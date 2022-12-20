#include<stdio.h>
int max(int a,int b){
    if(a>b) return a;
    else return b;}
int main(){
    int len,max_wt,i,j,k;
    printf("Enter the number of products: ");
    scanf("%d",&len);
    int wt[len];
    int pt[len];
    printf("Enter the details of products:\n");
    for(i=0;i<len;i++){
        printf("Enter the weight: ");
        scanf("%d",&wt[i]);
        printf("Enter the profit: ");
        scanf("%d",&pt[i]);}
    printf("Description of all the products:\n");
    printf("Weight\tProfit\n");
    for(i=0;i<len;i++)
        printf("%d\t%d\n",wt[i],pt[i]);
    printf("Enter the capacity of bag: ");
    scanf("%d",&max_wt);
    int a[len+1][max_wt+1];
    printf("Table for filling the bag:\n");
    for(i=0;i<=len;i++){
        for(j=0;j<=max_wt;j++){
            if(i==0 || j==0)
                a[i][j]=0;
            else    
            {   if(wt[i-1]>j) a[i][j]=a[i-1][j];
                else a[i][j]=max(pt[i-1]+a[i-1][j-wt[i-1]],a[i-1][j]);}
            printf("%d\t",a[i][j]);}
        printf("\n");}
    int weight=max_wt;
    int length=len;
    int profit=0;
    int max_pt=a[len][max_wt];
    printf("Items chosen:\n");
    while(profit<max_pt){
        if(a[length][weight]!=a[length-1][weight]){
            profit+=pt[length-1];
            printf("Item: I%d\tProfit: %d\tWeight: %d\n",length,pt[length-1],wt[length-1]);
            weight-=wt[length-1];}
        --length;}
    printf("Maximum profit: %d\n",max_pt);
    return 0;}