/*
input adjacency matrix
dist0 as arr
dist1 as dist0 and min condition
arr[i,j]=min(arr[i][j],arr[i][k]+arr[k][j])
arr[4,4]
k=0 
karr0=arr
k=1
karr1=min val in karr0
*/

#include<stdio.h>
#define INF 9999
int min(int a,int b){
    if(a<b) return a;
    else return b;}
void printdir(int n,int arr[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==-1)printf("N\t");
            else printf("%c\t",(char)arr[i][j]+64);
        }printf("\n");}}
void printarray(int n,int arr[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)printf("0\t");
            else if(arr[i][j]<INF-1000)printf("%d\t",arr[i][j]);
            else printf("INF\t");}
        printf("\n");}
    printf("\n");}
void floydwarshall(int n,int k,int arr[n][n],int dir[n][n]){
    if(k<n)
    {
        int k_arr[n][n];
        int i,j;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i!=j){
                    if(arr[i][k]+arr[k][j]>=arr[i][j]) k_arr[i][j]=arr[i][j];
                    else{
                        k_arr[i][j]=arr[i][k]+arr[k][j];
                        dir[i][j]=k+1;}}
                else continue;}}
        printf("\nWeight of paths:\n");
        printarray(n,k_arr);
        printf("Parent Vertex:\n");
        printdir(n,dir);
        floydwarshall(n,k+1,k_arr,dir);}}
int main(){
    int n,i,j,k;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    int arr[n][n];
    int dir[n][n];
    printf("\nEnter adjacency matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            dir[i][j]=-1;
            if(i==j) continue;
            printf("Enter weight from %d to %d: ",i+1,j+1);
            scanf("%d",&arr[i][j]);}}
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j) arr[i][j]=0;
            else if(arr[i][j]==0) arr[i][j]=INF;
            if(arr[i][j]<INF && i!=j) dir[i][j]=i+1;}}
    printf("D 0\n");
    printarray(n,arr);
    printf("P 0\n");
    printdir(n,dir);
    //int arr[][4]={{0,3,6,15},{INF,0,-2,INF},{INF,INF,0,2},{1,INF,INF,0}};   
    floydwarshall(n,0,arr,dir); 
    return 0;}