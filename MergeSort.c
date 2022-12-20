#include <stdio.h>
void merge(int arr[],int low,int mid,int high){
    int i,j,k;
    int n1=mid-low+1;
    int n2=high-mid;
    int lArr[n1],rArr[n2];
    for(int i=0;i<n1;i++)
        lArr[i]=arr[low+i];
    for(int j=0;j<n2;j++)
        rArr[j]=arr[mid+j+1];
    i=0;
    j=0;
    k=low;
    while(i<n1 && j<n2){
        if(lArr[i]<=rArr[j]){
            arr[k]=lArr[i];
            i++;
        }
        else{
            arr[k]=rArr[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=lArr[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=rArr[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
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
    mergeSort(arr,0,len-1);
    printArray(arr,len);
    return 0;}
