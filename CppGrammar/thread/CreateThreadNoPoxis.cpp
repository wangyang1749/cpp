#include <thread>
#include <iostream>

void PrintAs(){
    while (true)std::cerr<<'a';

    
}
void PrintZs(){
    while (true)std::cerr<<'z';

}

int main(){
    std::thread t(&PrintAs);
    PrintZs();
    return 0;
}
    