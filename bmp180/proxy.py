#!/usr/bin/env python2

import os, signal
import socket
import sys
import time

def handle(d):
	d = d.strip()
	if len(d) == 0: return
	unixtime = str(int(time.time()))
	dd = d.split('\n')
	dd = [(x + ' ' + unixtime) for x in dd]
	d = '\n'.join(dd)
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.connect(('localhost', 2003))
	s.sendall(d + '\n')
	print d

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
s.bind(('0.0.0.0', 1234))
s.listen(1)

signal.signal(signal.SIGCHLD, signal.SIG_IGN)

while 1:
	print "waiting for connection..."
	conn, addr = s.accept()
	newpid = os.fork()
	if newpid == 0:
		print "fork()"
		# kill the fork after 1 second
		signal.alarm(1)
		data = conn.recv(1024)
		handle(data)
		conn.close()
		print "fork: time to die"
		os._exit(0)
		print "fork: wtf?"

print "killed"

