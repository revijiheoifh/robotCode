# Took server code from https://stackoverflow.com/questions/69162232/simple-two-way-socket-communication
# There's a problem where the code is hanging but luckily there's also a solution as well but I want to test it as it is for now
## implemented the fix that was suggested in the stackoverflow forum.

import socket
import time

class server:
    def __init__(self, host, port, sock=None, conn=None, addr=None):
        self.host = host
        self.port = port
        self.sock = sock
        self.conn = conn
        self.addr = addr

    def bindAndListen(self):
        self.sock=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.bind((self.host, self.port))
        self.sock.listen()
        print(f"Listening on {self.host}:{self.port}")

    def acceptConnection(self):
        self.conn, self.addr = self.sock.accept()
        print(f"Accepted connection from {self.host}:{self.port}")

    def listenForData(self):
        while True:
            data=self.conn.recv(1024)
            time.sleep(1)
            if not data:
                break
            print(data.decode())

            for i in range(len(data.decode())):
                if data.decode()[i] == '>':
                    sendMessageBack = input("Message to send back: ")
                    self.conn.sendall(sendMessageBack.encode())
                    self.sock.close()

if __name__ == "__main__":
    serverInst = server('192.168.0.85', 18736)
    serverInst.bindAndListen()
    serverInst.acceptConnection()
    serverInst.listenForData()
