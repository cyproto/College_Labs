import linecache
import random

random = random.randrange(600)
word = linecache.getline("words.txt",random).rstrip()

print("Guess the characters: \n")

guess = ''
turns = len(word)+5

while turns > 0:
    failed = 0

    for char in word:
        if char in guess:
            print(char,end="")

        else:
            print("_", end=" ")
            failed = failed + 1

    if failed == 0:
        print("\n\n**************************")
        print("Won")
        print("**************************")
        print("Word is: ",word)
        print("**************************")
        break

    temp = input("\n\nGuess a character: ")
    guess = guess + temp

    if temp not in word:
        turns = turns - 1
        print("Wrong")

        print("Turns left", turns)

        if turns == 0:
            print("\n\nYou lose")
            print("The word was: ",word)