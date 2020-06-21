#include <iostream>
#include <experimental/filesystem>
#include <string>

//g++ -std=c++17   path.cpp -o path -lstdc++fs
int main(){
    //定义路径
    namespace fs = std::experimental::filesystem;
    fs::path p{"/"};
    // 输出文件分隔符
    std::cout<< fs::path::preferred_separator<<std::endl;
    //判断文件是否是常规文件，如果是输出文件大小
    if(fs::is_regular_file(p)){
        std::cout<< fs::file_size(p)<<std::endl;
    }else if (fs::is_directory(p)){
        std::cout<< p<<"is directory,includes:"<<std::endl;
        for (auto &e : fs::directory_iterator(p)){
            std::cout<<" "<<e.path();
        }
    }else if (fs::exists(p)){   
        std::cout<<p<<"is a special file\n";
    }else{
        std::cout<<p<<"does not exist"<<std::endl;
    }
    return 0;
}