#include<stdio.h>
void swap(int *x,int *y){
    int t;
    t=*x;
    *x=*y;
    *y=t;
}
void printArray(int arr[],int low,int high){
    int i;
    for(i=low;i<high;i++)
        printf("%d\t",arr[i]);
    printf("\n");
}
int Partition(int arr[],int low,int high){
    int pivot=arr[low];
    int start=low;
    int end=high;
    while(start<end){
        while(arr[start]<=pivot)
            start++;
        while(arr[end]>pivot)
            end--;
        if(start<end)
            swap(&arr[start],&arr[end]);
        printArray(arr,low,high);
    }
    swap(&arr[low],&arr[end]);
    return end;
}
int QuickSort(int arr[],int low,int high){
    if(low<high){
        int pvt=Partition(arr,low,high);
        QuickSort(arr,low,pvt-1);
        QuickSort(arr,pvt+1,high);
    }
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
    int low=0,high=len;
    printf("Array before sorting sorting:\n");
    printArray(arr,low,high);
    printf("Quick Sort:\n");
    QuickSort(arr,low,high);
    printf("Array after sorting:\n");
    printArray(arr,low,high);
    return 0;
}