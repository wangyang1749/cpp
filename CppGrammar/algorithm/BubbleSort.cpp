#include <iostream>

using namespace std;
void bubblesort(int A[],int n);

int main(){
    int A[]={5,7,2,6,8,1};
    cout<<sizeof (A)/sizeof (int)<<endl;
   
    cout<<A[0]<<endl;
    cout<<*A<<endl;//数组的引用指向第一个元素
    bubblesort(A,sizeof (A)/sizeof (int));
    for (int a:A){
        cout<<a<<" ";
    }
}

void bubblesort(int A[],int n){
    for(bool sorted=false;sorted=!sorted;n--){
        for(int i=1;i<n;i++){
            if(A[i-1]>A[i]){
                swap(A[i-1],A[i]);
                sorted=false;
            }
        }
    }
}
