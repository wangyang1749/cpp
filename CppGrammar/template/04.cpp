#include <iostream>
template<typename T>
void f(T s) {
    std::cout << s << '\n';
}
int main(){
    f<double>(1); // 实例化并调用 f<double>(double)
    f<>('a'); // 实例化并调用 f<char>(char)
    f(7); // 实例化并调用 f<int>(int)
    void (*ptr)(std::string) = f; // 实例化 f<string>(string)
}