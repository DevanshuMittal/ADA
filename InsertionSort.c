#include<stdio.h>
void printArray(int arr[],int len){
    int i;
    for(i=0;i<len;i++)
        printf("%d\t",arr[i]);
    printf("\n");
}
void InsertionSort(int arr[],int len){
    int temp,i,j;
    for(i=1;i<len;i++){
        temp=arr[i];
        j=i-1;
        while(temp<arr[j] && j>=0){
            arr[j+1]=arr[j];
            j--;
            printArray(arr,len);
        }
        arr[j+1]=temp;
        printf("\n");
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
    printf("Array before sorting sorting:\n");
    printArray(arr,len);
    printf("Insertion Sort:\n");
    InsertionSort(arr,len);
    printf("Array after sorting:\n");
    printArray(arr,len);
    return 0;
}
