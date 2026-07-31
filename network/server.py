# Took server code from https://stackoverflow.com/questions/69162232/simple-two-way-socket-communication
# There's a problem where the code is hanging but luckily there's also a solution as well but I want to test it as it is for now

import socket
import time

HOST = "127.0.0.1"
PORT = 18735

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST, PORT))
s.listen()
print(f"Listening on {HOST}:{PORT}")

conn, addr = s.accept()
print(f"Accepted connection from {HOST}:{PORT}")

cmd = ""
while True:
    data = conn.recv(2)
    time.sleep(1)
    if not data:
        break
    print(data.decode())
    # conn.sendall(b"OK")  This line fixes the problem!

conn.sendall(b"Finished")
s.close()
