#include <iostream>

using namespace std;
int sum(int A[],int n);
int main(){
    int A[] = {3,3,3,3,3};
    cout<<sum(A,5)<<endl;
}

int sum(int A[],int n){
    int count = 0;
    for(int i=0;i<n;i++){
        count+=A[i];
    }
    return count;
}