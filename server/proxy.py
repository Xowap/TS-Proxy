#!/usr/bin/python
# -*- coding: utf-8 -*-

##
# TSProxy ~ proxy.py
#
# By Rémy Sanchez <remy.sanchez@hyperthese.net>
# Under the terms of the WTFPL Licence, comes with
# no waranties at all.
##

from twisted.internet import protocol, reactor, defer
from twisted.protocols import basic
import fw

class TSProxy(basic.LineReceiver):
	"""Keeps a TS Forwarder alive as long as the client is connected"""

	fw = None
	port = None

	def lineReceived(self, line):
		if self.port == None:
			dest = line.split(':')

			# Fetch the local port
			given = self.factory.getPort(int(dest[0]))
			self.port = given

			# Create the TS Forwarder
			self.fw = reactor.listenUDP(given, fw.TSForwarder((dest[1], int(dest[2])), self.transport.getHost().host))

			# Reply with the port number
			self.transport.write(str(given) + "\r\n")

			# A little something for the logs
			print "%s asked for port %d, port %d given" % (self.transport.getHost().host, int(dest[0]), given)

	def connectionLost(self, reason):
		if self.fw != None:
			self.fw.stopListening()
			self.fw = None

		if self.port != None:
			self.factory.freePort(self.port)
			self.port = None

class TSProxyFactory(protocol.ServerFactory):
	"""A (basic) proxy for Teamspeak"""

	protocol = TSProxy
	inuse = []

	def getPort(self, pref):
		pref = ((pref - 42042) % 917) + 42042

		if pref in self.inuse:
			return self.getPort(pref + 1)
		else:
			self.inuse.append(pref)
			return pref

	def freePort(self, port):
		if port in self.inuse:
			self.inuse.remove(port)
