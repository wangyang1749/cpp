#include <iostream>
using namespace std;
int main(){
    char c;
    int i = 0;
    do{
        // 每次读取一个字符并把有Enter键生成的换行符留在输入队列中
        c = cin.get();
        cout<<++i<<static_cast<int>(c)<<endl;
    }while (c!='q');
    return 0;
}