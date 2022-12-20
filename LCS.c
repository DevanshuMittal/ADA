/*
<-----Cities on bank A------>
11  8   1   15   4   14  9   3   10   5   2   6   7  12  12
-----------------------------
<-----------River----------->
-----------------------------
1   2   3   4   5   6   7   8   9   10  11  12  13  14  15
<-----Cities on bank B------>
*/
#include<stdio.h>
#include<string.h>
int main(){
    char str1[20],str2[20];
    int i,j;
    printf("Enter the first string: ");
    scanf("%s",str1);
    printf("Enter the second string: ");
    scanf("%s",str2);
    int len1=strlen(str1);
    int len2=strlen(str2);
    int arr[len1+1][len2+1];
    char dir[len1+1][len2+1];
    for(i=0;i<=len1;i++){
        for(j=0;j<=len2;j++){
            if(i==0 || j==0){
                arr[i][j]=0;
                dir[i][j]='Z';}
            else{
                if(str1[i-1]==str2[j-1]){
                    arr[i][j]=arr[i-1][j-1]+1;
                    dir[i][j]='D';}
                else{
                    if(arr[i][j-1]>arr[i-1][j]){
                        arr[i][j]=arr[i][j-1];
                        dir[i][j]='L';}
                    else{
                        arr[i][j]=arr[i-1][j];
                        dir[i][j]='U';}}}}}
    printf("Table for length of LCS:\n");
    for(i=0;i<=len1;i++){
        for(j=0;j<=len2;j++)
            printf("%d ",arr[i][j]);
        printf("\n");}

    printf("Table for directions:\n");
    for(i=1;i<=len1;i++){
        for(j=1;j<=len2;j++)
            printf("%c ",dir[i][j]);
        printf("\n");}
    int length=arr[len1][len2];
    int a=len1;
    int b=len2;
    char answer[length];
    printf("Length of longest common subsequence is %d\n",length);
    while(length>0){
        if(dir[a][b]=='D'){
            answer[length-1]=str1[a-1];
            a--;
            b--;
            length--;}
        else if(dir[a][b]=='U')--a;
        else if(dir[a][b]=='L')--b;
        else{break;}}
    printf("%s",answer);
    return 0;}