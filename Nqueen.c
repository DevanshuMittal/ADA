#include<stdio.h>
#include<math.h>
int place(int row,int col){
    for(i=1;i<row;i++){
        if(board[i]==col) return 0;
        else if(abs(board[i]-col)==abs(i-row))return 0;
    }
    return 1;
}
int queen(int row,int n){
    int col;
    for(col=1;col<=n;col++){
        if(place(row,col)){
            board[row]=col;
            if(row==n)printf(n);
            else queen(row+1,n);
        }
    }
}
int main(){
    int n,i,j;
    printf("Enter number of queens: ");
    scanf("%d",&n);
    return 0;
}