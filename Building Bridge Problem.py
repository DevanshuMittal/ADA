def inputhouse(arr,n):
    for i in range(n):
        x=input("Enter house: ")
        arr.append(x)
def bridgebuilding(str1,str2):
    len1=len(str1)
    len2=len(str2)
    arr=[[0]*(len2+1) for i in range(len1+1)]
    dir=[['Z']*(len2+1) for i in range(len1+1)]
    for i in range(0,len1+1):
        for j in range(0,len2+1):
            if i==0 or j==0:
                arr[i][j]=0
            else:
                if str1[i-1]==str2[j-1]:
                    arr[i][j]=arr[i-1][j-1]+1
                    dir[i][j]='D'
                else:
                    if arr[i][j-1]>arr[i-1][j]:
                        arr[i][j]=arr[i][j-1]
                        dir[i][j]='L'
                    else:
                        arr[i][j]=arr[i-1][j]
                        dir[i][j]='U'
    return arr,dir
def bridges(str1,str2):
    arr,dir=bridgebuilding(str1,str2)
    a=len(str1);
    b=len(str2);
    length=arr[a][b]
    answer=list()
    while length>0:
        if dir[a][b]=='D':
            answer.append(str1[a-1])
            a-=1
            b-=1
            length-=1
        elif dir[a][b]=='U':
            a-=1
        elif dir[a][b]=='L':
            b-=1
        else:
            break
    answer.reverse()
    print(answer)
    print("Table for length:")
    for i in range(0,len(str1)+1):
        for j in range(0,len(str2)+1):
            if dir[i][j]=='D':
                print("\033[1;31m",arr[i][j],end='   ')
            elif dir[i][j]=='U':
                print("\033[2;32m",arr[i][j],end='   ')
            elif dir[i][j]=='L':
                print("\033[0;33m",arr[i][j],end='   ')
            elif dir[i][j]=='Z':
                print("\033[1;30m",arr[i][j],end='   ')
            else:
                print(arr[i][j],end='   ')
        print(" ")
    print("\033[0m")
    print("Table for directions:")
    for i in range(0,len(str1)+1):
        for j in range(0,len(str2)+1):
            if dir[i][j]=='D':
                print("\033[1;31m",dir[i][j],end='   ')
            elif dir[i][j]=='U':
                print("\033[2;32m",dir[i][j],end='   ')
            elif dir[i][j]=='L':
                print("\033[0;33m",dir[i][j],end='   ')
            elif dir[i][j]=='Z':
                print("\033[1;30m",dir[i][j],end='   ')
            else:
                print(arr[i][j],end='   ')
            #print(arr[i][j],end='   ')
        print("\033[0m"," ")
    return answer
if __name__=="__main__":
        
        #arr1=[2,2,1,1,2,1,2,1]
        #arr2=[2,1,1,2,2,1,1,2,1]
        #arr1='EXPONENTIAL'
        #arr2='POLYNOMIAL'
    
    
    a=int(input("Enter number of houses on north bank: "))
    b=int(input("Enter number of houses on south bank: "))
    arr1=[]
    arr2=[]
    print("North Bank:")
    inputhouse(arr1,a)
    print("South Bank:")
    inputhouse(arr2,b)
    answer=bridges(arr1,arr2)
    print("Houses with bridges:")
    for x in answer:
        print(x)