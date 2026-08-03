# Source - https://stackoverflow.com/q/69162232

# Posted by torayeff, modified by community. See post 'Timeline' for change history

# Retrieved 2026-07-31, License - CC BY-SA 4.0

import socket
import server

clientInst = server.client('192.168.0.85', 18736)
clientInst.connectToServer()
clientInst.sendMessage()
clientInst.showResultAndClose()