'''
input all nodes and adjacency matrix
select starting node
traverse its adjacency list
if element is not in path list add it else not
'''
def remove_item(li,x):
   c=li.count(x)
   for i in range(c):
      li.remove(x)
   return li
def bfs(arr,num):
   start=int(input("Select start node: "))
   path=[]
   bfs_queue=[]
   bfs_queue.append(start)
   while(len(path)<num):
      head=bfs_queue[0]
      for x in arr[head]:
         bfs_queue.append(x)
      if head not in path:
         path.append(head)
      bfs_queue=remove_item(bfs_queue,head)
   return path       
if __name__=="__main__":
   '''
   num=int(input("Enter the number of nodes: "))
   arr=[[0]*(num+1) for i in range(num+1)]
   for i in range(num):
      for j in range(num):
         print("Enter element at ",i," ",j," : ")
         arr[i][j]=input()
   li=list(range(num))'''
   arr=[[1,3],[0,2],[1,3],[0,3]]
   arr=[[1,2],[2],[0,3],[3]]
   num=4
   path=bfs(arr,num)
   print(path)
   
   