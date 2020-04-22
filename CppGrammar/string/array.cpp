#include <iostream>
#include <array>
/*
    是一个容器类，所以有迭代（访问成员的高级指针）
    可以直接赋值
    知道自己的大小
    能和另一个子数组交换内容
    能以指定值填充自己
    取某个位置的元素
 */
using namespace std;
int main(){
    //C++数组是一个模板类，可以容纳任何数据
    //
    array<int,10> x;
    array<char,5> y{'H','E'};
    //C++17引入一种新特性，对模板类的参数进行推导
    // array a1{1,2,3};
    // array a2{'H','E'};

    for(char c:y){
        cout<<c<<endl;
    }

    cout<<y[0]<<endl;
    
    return 0;
}