#include<stdio.h>
void printArray(int arr[],int low,int high){
    int i;
    for(i=low;i<high;i++)
        printf("%d\t",arr[i]);
    printf("\n");
}
void Merge(int arr[],int low,int mid,int high){
    int i=low;
    int j=mid+1;
    int k=low;
    int b[high];
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            b[k]=arr[i];
            i++;
        }
        else{
            b[k]=arr[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=high){ 
            b[k]=arr[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid){
            b[k]=arr[i];
            i++;
            k++;
        }
    }
    for(k=low;k<=high;k++)
        arr[k]=b[k];
    printArray(arr,low,high);
}
void MergeSort(int arr[],int low,int high){
    if(low<high){
    int mid=(low+high)/2;
    MergeSort(arr,low,mid);
    MergeSort(arr,mid+1,high);
    Merge(arr,low,mid,high);}
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
    MergeSort(arr,low,high);
    printf("Array after sorting:\n");
    printArray(arr,low,high);
    return 0;
}