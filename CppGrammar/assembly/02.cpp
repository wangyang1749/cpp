#include <iostream>

#pragma comment(linker, "/ENTRY:foo ")
#pragma comment(linker, "/INCLUDE:_mainCRTStartup")


int main()
{
	return 0;
}



int foo()
{
	std::cout << "hello world" << std::endl;
	return 0;
}