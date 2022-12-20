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
void SelectionSort(int arr[],int len){
    int i,j,min;
    for(i=0;i<len;i++){
        min=i;
        for(j=i+1;j<len;j++){
            if(arr[min]>arr[j]){
                min=j;
            }
            
            //printArray(arr,len);
        }
        printf("\n");
        swap(&arr[i],&arr[min]);
        printArray(arr,len);
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
    printf("Selection Sort:\n");
    SelectionSort(arr,len);
    printf("Array after sorting:\n");
    printArray(arr,len);
    return 0;
}