from network import networkingLib

host = '192.168.0.85'
port = 13425

serverInst = networkingLib.server(host, port)
serverInst.bindAndListen()
serverInst.acceptConnection()
serverInst.listenForData()