#include <iostream>

using std::cout;
using std::endl;
template <typename T>
T max(T x,T y){
    return (x>y?x:y);
}

// template <int> int max(int,int);
int main(){
    cout<<max(1,2)<<endl;
    

}