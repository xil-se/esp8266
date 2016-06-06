#!/usr/bin/env python2

import socket
import sys
import time

# Add timestamp and proxy data to carbon


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
s.bind(('0.0.0.0', 1234))
s.listen(1)
while 1:
    conn, addr = s.accept()
    print "got client"
    data = conn.recv(1024)
    print data
    handle(data)
    conn.close()
    print "done"

print "killed"

