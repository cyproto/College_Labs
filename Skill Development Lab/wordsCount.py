file = input("Enter file name: ")

words = 0

try:
    with open(file,'r') as temp:
        for line in temp:
            w = line.split()
            words = words + len(w)

    print("Number of words:")
    print(words)

except:
    print("No file found named: ",file)