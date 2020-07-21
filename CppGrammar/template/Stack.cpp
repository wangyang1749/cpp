#include <iostream>
using std::cout;
using std::endl;
template<typename T>
class Stack{
private:
    T elemnet[100];
    int size{0};
public:
    Stack(){
        size=0;
        for(T& e:elemnet){
            e=0;
        }
    }
    bool empty(){
        return (size==0?true:false);
    }
    T peek(){
        return elemnet[size-1];
    }
    //入栈
    T push(T value){
        elemnet[size]=value;
        size++;
        return value;
    }
    //将栈里的函数移除并返回值
    T pop();
    int getSize(){
        return size;
    }
};  
// template<typename T>
// T  Stack<T>::push(T value){
    
// }
template<typename T>
T Stack<T>::pop(){
    T temp = elemnet[size-1];
    elemnet[size-1]=0;
    size--;
    return temp;
}

//显式实例化
template class Stack<int>;
int main(){
    Stack<int> s1{};
    for(int i=0;i<5;i++){
        s1.push(i+1);
    }
    cout<<s1.getSize()<<endl;
    cout<<s1.peek()<<endl;
    // int size=s1.getSize();
    // for(int i=0;i<size;i++){
    //     cout<<s1.pop()<<endl;
    // }
    while(!s1.empty()){
        cout<<s1.pop()<<endl;
    }
    cout<<s1.empty()<<endl;

    Stack<char> c;
    std::string s ="HelloWord";
    for(auto i:s){
        c.push(i);
    }
    for(;c.empty()!=true;){
        cout<<c.pop();
    }

}