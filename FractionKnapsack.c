/*
input the weight and profit
calculate ratio
select min
check min<required
wt_req decreased profit increased
otherwise 
profit=profit*weightreq/weight
*/
#include<stdio.h>
int main(){
    int i,j,len;
    float max_wt;
    float profit=0.0;
    printf("Enter number of items: ");
    scanf("%d",&len);
    float wt[len],pt[len];
    float rt[len];
    for(i=0;i<len;i++){
        printf("Enter the weight of item %d: ",i+1);
        scanf("%f",&wt[i]);
        printf("Enter the profit of item %d: ",i+1);
        scanf("%f",&pt[i]);
        rt[i]=pt[i]/wt[i];
    }
    printf("Weight\t\tProfit\t\tRatio\n");
    for(i=0;i<len;i++){
        printf("%f\t%f\t%f\n",wt[i],pt[i],rt[i]);
    }
    printf("Enter the capacity of the bag: ");
    scanf("%f",&max_wt);
    while(max_wt>0){
        int maxindex=0;
        for(i=0;i<len;i++){
            if(rt[i]>rt[maxindex]) maxindex=i;}
        rt[maxindex]=-1;
        float wtratio=max_wt/wt[maxindex];//less than 1 for full req
        //greater than 1 for fractional req
        if(wtratio<1){pt[maxindex]*=wtratio;
        wt[maxindex]*=wtratio;}
        printf("Profit: %f\t Weight: %f\n",pt[maxindex],wt[maxindex]);
        profit+=pt[maxindex];
        max_wt-=wt[maxindex];
    }
    printf("Total Profit: %f",profit);
    return 0;
}