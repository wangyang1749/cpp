/*重定义函数 */
/*名字隐藏 */
#include <iostream>

using namespace std;
class P{
    public:
    void f(){
        cout<<"P f()"<<endl;
    }
};
//子类是一个内部作用域
class C:public P{
    public:
    using P::f;
    //与基类函数相同
    void f(){cout<<"C f()"<<endl;}
};

int main(){
    C c;
    c.f();
    c.P::f();
    return 0;
}