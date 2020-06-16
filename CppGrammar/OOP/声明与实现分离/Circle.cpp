/*
一个文件中实现分离
*/
#include <iostream>

class Circle{
     double radius;
    public:
        Circle();
        Circle(double radius_);
        double getArea();
};

Circle::Circle(){
    radius=1;
}
Circle::Circle(double radius_){
    radius = radius_;
}

double Circle::getArea(){
    return (3.14*radius*radius);
}

int main(){
    Circle c1;
    Circle c2{2.0};
    std::cout<<c1.getArea()<<std::endl;
    std::cout<<c2.getArea()<<std::endl;
}