def remove_item(li,x):
   c=li.count(x)
   for i in range(c):
      li.remove(x)
   return li
'''
input adjacency matrix

set all vertices as white(0)
select starting node
set to grey(1)

arr=
0->[1,3]
1->[0,2]
2->[1,3]
3->[0,3]

   0  1  2  3
0  0  1  0  1
1  1  0  1  0
2  0  1  0  1
3  1  0  0  1

0-1-2
'''
def dfs(arr,num):
   start=int(input("Select start node: "))
   path=[]
   dfs_stack=[]
   dfs_stack.append(start)
   while(len(path)<num):
      head=dfs_stack[0]
      for x in arr[head]:
         