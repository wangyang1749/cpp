/**
 * Reference 引用就是另一个变量的别名
 * 通过引用所做的读写操作实际上是作用与原变量上
 * 引用参数：改变引用变量的值，实际上改变的是实际参数的值
 * 2020 4 23
 * **/

#include <iostream>
using namespace std;

void swap(int&,int&);

int main(){
    int a{5},b{10};
    cout<<"a="<<a<<" b="<<b<<endl;
    swap(a,b);
    cout<<"a="<<a<<" b="<<b<<endl;


    int d =99;
    int e = 66;
    const int *p; //不能通过指针修改，但是可以改变指针所指
    p = &d;
    // *p = 33; // 编译报错

    const int*& r = p; //指针类型的引用
    r = &e;

    cout<<"p="<<p<<" *p="<<*p<<endl;
    p = &e;
    cout<<"p="<<p<<" *p="<<*p<<endl;

    return 0;
}

void swap(int& a,int& b){
    int temp =a;
    a=b;
    b=temp;
}

