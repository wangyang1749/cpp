#include <iostream>

using namespace std;
int sum(int A[],int n);
int main(){
    int A[]={5,5,5};
    cout<<sum(A,3)<<endl;
}

int sum(int A[],int n){
    return (n<1)?0 : sum(A,n-1)+A[n-1];
}