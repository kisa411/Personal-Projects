#make a map/dictionary of the given values (number, count)
#return the keys of the map

from collections import OrderedDict

def unique( dataList=[] ):
	uniqueDict=OrderedDict() #make a dictionary to contain the unique keys
	for value in dataList:
		if value in uniqueDict:
			uniqueDict[value]+=1
		else:
			uniqueDict[value]=1
	for key in uniqueDict.iterkeys(): #print the keys, which are the unique digits in the list
		print("%2d" %key)



numbers=[1,3,2,2,5,6,5,1,1,3]
unique(numbers)


