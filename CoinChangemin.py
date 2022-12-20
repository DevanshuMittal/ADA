def min(a,b):
   if a<b:
      return a
   else:
      return b
def red():
   print("\033[1;31m",end=''),
def yellow():
   print("\033[1;33m",end=''),
def blue():
   print("\033[0;33m",end=''),
def cyan():
   print("\033[0;36m",end=''),
def reset():
   print("\033[0m",end=''),
INF=999999
if __name__=="__main__":
   n=int(input("Enter number of coins: "))
   coins=list()
   for i in range(n):
      x=int(input("Enter denomination: "))
      coins.append(x)
   amt=int(input("Enter the total amount: "))
   arr=[[0]*(amt+1) for i in range(n+1)]
   print("Minimum Coin Change Problem: ")
   for i in range(n+1):
      for j in range(amt+1):
         if i==0:
            arr[i][j]=INF
         elif j==0:
            arr[i][j]=0
         else:
            if j<coins[i-1]:
               arr[i][j]=arr[i-1][j]
               blue()
            else:
               arr[i][j]=min(arr[i-1][j],arr[i][j-coins[i-1]]+1)
               cyan()
         if arr[i][j]==INF:
            print("INF","\t",end=''),
         else:
            print(arr[i][j],"\t",end=''),
         reset()
      print(" ")
   coin_num=arr[n][amt]
   a,b=n,amt
   print("Coin\tAmount left")
   while coin_num>0:
      if arr[a][b]!=arr[a-1][b]:
         b-=coins[a-1]
         print(coins[a-1],"\t",b)
         coin_num-=1
      else:
         a-=1
         