/**
 * 计算任意n个数
 * 2020 4 22
 **/
#include <stdio.h>

int sum(int A[],int n){
    return n<1? 0: sum(A,n-1)+A[n-1];
}

int main(){
    int A[] = {1,2,3};
    int B = sum(A,3);
    printf("%d",B);
}