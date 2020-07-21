#include <iostream>
#include <string>
#include <memory>

template<typename T>
class UniquePointer{
public:
    using Pointer = T*;
    using Reference = T&;
    UniquePointer():ptr_(nullptr){}
    UniquePointer(Pointer ptr):ptr_(ptr){}
    //拷贝构造函数
    UniquePointer(const UniquePointer&)=delete;
    //赋值构造函数
    UniquePointer& operator = (const UniquePointer&) = delete;
    //移动语义
    UniquePointer(UniquePointer&& other):ptr_{other.ptr_}{
        other.ptr_ = nullptr;
    }
    UniquePointer & operator=(UniquePointer&& other){
        ptr_=other.ptr_;
        other.ptr_=nullptr;
        return *this;
    }

    ~UniquePointer(){
        if(ptr_!=nullptr){
            delete ptr_;
        }
    }
    Pointer operator->(){
        return ptr_;
    }
    operator bool(){
        return ptr_!=nullptr;
    }

private:
    Pointer ptr_;
};
using namespace std;
class Person{

public:
    string name="111111";
    ~Person(){
        cout<<"Person 被析构"<<endl;
    }
};

 UniquePointer<Person> test(){
     return UniquePointer<Person>{new Person};
 }

int main(){
    UniquePointer<Person> p1(new Person);
    UniquePointer<Person> p2 = test();
    cout<<p2->name<<endl;
    UniquePointer<Person> p3;
    cout<<p3<<endl;
    return 0;
}