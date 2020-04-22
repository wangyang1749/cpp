#include <iostream>

using namespace std;

class A
{
private:
    int a;

public:
    int getA(){
        return this->a;
    }
    A()
    {
        cout << "A no argument constructor" << endl;
    }
    A(int i):a{i}
    {
        cout << "A this i is " << i << endl;
    }
};
class B : public A
{
private:
    int b;

public:
    using A::A; //继承基类all constructor,除了A{int i}
  
    int getB(){
        return this->b;
    }
    /*
    如果子类的构造函数也要初始化，则可以在子类构造函数中调用父类构造函数
    */
    B(int i):b{i},A{i}{
        
    }
};
int main()
{
    // B b{};
    B b2{3};
    cout<<b2.getA()<<endl;
    return 0;
}
