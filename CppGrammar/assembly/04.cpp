#include <iostream>
#pragma comment(lib, "msvcrtd.lib")
#pragma comment(lib, "vcruntimed.lib")
#pragma comment(lib, "ucrtd.lib")
#pragma comment(linker, "/ENTRY:foo ")
// #pragma comment(linker, "/INCLUDE:_mainCRTStartup")
int main() {
	return 0;
}
int foo() {
	std::cout << "hello world" << std::endl;
	return main();

}