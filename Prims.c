/*
Input adjacency matrix
choose src node
calculate the dist
mark the non connected vertices to be at INF
select min of vn, vn-1+edge
select min for this row
choose min as src for next iteration
*/


/*
input adjacency matrix
make separate grp of each vertex
select minimum element of matrix
grp the vertices
select  min if not in same grp

*/
#include <stdio.h>    
#include <limits.h>    
#define INF 99999
int minimum_key(int k[],int mst[],int vertices){  
    int minimum=INT_MAX,min,i;    
    for (i=0;i<vertices;i++)  
        if (mst[i]==0 && k[i]<minimum)   
            minimum=k[i],min=i;    
    return min;}    
int main(){
    int vertices,i,j;
    printf("Enter number of vertices: ");
    scanf("%d",&vertices);
    int arr[vertices][vertices];
    int parent[vertices];    
    int k[vertices];       
    int mst[vertices];      
    int count,edge,v; 
    printf("Enter adjacency matrix:\n");
    for(i=0;i<vertices;i++){
        for(j=0;j<vertices;j++){
            if(i==j)continue;
            printf("Enter edge between %d and %d: ",i+1,j+1);
            scanf("%d",&arr[i][j]);}}
        //for(j=0;j<i;j++)arr[i][j]=INF;
    for(i=0;i<vertices;i++){  
        k[i]=INT_MAX;  
        mst[i]=0;}  
    k[0]=0; 
    parent[0]=-1;
    for(count=0;count<vertices-1;count++){    
        edge=minimum_key(k,mst,vertices);    
        mst[edge]=1;    
        for(v=0;v<vertices;v++)      
            if(arr[edge][v] && mst[v]==0 && arr[edge][v]<k[v])    
                parent[v]=edge,k[v]=arr[edge][v];}    
    printf(" Edge \t  Weight\n");  
    for (i=1;i<vertices;i++)    
    printf(" %d <-> %d    %d \n",parent[i],i,arr[i][parent[i]]); 
    return 0;}