#include <iostream>
#include "Vec2D.h"
using std::cout;
using std::endl;
// g++ main.cpp Vec2D.cpp -I.  -o Vec2D

int main(){
    //创建向量对象
    Vec2D v1{3,5},v2{4,6};
    //向量转化为字符串
    cout<< "v1="<<v1.toString()<<endl;
    cout<< "v2="<<v2.toString()<<endl;
    // 向量加法： 向量+向量 向量+数
    // Vec2D v3 = v1.add(v2);
    Vec2D v3 = v1+v2;
    // Vec2D v4 = v3.add(10.0);
    Vec2D v4 = v3+10.0;
    cout<< "v3="<<v3.toString()<<endl;
    cout<< "v4="<<v4.toString()<<endl;
    // 向量减法 向量点积 向量数乘
    Vec2D v5 = v2.subtract(v1);
    double v6 = v2.dot(v1);
    Vec2D v7 = v3.multiply(2.1);
    cout<< "v2 + v1="<<v5.toString()<<endl;
    cout<< "v2 . v1="<<v6<<endl;
    cout<< "v7="<<v7.toString()<<endl;
    //向量的求负
    Vec2D v8 = v2.negative();
    cout<< "-v2 = "<<v8.toString()<<endl;
    //向量的自增、自减
    cout<< "++v8="<<v8.increrase().toString()<<endl;
    cout<< "--v2="<<v2.decrease().toString()<<endl;
    // 读取或者修改向量的元素
    cout<< "v1.x_="<< v1.at(0) <<endl;
    cout<< "v1.y_="<< v1.at(1) <<endl;
    //向量的长度和角度
    cout<<"v1.magnitude"<<v1.magnitude()<<endl;
    cout<<"v1.direction"<<v1.direction()<<endl;
    // 比较两个向量
    cout<<" v1 compare v2"<<v1.compareTo(v2)<<endl;
}