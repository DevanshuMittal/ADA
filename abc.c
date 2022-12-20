#include<stdio.h>
void printarray(int n,int arr[n][n]){
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
}
void matrixmul(int n, int li[])
{
    int x,y,k;
    int arr[n][n];
    for(x=0;x<n;x++)
    {
        for(y=0;y<n-x;y++)
        {
            int i=y;
            int j=y+x;
            if(i==j) arr[i][j]=0;
            else
            {
                int val;
                arr[i][j]=99999999;
                for(k=i;k<j;k++)
                {
                    val=arr[i][k]+arr[k+1][j]+li[i-1]*li[k]*li[j];
                    if(val<arr[i][j])
                        arr[i][j]=val;
                }
            }
            printf("%d %d",i,j);
        }
    }
    printarray(n,arr);
}
void main(){
    int i,j,k,n=5;
    int li[n];
    printf("Enter dimensions of matrices:\n");
    for(i=0;i<n;i++){
        printf("Enter %d element: ",i+1);
        scanf("%d",&li[i]);
    }
    matrixmul(n,li);
}