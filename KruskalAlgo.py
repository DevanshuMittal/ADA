'''
input the edges
Select minimum edge
merge the sets
'''   
len=int(input("Enter the number of vertices: "))
arr=[[0]*len]*len
for i in range(len):
    for j in range(len):
        arr[i][j]=int(input("Enter the edge between {} and {}".format(i+1,j+1)))
li_of_li=[[]]
minimum=min([min(r) for r in arr])
min_val=arr.index(minimum)

print(arr)



