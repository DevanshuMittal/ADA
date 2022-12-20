/*
    1   2   3   4
1   0   10  15  20
2   10  0   35  25
3   15  35  0   30
4   20  25  30  0

    A   B   C   D   E
A   0   2   0   12  5
B   2   0   4   8   0
C   0   4   0   3   3
D   12  8   3   0   10
E   5   0   3   10  0

make 2d matrix of order n-1,n-2,n-3....1


array of order n
no. of elements of multiplication of 2 
(n-1)!

2,3
2,4
3,2
3,4
4,2
4,3

3
(n-2)!

order 5
4!  3!  2!  1!
24  6   2   1
2 to 1 via 
*/
#include<stdio.h>
#define INF 99999
void tsp(int n,int arr[n][n]){

}
int main(){
    int n,i,j,k;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    int arr[n][n];
    //inputting matrix
    printf("\nEnter adjacency matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j) continue;
            printf("Enter weight from %d to %d: ",i+1,j+1);
            scanf("%d",&arr[i][j]);}}
    //Preprocessing of the matrix
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j) arr[i][j]=0;
            else if(arr[i][j]==0) arr[i][j]=INF;}}
    printf("Adjacency Matrix:\n");
    printarray(n,arr);
    return 0;
}