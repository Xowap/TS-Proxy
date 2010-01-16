#!/usr/bin/python
# -*- coding: utf-8 -*-

##
# TSProxy ~ fw.py
#
# By Rémy Sanchez <remy.sanchez@hyperthese.net>
# Under the terms of the WTFPL Licence, comes with
# no waranties at all.
##

import socket
from twisted.internet.protocol import DatagramProtocol
from twisted.internet import reactor

class UDPForwarder(DatagramProtocol):
	"""Made to forward incoming UDP packets from a specific host to another host/port"""

	def __init__(self, (host_to, port_to), host_from):
		"""Forwards all UDP packets coming on from_port to host:port"""

		self.host_to = socket.gethostbyname(host_to)
		self.port_to = port_to

		self.host_from = socket.gethostbyname(host_from)
		self.port_from = None

		print "Now forwarding packets from %s to %s on port %d" % (self.host_from, self.host_to, self.port_to)

	def datagramReceived(self, data, (host, port)):
		"""If a valid packet comes in, it is forwarded to the other end"""

		if self.checkData(data):
			if self.host_from == host:
				if(self.port_from != port):
					self.port_from = port
				self.transport.write(data, (self.host_to, self.port_to))
			elif (self.host_to == host) and (self.port_from != None):
				self.transport.write(data, (self.host_from, self.port_from))

	def checkData(self, data):
		"""Validates a packet. Intented to be overloaded with heritage, not useful here, because it always returns True"""

		return True

class TSForwarder(UDPForwarder):
	"""Forwards Teamspeak packets"""

	cnt = {}

	def checkData(self, data):
		"""Checks if the packet begins with a valid teamspeak class"""

		if len(data) < 4:
			return False
		elif ord(data[1]) == 0xbe and ord(data[0]) >= 0xf0 and ord(data[0]) <= 0xf4:
			# It's TS2 :)
			return True
		else:
			# It's TS3 :'(
			if len(data) < 12:
				return False

			# Note : this part is purely speculative and
			# might actualy not work at all in some cases...
			# May TeamSpeak and its closed protocol go to hell !

			pclass = data[10:11]
			pcnt = ord(data[8]) << 8 + ord(data[9])

			if self.cnt.has_key(pclass) == False:
				self.cnt[pclass] = pcnt
				return True
			elif pcnt >= self.cnt[pclass] or (pcnt < 10 and self.cnt[pclass] > 0xfff0):
				self.cnt[pclass] = pcnt
				return True
			else:
				return False
