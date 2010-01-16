# -*- coding: utf-8 -*-

##
# TSProxy ~ tsproxy_plugin.py
#
# By Rémy Sanchez <remy.sanchez@hyperthese.net>
# Under the terms of the WTFPL Licence, comes with
# no waranties at all.
##

from zope.interface import implements

from twisted.python import usage
from twisted.plugin import IPlugin
from twisted.application.service import IServiceMaker
from twisted.application import internet

from tsproxy import TSProxyFactory

class Options(usage.Options):
	optParameters = [
		["base-port", "b", 42042, "The base port number used for forwarding"],
		["fw-num", "f", 4242, "Forward up to fw-num connections"],
		["port", "p", 7412, "Port on witch the proxy will listen for incoming connections from TSClient"]
	]

class MyServiceMaker(object):
	implements(IServiceMaker, IPlugin)
	tapname = "tsproxy"
	description = "TS Proxy is a TeamSpeak 2 & 3 proxy, for sysadmins frustrated with the non-standard port of TeamSpeak"
	options = Options

	def makeService(self, options):
		"""
		Construct a TCPServer from the factory of TSProxy
		"""

		return internet.TCPServer(int(options["port"]), TSProxyFactory())

serviceMaker = MyServiceMaker()
