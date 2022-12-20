/*
if j<i
arr[i][j]=arr[i-1][j]
j=i
arr[i][j]=1
j>i
arr[i][j]=min(coins[i])
    0   1   2   3   4   5   6   7   8   9   10
0   0   0   0   0   0   0   0   0   0   0   0
1   0   1   2   3   4   5   6   7   8   9   10
2   0   1   1   2   2   3   3   4   4   5   5
5   0   1   1   2   2   1   2   2   3   3   2
8   0   1   1   2   2   1   2   2   1   2   2
9   0   1   1   2   2   1   2   2   1   1   2
*/
#include<stdio.h>
#define INF 99999
int min(int a,int b)
{
    if(a<b) return a;
    else return b;
}
void red(){printf("\033[1;31m");}
void yellow(){printf("\033[1;33m");}
void blue(){printf("\033[0;33m");}
void cyan(){printf("\033[0;36m");}
void reset(){printf("\033[0m");}
int main(){
    int i,j,n,amt;
    printf("Enter number of coins: ");
    scanf("%d",&n);
    int coins[n+1];
    coins[0]=0;
    for(i=1;i<=n;i++){
        printf("Enter %d denomination: ",i);
        scanf("%d",&coins[i]);
    }
    printf("Enter the total amount: ");
    scanf("%d",&amt);
    int arr[n+1][amt+1];
    printf("\n\nDynamic Programming tabular representation for Minimum coin problem:\n"); 
    red();
    for(i=0;i<=amt;i++)printf("\t%d",i);
    reset();
    printf("\n");
    for(i=0;i<=n;i++){
        red();
        printf("%d\t",coins[i]);
        reset();
        for(j=0;j<=amt;j++){
            if(i==0)arr[i][j]=INF;
            else if(j==0)arr[i][j]=0;
            else{
                if(j<coins[i]){arr[i][j]=arr[i-1][j];blue();}
                else {arr[i][j]=min(arr[i-1][j],arr[i][j-coins[i]]+1);cyan();}
            }
            if(arr[i][j]==INF)printf("INF\t");
            else printf("%d\t",arr[i][j]);
            reset();
        }
        printf("\n");
    }
    int coin_num=arr[n][amt];
    int a=n;
    int b=amt;
    printf("\nMinimum number of coins required: %d\n",coin_num);
    printf("Denomination\tAmount Left\n");
    while(coin_num>0){
        if(arr[a][b]!=arr[a-1][b]){
            b-=coins[a];
            printf("%d\t\t%d\n",coins[a],b);
            --coin_num;
        }
        else --a;
    }
    return 0;
}