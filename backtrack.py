def appendAtBeginningFront(x,L):
    return [x+ element for element in L]
def bitStrings(n):
    #if n==0:return[]
    if n==1: return["0","3"]
    else:
        return(appendAtBeginningFront("2",bitStrings(n-1))+appendAtBeginningFront("1",bitStrings(n-1)))
print(bitStrings(5))
#print(['0','1'])

'''bitstr 4
 0,bitstr3 + 1,bitstr3
 bitrstr 3
  0,bitstr2 + 1,bitstr2
  bitstr 2
   0,bitstr1 + 1,bitstr1
   bitstr 1
    0 , 1
'''   
'''
def rangeToList(k):
    result=[]
    for i in range(0,k):
        result.append(str(i))
    return result
def baseKStrings(n,k):
    if n==0: return[]
    if n==1: return rangeToList(k)
    return[digit+bitstring for digit in baseKStrings(1,k)
           for bitstring in baseKStrings(n-1,k)]
print (baseKStrings(4,3))
'''