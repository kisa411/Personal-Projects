

for number in range(1,101):
	if (number%3==0 and number%5==0):
		print 'CallBox'
	elif (number%5==0): #is a multiple of five
		print 'Box'
	elif (number%3==0): #is a multiple of three
		print 'Call'
	else:
		print number
