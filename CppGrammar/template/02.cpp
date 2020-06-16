#include <iostream>
template <typename T, typename S>
auto add (T  x1, S x2) { //C++14
    return (x1 + x2);
}

int main () {
  auto y = add ( 1, 2.0 );
  std::cout<<y<<std::endl; //3
  return 0;
}

 