#!/usr/bin/python
# -*- coding: utf-8 -*-

##
# TSProxy ~ tsproxy.tac
#
# By Rémy Sanchez <remy.sanchez@hyperthese.net>
# Under the terms of the WTFPL Licence, comes with
# no waranties at all.
##

import tsproxy

from twisted.application import internet, service

f = tsproxy.TSProxyFactory()

application = service.Application('tsproxy')
serviceCollection = service.IServiceCollection(application)
internet.TCPServer(7412, f).setServiceParent(serviceCollection)
