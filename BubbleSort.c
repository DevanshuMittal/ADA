#include<stdio.h>
void swap(int *x,int *y){
    int t;
    t=*x;
    *x=*y;
    *y=t;
}
void printArray(int arr[],int len){
    int i;
    for(i=0;i<len;i++)
        printf("%d\t",arr[i]);
    printf("\n");
}
void BubbleSort(int arr[],int len){
    int i,j;
    for(i=0;i<len-1;i++)//pass loop swap biggest element to right
    {
        
        for(j=0;j<len-i-1;j++)//loop till unsorted array
        {
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);}
            printArray(arr,len);        
        }
        printf("\n");
    }
    printf("\n");
}
int main(){
    int len,i;
    printf("Enter the length of array: ");
    scanf("%d",&len);
    int arr[len];
    printf("Enter the array elements:\n");
    for(i=0;i<len;i++){
        printf("Enter the element %d: ",i);
        scanf("%d",&arr[i]);
    }
    printArray(arr,len);
    BubbleSort(arr,len);
    return 0;
}
