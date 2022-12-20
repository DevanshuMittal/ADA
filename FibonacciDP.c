#include<stdio.h>
int main(){
    int num=7,i;
    int arr[num];
    for(i=0;i<num;i++){
        if (i<2)  
            arr[i]=i;
        else
            arr[i]=arr[i-1]+arr[i-2];
        printf("%d\t",arr[i]);
    }
    
}