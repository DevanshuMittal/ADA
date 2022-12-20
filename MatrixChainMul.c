#include<stdio.h>
#define INF 9999999
void printarray(int n,int arr[n][n]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++)printf("-\t");
        for(j=i+1;j<n;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
}
void parenthesis(int i,int j,int n,int dir[n][n]){
    if(i==j) printf("A%d",i+1);
    else{
        printf("(");
        parenthesis(i,dir[i][j]-1,n,dir);
        parenthesis(dir[i][j],j,n,dir);
        printf(")");
    }
}
void matrixmul(int n,int li[n]){
    int x,y,i,j,k;
    int arr[n][n];
    int dir[n][n];
    for(x=0;x<n;x++){
        for(y=0;y<n-x;y++){
            i=y;
            j=y+x;
            if(i==j) arr[i][j]=0;
            else{
                int val;
                arr[i][j]=INF;
                for(k=i;k<j;k++){
                    val=arr[i][k]+arr[k+1][j]+li[i]*li[k+1]*li[j+1];
                    if(val<arr[i][j]){arr[i][j]=val;dir[i][j]=k+1;}
                }
            }
        }
    }
    printf("Minimum Cost Array:\n");
    printarray(n,arr);
    printf("Direction array:\n");
    printarray(n,dir);
    printf("Order of multiplication:\n");
    parenthesis(0,n-1,n,dir);
}
int main(){
    int n=6;
    printf("Enter number of matrices: ");
    scanf("%d",&n);
    int li[n];
    for(int i=0;i<n;i++){
        printf("Enter ");
    }
    //int li[7]={30,35,15,5,10,20,25};
    matrixmul(n,li);
    return 0;
}