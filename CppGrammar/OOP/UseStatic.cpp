#include <iostream>
class UseStatic
{
private:
    /* data */
public:
    static void show();
    UseStatic(/* args */);
    ~UseStatic();
};

void UseStatic::show(){
    std::cout<<"Hello";
}

UseStatic::UseStatic(/* args */)
{
}

UseStatic::~UseStatic()
{
}

int main(){
    UseStatic u{};
    u.show();
    UseStatic::show();
    return 0;
}