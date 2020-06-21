#include "Vec2D.h"
#include <exception>
Vec2D::Vec2D(/* args */)
{
}

Vec2D::~Vec2D()
{
}
Vec2D::Vec2D(double x,double y){
    x_ =x;
    y_ = y;
    
}
std::string Vec2D::toString(){
    return std::string("("+std::to_string(x_)+","
                        +std::to_string(y_)+")");
}
Vec2D Vec2D::add(const Vec2D&  secondVec2D){
     return Vec2D(this->x_+secondVec2D.x_,this->y_+secondVec2D.y_);
}
Vec2D Vec2D::add(double number){
    return Vec2D(this->x_+number,this->y_+number);
}
Vec2D Vec2D::subtract(Vec2D secondVec2D){
    return Vec2D(this->x_-secondVec2D.x_,this->y_-secondVec2D.y_);
}
double Vec2D::dot(Vec2D secondVec2D){
    return (this->x_*secondVec2D.x_+this->y_*secondVec2D.y_);
}
Vec2D Vec2D::multiply(double number){
    return Vec2D(this->x_*number,this->y_*number);
}
Vec2D Vec2D::negative(){
    return Vec2D(-x_,-y_);
}
Vec2D& Vec2D::increrase(){
    x_++;y_++;
    return(*this);
}
Vec2D& Vec2D::decrease(){
    x_--;y_--;
    return(*this);
}
double& Vec2D::at(const int index){
    if(0==index)
        return x_;
    else if(1==index)
        return y_;
    else
        throw std::out_of_range("at() only accept 1 or 2 as parameter");
}
double Vec2D::magnitude(){
    return sqrt(x_*x_+y_*y_);
}
double Vec2D::direction(){
    return atan(y_/x_);
}
int Vec2D::compareTo(Vec2D secondVec2D){
    double m1 = this->magnitude();
    double m2 = secondVec2D.magnitude();
    if (abs(m1-m2)<1e-10)
        return 0;
    else
        return (m1>m2 ?1:-1);
}