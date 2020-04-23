/**
 * Dynamic memory managemennt 动态内存管理（分配，释放）
 * new 动态申请内存
 *  new <类型名>(初值); new <类型名>{初值};申请一个变量空间
 *  new <类型名>[常量表达式]; 申请数组
 *  如果申请成功，返回指定类型内存的地址
 *  如果申请失败，抛出异常，或者返回空指针(nullptr)
 * delete 运算符释放内存
 *  delete <指针名>; 删除变量/对象
 *  delete[]<指针名>; 删除数组空间
 * 2020 4 23
 * **/

#include <iostream>

using namespace std;
int main(){
    int *p{nullptr};
    int *q{nullptr};
    p = new int{25};// 返回指定类型内存的地址
    cout<<"p="<<*p<<endl;

    q = new int[4];
    for (int i = 0;i<4;i++){
        q[i]=10+i;
        cout<<q[i]<<endl;
    }

    delete p;
    delete [] q;
}