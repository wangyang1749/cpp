#include <vector>
#include <iostream>
#include <string>

#define PRINT(x) std::cout << #x <<":"<<x<<std::endl;


// https://en.cppreference.com/w/cpp/container/vector/vector
template<typename T>
std::ostream& operator<<(std::ostream& s, const std::vector<T>& v) 
{
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'};
    for (const auto& e : v) {
        s << comma << e;
        comma[0] = ',';
    }
    return s << ']';
}