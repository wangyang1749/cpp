#include <iostream>
using namespace std;
int  main(){
    int A[] ={1,2,3,4,5,6,7};
    int lo=1,hi=5;
    while(lo<hi)
    {
        swap(A[lo++],A[hi--]);
    }
    for(int a : A){
        cout<<a<<endl;
        
    }
    
}   

