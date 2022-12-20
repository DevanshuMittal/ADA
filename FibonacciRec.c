#include<stdio.h>
int fib(int n){
    if (n<0) 
        return -1;
    else if (n<3)
    {
        return n-1;
    }
    else return fib(n-1)+fib(n-2);
}
int main(){
    int n=5;
    printf("%d",fib(n));
    return 0;
}