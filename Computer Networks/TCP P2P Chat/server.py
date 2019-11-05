import socket

conn = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server = '127.0.0.1'
port = 4200
conn.bind((server,port))
conn.listen(1)
interface, (ip,port) = conn.accept()
while True:
	data = interface.recv(16)
	if "exit" in data.decode():
		print("\nYour friend has left the chat")
		break
	else:
		print("Client: " + data.decode())
	data = input("You: ")
	interface.sendto(data.encode(),(server,port))
	if "exit" in data:
		print("\nYou left the chat")
		break
conn.close()