import socket
import sys

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
ip = '127.0.0.1'
port = 4300
sock.bind((ip, port))

msg, (ip, port) = sock.recvfrom(100)
print("Client connected to IP: " + ip + " and port: " + str(port))
print("Received message: " + msg.decode())

data = "Hi"
sock.sendto(data.encode(), (ip,port))

while True:    	
	msg, (ip, port) = sock.recvfrom(100)
	print("Client connected to IP: " + ip + " and port: " + str(port))

	if "exit" in msg.decode():
		print("\nYour friend has left the chat")
		break
	else:
		print("Friend: " + msg.decode())
	
	msg = input("You: ")
	sock.sendto(msg.encode(), (ip,port))
	if "exit" in msg:
		print("\nYou left the chat")
		break
sock.close()