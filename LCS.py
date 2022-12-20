def maximum(a,b):
    if a[0]>b[0]:
        return a[0],'L'
    else:
        return b[0],'U'
#str1=str(input("Enter first string: "))
#str2=str(input("Enter second string: "))
str1='abaaba'
str2='babbab'
len1=len(str1)+1
len2=len(str2)+1
arr=[[[]]*len2]*len1
dir=[[[]]*len2]*len1
for i in range(0,len1):
    for j in range(0,len2):
        if i==0 or j==0:
            arr[i][j]=0
            dir[i][j]='Z'
        else:
            if str1[i-1]==str2[j-1]:
                arr[i][j]=arr[i-1][j-1]+1
                dir[i][j]='D'
            else:
                if arr[i][j-1]>arr[i-1][j]:
                    arr[i][j],dir[i][j]=arr[i][j-1],'L'
                else:
                    arr[i][j],dir[i][j]=arr[i-1][j],'U'
                #arr[i][j][0],arr[i][j][1]=maximum(arr[i][j-1],arr[i-1][j])
#print(arr)  
#print(dir)
for i in range(0,len1):
    print(arr[i])
    print(dir[i])
        