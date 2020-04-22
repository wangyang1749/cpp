#include <iostream>
#include <string>
#include <cmath>
#include <exception>

using namespace std;
class Vec2D{

private:
    double x_;
    double y_;
public:
    Vec2D(double x,double y){
        x_=x;
        y_=y;
    }
    Vec2D(){
        x_=0.0;
        y_=0.0;
    }
    ~Vec2D(){

    }

    std::string toString(){
        return std::string("("+std::to_string(x_)+","+std::to_string(y_)+")");
    }
    Vec2D operator+(Vec2D& secondVec2D){
       return this->add(secondVec2D);
    }
    Vec2D add(Vec2D secondVec2D){
       return Vec2D(x_+secondVec2D.x_,y_+secondVec2D.y_);
    }
    Vec2D add(double numeral){
       return Vec2D(this->x_+numeral,this->y_+numeral);
    }
    Vec2D subtract(Vec2D secondVec2D){
       return Vec2D(x_-secondVec2D.x_,y_-secondVec2D.y_);
    }
    double dot(Vec2D secondVec2D){
        return (x_*secondVec2D.x_+y_*secondVec2D.y_);
    }
    Vec2D multiply(double multiplier){
        return Vec2D(x_*multiplier,y_*multiplier);
    }
    Vec2D negative(){
        return Vec2D(-x_,-y_);
    }
    Vec2D& increase(){
        x_++;y_++;
        return (*this);
    }
    Vec2D& decrease(){
        x_--;y_--;
        return (*this);
    }
    double& at(const int index){
        if(0==index){
            return x_;
        }else if(1==index){
            return y_;
        }else{
            throw std::out_of_range("at().....");
        }
    }
    double magnitude(){
        return sqrt(x_*x_+y_*y_);
    }
    double direction(){
        return atan(y_/x_);
    }

    int compareTo(Vec2D secondVec2D){
        double m1=this->magnitude();
        double m2=secondVec2D.magnitude();
        if(abs(m1-m2)<1e-10)
            return 0;
        else
            return (m1>m2?1:-1);
    }

    friend Vec2D operator+(double,Vec2D);
};

Vec2D operator+(double number,Vec2D vec2d){
    return vec2d.add(number);
}

int main(){
    //创建向量对象
    Vec2D v1{3,5},v2{4,6};
    //向量转化为字符串
    std::cout<<"v1="<<v1.toString()<< std::endl;
    std::cout<<"v2="<<v2.toString()<<std::endl;
    //向量的加法：向量+向量 向量+数
    Vec2D v3 =v1+v2;
    // Vec2D v3 =v1.add(v2);
    // Vec2D v4=v3+10.0;
    Vec2D v4=v3.add(10.0);
    std::cout<<"v3="<<v3.toString()<<std::endl;
    std::cout<<"v4="<<v4.toString()<<std::endl;

    //向量的减法、点积、数乘
    Vec2D v5 = v2.subtract(v1);
    double v6 = v2.dot(v1);
    Vec2D v7 = v3.multiply(2.1);
    std::cout<<"v2-v1="<<v5.toString()<<std::endl;
    std::cout<<"v2.v1"<<v6<<std::endl;
    std::cout<<"v3.2.1"<<v7.toString()<<std::endl;
    //向量的负值
    Vec2D v8 = v2.negative();
    std::cout<<"v8"<<v8.toString()<<std::endl;

    //向量的自增/自减
    std::cout<<"++v8="<<v8.increase().toString()<<std::endl;
    std::cout<<"--v8="<<v8.decrease().toString()<<std::endl;
    
    //读取或者修改向量的元素
    std::cout<<"v1.x_="<<v1.at(0)<<std::endl;
    std::cout<<"v1.y_="<<v1.at(1)<<std::endl;

    //向量的长度和角度
    std::cout<<"v1.magnitude"<<v1.magnitude()<<std::endl;
    std::cout<<"v1.direction"<<v1.direction()<<std::endl;

    //比较两个向量
    std::cout<<"v1 compare v2"<<v1.compareTo(v2)<<std::endl;

    return 0;
}