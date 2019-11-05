import socket
import sys
conn = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server = '127.0.0.1'
port = 4200
conn.connect((server,port))
data = input("You: ")
conn.sendto(data.encode(),(server,port))
while True:
	data = conn.recv(16)
	if "exit" in data.decode():
		print("\nYour friend has left the chat")
		break
	else:
		print("Server: " + data.decode())
	data = input("You: ")
	conn.sendto(data.encode(),(server,port))
	if "exit" in data:
		print("\nYou left the chat")
		break
conn.close()