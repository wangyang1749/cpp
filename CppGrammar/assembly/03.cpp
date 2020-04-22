#include <iostream>

#pragma comment(linker, "/ENTRY:_foo ")
// #pragma comment(linker, "/INCLUDE:_mainCRTStartup")
int main(){
	return 0;
}
int foo(){
    // int* i = new int{};
    double a = 5.0;
	std::cout << "hello world" << std::endl;
	return 0;
}