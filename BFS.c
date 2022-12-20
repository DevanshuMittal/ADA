/*
Select start node
if element not in path
traverse all element in its adjacency list

*/
#include<stdio.h>
void main()
{
   int num,i,j,start;
   printf("Enter number of nodes: ");
   int arr[num][num];
   for(i=0;i<num;i++){
      for(j=0;j<num;j++){
         scanf("%d",&arr[i][j]);
      }
   }
   printf("Enter starting node: ");
   scanf("%d",&start);
   
}