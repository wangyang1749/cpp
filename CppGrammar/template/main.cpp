#include <iostream>
// template <class T>
// T add(T x,T y){
//     return (x+y);
// }

template <class T,class S>
auto add(T x,S y){
    return (x+y);
}
//显示实例化
template auto add<>(int,int);
using namespace std;
int main(){
    // double a = add(10.0,2);
    //隐式实例化
    cout<<add(5.9,20)<<endl;
    cout<<add<int,int>(5.9,20)<<endl;
    cout<<add<>(5.9,20)<<endl;

    double (*ptr)(int,double) =add;
    cout<<ptr(10,10.5)<<endl;
    return 0;
}
