#include <iostream>

using namespace std;

int main(){
    //使用cin对象的缓冲区对象
    auto p = cin.rdbuf();

    //从键盘读入字符串到缓冲区，保留所有字符在缓冲区
    auto x = cin.peek();
    cout<<"x="<<x<<endl;
 
    //显示缓冲区字符的数量
    auto count= p->in_avail();
    cout<<"this is"<<count<<endl;
    //把缓冲器字符取出显示
    
    for(int i=0;i<count;i++){
        cout<<i+1<<cin.get()<<endl;
    }
    //当缓冲区中有数据时cin.get();不会停留
    cin.get();
}