#include<stdio.h>
void swap(int* a,int* b){
    int t=*a;
    *a=*b;
    *b=t;}
int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);}}
    swap(&arr[i+1],&arr[high]);
    return(i+1);}
void quickSort(int arr[],int low,int high){
    if (low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);}}
void printArray(int arr[],int len){
    for(int i=0;i<len;i++)
        printf("%d\t",arr[i]);
    printf("\n");}
int main(){
    int arr[100],len,i;
    printf("Enter the length of array: ");
    scanf("%d",&len);
    for(i=0;i<len;i++){
        printf("Enter %d element: ",i);
        scanf("%d",&arr[i]);}
    printArray(arr,len);
    quickSort(arr,0,len-1);
    printArray(arr,len);
    return 0;}

