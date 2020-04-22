/*任给数组A[0,n),将其前后颠倒
 */
#include <iostream>

using namespace std;
void reveser(int A[],int lo,int hi);
int main(){
    int A[] = {1,2,3,4,5,6,7};
    reveser(A,1,4);
    for(int a : A){
        cout<<a<<endl;
    }

}
void reveser(int A[],int lo,int hi){
    if(lo<hi){
        swap(A[lo],A[hi]);
        reveser(A,lo+1,hi-1);
    }
}
