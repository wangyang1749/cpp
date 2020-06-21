#include <string>
#include <iostream>
#include <cmath>

class Vec2D
{
private:
    double x_;
    double y_;
public:
    Vec2D();
    ~Vec2D();
    Vec2D(double x,double y);
    std::string toString();
    Vec2D add(const Vec2D& secondVec2D);
    Vec2D operator+(Vec2D secondVec2D){
        return this->add(secondVec2D);
    }
    Vec2D add(double number);
    Vec2D  operator+(double number){
         return this->add(number);
    }
    Vec2D subtract(Vec2D secondVec2D);
    double dot(Vec2D secondVec2D);
    Vec2D multiply(double number);
    Vec2D negative();
    Vec2D& increrase();
    Vec2D& decrease();
    double & at(const int index);
    double magnitude();
    double direction();
    int compareTo(Vec2D secondVec2D);
};

