from network import networkingLib
from tts import textToSpeech

host = '192.168.0.85'
port = 13425

clientInst = networkingLib.client(host, port)

clientInst.connectToServer()

while clientInst.messageToSend != '>':
    clientInst.sendMessageShowResult()
    textToSpeech.tts(clientInst.receivedMessage)

clientInst.closeSocket()