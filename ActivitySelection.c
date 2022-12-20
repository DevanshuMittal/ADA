#include<stdio.h>
int main(){
    int len,i,j;
    printf("Enter the number of activities: ");
    scanf("%d",&len);
    int start[len];
    int finish[len];
    for(i=0;i<len;i++){
        printf("Enter starting time for activity %d: ",i+1);
        scanf("%d",&start[i]);
        printf("Enter finishing time for activity %d: ",i+1);
        scanf("%d",&finish[i]);
    }
    printf("Activity\tStart\t\tFinish\n");
    for(i=0;i<len;i++){
        printf("%d\t\t%d\t\t%d\n",i+1,start[i],finish[i]);
    }
    printf("Sequence of activities:\n");
    j=0;
    for(i=1;i<=len;i++){
        if(start[i]>=finish[j]){
            printf("A%d\t",i);
            j=i;
        }
    }
    return 0;
}