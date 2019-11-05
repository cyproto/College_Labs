import socket
import sys

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

data = "Hello"
ip = '127.0.0.1'
port = 4300
sock.sendto(data.encode(), (ip, port))

while True:    	
	msg, (ip, port) = sock.recvfrom(100)

	if "exit" in msg.decode():
		print("\nYour friend has left the chat")
		break

	else:			
		print("Server: " + msg.decode())
	
	msg = input("You: ")
	sock.sendto(msg.encode(), (ip,port))

	if "exit" in msg:
		print("\nYou left the chat")
		break

sock.close()