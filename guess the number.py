import random

dice = random.randint(1,6)


answer = int (raw_input ("What do you think is the number?"))
while (answer != dice):
    if answer > dice:
        print ("That's a little high. Try again!\n")
    else:
        print ("That's a little low. Try again!\n")
    answer = int (raw_input ("What do you think is the number?"))

print ("That's correct! Good job. \n")

