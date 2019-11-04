frameSize = int(input("Enter frame size: "))
frame = list()
print("Enter bits: ")
for i in range(frameSize):
    a = input()
    frame.append(int(a))

keySize = int(input("Enter key size: "))
key = list()
print("Enter bits: ")
for i in range(keySize):
    b = input()
    key.append(int(b))
print("--------------------------")
print("Sender's side: ")
print("--------------------------")
print("Frame:", frame)
print("Key:", key)

for i in range(frameSize, frameSize + keySize - 1):
    frame.append(0)

print("Frame after appending zeros: ",frame)

temp = list(frame)

for i in range(frameSize):
    k = i
    j = 0
    if temp[k] >= key[j]:
        for j, k in zip(range(keySize), range(i, 1000)):
            if (temp[k] == 1 and key[j] == 1) or (temp[k] == 0 and key[j] == 0):
                temp[k] = 0
            else:
                temp[k] = 1

crc = []
for i, j in zip(range(keySize-1), range(frameSize, 1000)):
    crc.append(temp[j])

print("CRC: ", crc)
transmittedFrame = []
for i in range(frameSize):
    transmittedFrame.append(frame[i])

for i in range(keySize-1):
    transmittedFrame.append(crc[i])

print("Transmitted frame: ", transmittedFrame)
print("--------------------------")
print()
print("--------------------------")
print("Receiver's side: ")
print("--------------------------")
print("Received frame: ", transmittedFrame)

temp = transmittedFrame.copy()

for i in range(frameSize):
    k = i
    j = 0
    if temp[k] >= key[j]:
        for j, k in zip(range(keySize), range(i, 1000)):
            if (temp[k] == 1 and key[j] == 1) or (temp[k] == 0 and key[j] == 0):
                temp[k] = 0
            else:
                temp[k] = 1


remainder = []

for i in range(frameSize, frameSize + keySize-1):
    remainder.append(temp[i])

print("Remainder: ", remainder)

if 1 in remainder:
    print("Error! As remainder is not zero, there's something wrong with the received frame.")
else:
    print("Success! As remainder is zero, the received frame is correct.")
print("--------------------------")







