import socket
choice = 0
while choice!=3:
    print('Menu \n 1] DNS to IP \n 2] IP to DNS \n 3] Exit')
    choice = int(input('Enter choice(1|2|3): '))
    if choice == 1:
        URL=input('Enter URL: ')
        address = socket.gethostbyname(URL)
        print("IP is : ",address,"\n\n")
    elif choice == 2:
        IP=input('Enter IP Address: ')
        temp=socket.gethostbyaddr(IP)
        print("IP is : ",temp,"\n\n")
    elif choice == 3:
        print('Exiting...')
    else:
        print('Invalid input. Enter again.')