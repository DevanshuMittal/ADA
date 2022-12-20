#include<stdio.h>
void main()
{
   int i,j;
   int arr1={2,2,1,1,2,1,2,1};
   int arr2={2,1,1,2,2,1,1,2,1};
   int len1=8;
   int len2=9;
   int arr[len1+1][len2+1];
   char dir[len1+1][len2+1];
   for(i=0;i<=len1;i++){
      for(j=0;j<=len2;j++){
         if(i==0 || j==0) {arr[i][j]=0;dir[i][j]='Z';}
         else{
            if(arr1[i-1]==arr2[i-1]){
               arr[i][j]=arr[i-1][j-1]+1;
               dir='D';
            }
            else{
               if(arr[i][j-1]>arr[i-1][j]){
                  arr[i][j]=arr[i][j-1];
                  dir[i][j]='L';
               }
               else{
                  arr[i][j]=arr[i-1][j];
                  dir[i][j]='U';
               }
            }
         }
      }
   }
   int a=len1;
   int b=len2;
   int length=arr[a][b];
   int answer[length];
   while(length>0){
      if(dir[a][b]=='D'){
         answer[arr[a][b]-length]=arr1[a-1];
         a--;
         b--;
         length--;
      }
      else if(dir[a][b]=='U') a--;
      else if(dir[a][b]=='L') b--;
      else break;
   }
   printf("%d",answer);
   for(i=0;i<=)
}