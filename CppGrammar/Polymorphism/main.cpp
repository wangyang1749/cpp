#include <iostream>

using namespace std;
class A{
public:
//虚函数
    virtual void f(){
        cout<<"A f()"<<endl;
    }
    // virtual void d()=0;
};
class B:public A{
public:
    void f() override{
        cout<<"B f()"<<endl;
    }
      void f2(){
        cout<<"B f2()"<<endl;
    }
};

void print(A* a){
    a->f();
}

int main(){
    A a;
    B b;
    A*  p= &b;
    // a.f();
    // b.f();
    // b.A::f();
    p->f();
    B b2=B{};
    A* b3 = new B{};
    //隐式类型转换，
    //子类型地址转化为，父类型的指针
    print(b3);

    A a2=b;
    a2.f();

    A& a3=b;
    a3.f();
    return 0;
}