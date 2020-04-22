#include <iostream>
using namespace std;
class Computer{
    public:
    Computer(){cout<<"Cmputer"<<endl;}
    ~Computer(){cout<<"~Computer"<<endl;}
};

class Pc:public Computer{
    public:
    Pc(){cout<<"Pc()"<<endl;}
    ~Pc(){cout<<"~Pc()"<<endl;}
};
class Desktop: public Pc{
    public:
    Desktop(){cout<<"Desktop()"<<endl;}
    ~Desktop(){cout<<"~Desktop()"<<endl;}
    Desktop(Desktop* desktop){

    }
};
class Camera{
    public:
    Camera(){cout<<"Camera()"<<endl;}
    ~Camera(){cout<<"~Camera()"<<endl;}
};
class Laptop:public Pc{
    private:
    Camera c{};
    public:
    Laptop(){cout<<"Laptop()"<<endl;}
    ~Laptop(){cout<<"~Laptop()"<<endl;}
};

int main(){
    {
        //  Desktop d{};
        //  Laptop l{};
        // Desktop* d0 = new Desktop{};
        // Desktop d1{};

        Desktop d2 =Desktop{};//匿名对象做拷贝初始化
        // Desktop d3;//直接初始化
        // d3=Desktop{}; //匿名对象赋值

        // Desktop d4=d3;



    }
   

    return 0;
}