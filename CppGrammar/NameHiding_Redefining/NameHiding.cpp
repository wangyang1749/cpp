/*名字隐藏 */
#include <iostream>

using namespace std;
class P{
    public:
    void f(){}
};
//子类是一个内部作用域
class C:public P{
    public:
    using P::f;
    //基类的同名函数被隐藏
    void f(int i){cout<<"i is"<<i<<endl;}
};

int main(){
    C c;
    c.f();
    return 0;
}