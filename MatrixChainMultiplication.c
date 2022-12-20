#include<stdio.h>
#define INF 9999999/*
void printarray(int arr[],int len){
    for(int i=0;i<len;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
}*/
int main(){
    int num;
    printf("Enter the number of matrix: ");
    scanf("%d",&num);
    for(i=0;i<num;i++){
        printf("Matrix %d:\n",i+1);
        printf("Enter number of rows: ");
        scanf("%d",&row[i]);
        printf("Enter number of columns: ");
        scanf("%d",&col[i]);
    }
    int n=num+1;
    int li[n];
    for(i=1;i<num;i++){
        if(row[i]!=col[i-1])exit(0);
        else li[i]=i;
    }
    
    return 0;
}