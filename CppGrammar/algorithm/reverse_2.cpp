#include <iostream>
using namespace std;
int main(){
    int lo=1,hi=4;
    int A[]={1,2,3,4,5,6,7};
    next:
        if(lo<hi){
            swap(A[lo],A[hi]);
            lo++;
            hi--;
            goto next;
        }
    
    for(int a:A){
        cout<<a<<endl;
    }
}