#include <iostream>
#include <string>
#include <memory>

using namespace std;
class Person{

public:
    string name="111111";
    ~Person(){
        cout<<"Person 被析构"<<endl;
    }
};

unique_ptr<Person> test(){
    return  unique_ptr<Person>{new Person};//会调用Person的析构函数
}

int main(){

    // Person * p1 = new Person;//不会调用Person的析构函数
    // unique_ptr<Person> p2{new Person};//会调用Person的析构函数
    // cout<<p2->name<<endl;
    unique_ptr<Person> p3 = test();
    cout<<p3->name<<endl;
    //只能有一个对象拥有指针的所有权
    unique_ptr<Person> p4 = move(p3);
    // cout<<p3->name<<endl;//此时p3是空的
    p4.reset(new Person);//此时 p4 会被销毁，这里创建的对象也会被销毁


    unique_ptr<Person> p5 =make_unique<Person>();

    return 0;
}