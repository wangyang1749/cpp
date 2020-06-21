#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::ofstream output{"aa.txt"};
    output<<"wukong"<<" "<<80<<std::endl;
    output.close();

    std::ifstream input{"aa.txt"};
    
    std::string name{""};
    int age;

    if(input.fail()){
       std::cout<< "Can't open file" <<std::endl;
        return 0;
    }
    input >> name >>age;
    std::cout<<name<<age<<std::endl;


    // char x;
    // while (!input.get(x).eof())
    // {
    //     // input.get(x);
    //     std::cout<<x;
    // }
    
    return 0;
}