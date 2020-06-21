#include <iostream>
using namespace std;

int main(){
    //拿到cin对象的缓冲区指针
    auto p = cin.rdbuf();
    // 从键盘读取字符到缓冲区， peek可以读取并保留字符在缓冲区
    auto x = cin.peek();
    cout<<"x="<<x<<endl;
    //显示缓冲区中的字符数量
    auto count = p->in_avail();
    cout<<"There are "<<count<<"characters in the buffer"<<endl;
    //把缓冲区的字符都取出来并显示
    for(int i=0;i<count;i++){
        cout<<i+1<<" : "<<cin.get()<<endl;
    }
    return 0;
}