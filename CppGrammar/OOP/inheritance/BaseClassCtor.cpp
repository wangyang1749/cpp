#include <iostream>
using namespace std;
//任务1、继承构造函数
//  创建基类的构造函数B(int)
class B{
public:
    B(){cout<<"B()"<<endl;}
    B(int i){cout<<"B("<<i<<")"<<endl;}
    B(char c){cout<<"B("<<c<<")"<<endl;}

};
class E{
public:
    E(){ cout<<"E()"<<endl;}
};
class D:public B{
public:
    using B::B;
    //D():B{}{}
    //D(int i):B{i}{}
    //D(char c){}
    D(double x):e1{},e2{},B{static_cast<int>(x)}{cout<<"D("<<x<<")"<<endl;}
private:
     E e1,e2;
};


int main(){
    B b;
    D d;//子类默认构造函数自动调用基类的构造函数
    // D d2{3.03};
    return 0;
}