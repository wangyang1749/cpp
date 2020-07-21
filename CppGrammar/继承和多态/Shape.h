#include <iostream>
#include <string>
#include <array>
using std::string;
using namespace std::string_literals;

enum class Color{
    white,black,red,green,blue,yellow,
};
class Shape
{
private:
    Color color{Color::black};
    bool filled{false};
public:
    Shape()=default;
    Shape(Color color,bool filled){
        this->color = color;
        this->filled = filled;
    }
    ~Shape();
};

Shape::Shape(/* args */)
{
}

Shape::~Shape()
{
}


