import random

print "Rolling the dice..."

dice = random.randint(1,6)
print dice

answer = raw_input("Would you like to roll again?\n")
if (answer == "yes"):
    dice = random.randint(1,6)
    print "Your new value is %d" % dice
else:
    print "yay!"