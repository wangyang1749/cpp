#include <iostream>
#include "LibAdd.h"

void HelloDll::hello()
{
    std::cout << "hello, this is my dll ^_^ " << std::endl;
}

// -Wl,--output-def,libadd.def,--out-implib,libadd.a,--add-stdcall-alias
// ar cr libhello.a hello.o