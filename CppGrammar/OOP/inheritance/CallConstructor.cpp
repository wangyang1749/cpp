#include <iostream>

using namespace std;

class A
{
private:
    int number;
public:
    A(){
        cout<<"A no argument constructor"<<endl;
    }
    A(int i){
        cout<<"A this i is "<<i<<endl;
    }
};
class B : public A
{
private:
    int number;
public:
    /*
    当创建B b2{2};
    此时会隐式的添加
    B(int i):A{i}{}
    相当于自动调用了类A的构造函数
     */
    using A::A;//继承基类all constructor
    int i{0};
};

int main()
{
    B b2{2};
    return 0;
}











