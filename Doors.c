#include<stdio.h>
#include<stdbool.h>
int main(){
    int n,i,j,open=0;
    printf("Enter number of doors: ");
    scanf("%d",&n);
    bool arr[n];
    for(i=0;i<n;i++)arr[i]=false;
    for(i=0;i<n;i++){
        for(j=i+1;j<=n;j+=(i+1)){
            if(arr[j-1]==false)arr[j-1]=true;
            else arr[j-1]=false;
        }
        for(j=0;j<n;j++)
        {
            if((j+1)%(i+1)==0) printf("\033[1;33m");
            else printf("\033[1;31m");
            printf("%i  ",arr[j]);
        }
        printf("\n");
    }
    for(i=0;i<n;i++){
        if(arr[i]==true)open++;
    }
    printf("Open: %d\nClose: %d",open,n-open);
    return 0;
}
