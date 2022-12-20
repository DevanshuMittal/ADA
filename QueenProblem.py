n=int(input("Enter number of queens: "))
li=[]*n
def place(k,i):
    for j in range(1,k-1):
        if li[j]==i or abs(li[j]-i)==abs(j-k):
            return False
    return True
def nqueen(k,n):
    for i in range(1,n):
        if(place(k,i)):
            li[k]=i
            if k==n:
                print(li[1:n])
            else:
                nqueen(k+1,n)
nqueen(1,n)