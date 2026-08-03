# Took server code from https://stackoverflow.com/questions/69162232/simple-two-way-socket-communication
# There's a problem where the code is hanging but luckily there's also a solution as well but I want to test it as it is for now
## implemented the fix that was suggested in the stackoverflow forum.

import socket
import time

HOST = "192.168.0.85"
PORT = 18736

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

    for i in range(len(data.decode())):
        if data.decode()[i] == '>':
            messageToSendBack = input("message to send back: ")
            conn.sendall(messageToSendBack.encode())
            s.close()
    

