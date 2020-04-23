/**
 * nullptr 空指针
 * 2020 4 23
 * **/

#include <iostream>

using namespace std;
int main(){
    auto x{10}; //int x = 10;
    int *p =nullptr;
    int *q{nullptr};
    q=&x;
    return 0;
}