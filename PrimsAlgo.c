#include<stdio.h>
int min(int arr[],int len){
    int minimum=0,i;
    for(i=0;i<len;i++){
        if(arr[i]<arr[minimum])
            minimum=i;
    }
    return minimum;
}
int main(){
    int i,j,len;
    printf("Enter the number of vertices: ");
    scanf("%d",&len);
    int arr[len][len];
    for(i=0;i<len;i++){
        for(j=0;j<len;j++){
            if(i<j){
                printf("Enter edge weight %d to %d",i,j);
                scanf("%d",&arr[i][j]);
            }
            else if(i==j)arr[i][j]=999999;
            else arr[i][j]=arr[j][i];
        }
    }

    return 0;
}
/*
input adjacency matrix
select a src
get dist of all from src
print src
select min
calculate dist from min
print min
select min
*/