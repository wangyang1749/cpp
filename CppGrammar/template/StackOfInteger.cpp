#include <iostream>
using std::cout;
using std::endl;

class StackOfInteger{
private:
    int elemnet[100];
    int size{0};
public:
    StackOfInteger(){
        size=0;
        for(int& e:elemnet){
            e=0;
        }
    }
    bool empty(){
        return (size=0?true:false);
    }
    int peek(){
        return elemnet[size-1];
    }
    //入栈
    int push(int value){
        elemnet[size]=value;
        size++;
        return value;
    }
    //将栈里的函数移除并返回值
    int pop(){
        int temp = elemnet[size-1];
        elemnet[size-1]=0;
        size--;
        return temp;
    }
    int getSize(){
        return size;
    }
};  

int main(){
    StackOfInteger s1{};
    for(int i=0;i<5;i++){
        s1.push(i+1);
    }
    cout<<s1.getSize()<<endl;
    cout<<s1.peek()<<endl;
    int size=s1.getSize();
    for(int i=0;i<size;i++){
        cout<<s1.pop()<<endl;
    }
    // cout<<s1.empty()<<endl;

}