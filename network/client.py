# Source - https://stackoverflow.com/q/69162232

# Posted by torayeff, modified by community. See post 'Timeline' for change history

# Retrieved 2026-07-31, License - CC BY-SA 4.0

import socket

HOST = "192.168.0.59"
PORT = 18736

# create socket and connect
cs = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
cs.connect((HOST, PORT))

# send data
cs.sendall(b"123456>")

# wait for a result
data = cs.recv(1024)
print("result: ", data)
cs.close()
