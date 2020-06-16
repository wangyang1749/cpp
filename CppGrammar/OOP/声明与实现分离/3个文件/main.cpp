#include <Circle.h>
#include <iostream>
//  g++ Circle.cpp  main.cpp  -I .   -o main
int main(){
    Circle c1;
    Circle c2{2.0};
    std::cout<<c1.getArea()<<std::endl;
    std::cout<<c2.getArea()<<std::endl;
}