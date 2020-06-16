/*
一个文件中实现分离
*/

#include <Circle.h>


Circle::Circle(){
    radius=1;
}
Circle::Circle(double radius_){
    radius = radius_;
}

double Circle::getArea(){
    return (3.14*radius*radius);
}

