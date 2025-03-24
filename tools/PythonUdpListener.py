#!/usr/bin/python
'''
    UDP message listener
    By David McDonald
'''

import socket	#for sockets

HOST = "0.0.0.0" # Default 0.0.0.0 for messages on any network interface
PORT = 12345

# Open the socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
addr = (HOST, PORT)
sock.bind(addr)
print("Listening on {}:{}".format(HOST, PORT))

while True:
    payload, client_address = sock.recvfrom(1024)
    print(payload.decode("ascii"))