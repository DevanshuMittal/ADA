import time
import matplotlib.pyplot as plt
def binary_search(num,arr,low,high):
   if low<=high:
      mid=(low+high)//2
      print("Low = ",low,"\tMid = ",mid,"\tHigh = ",high,"\tElement = ",arr[mid])
      if num<arr[mid]:
         binary_search(num,arr,low,mid-1)
      elif num>arr[mid]:
         binary_search(num,arr,mid+1,high)
      else:
         print("Index = ",mid)
         return mid
   else:
      print("Not Found")
      return
if __name__=='__main__':
   arr=list(range(100))
   arr.sort()
   print(arr)
   low=0
   high=len(arr)-1
   search_time=list()
   for x in arr:
      print("Iteration ",x)
      start=time.time()
      binary_search(x,arr,low,high)
      end=time.time()
      print("Time = ",end-start)
      search_time.append(end-start)
   plt.plot(search_time,marker='^')
   plt.show()
      
   
   