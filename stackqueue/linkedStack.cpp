#include <iostream>
using namespace std;
template <class T> class lnkStack;
template <class T> // 栈的元素类型为 T
class Stack
{
public:                      // 栈的运算集
    void clear();            // 变为空栈
    bool push(const T item); // item入栈，成功则返回真，否则返回假
    bool pop(T &item);       // 返回栈顶内容并弹出，成功返回真，否则返回假,
    bool getTop(T &item);    // 返回栈顶内容但不弹出成功返回真，否则返回假,
    bool isEmpty();          // 若栈已空返回真
    bool isFull();           // 若栈已满返回真
};
template <class T>
class Link
{
private:
    T data;     // 用于保存结点元素的内容
    Link *next; // 指向后继结点的指针
public:
    friend class lnkStack<T>;
    Link(const T info, Link *nextValue);
    Link(Link *nextValue = NULL);
};
template <class T>
Link<T>::Link(const T info, Link *nextValue){
    data = info;
    next = nextValue;
}
template <class T>
class lnkStack : public Stack<T>
{
private:          // 栈的链式存储
    Link<T> *top; // 指向栈顶的指针
    int size;     // 存放元素的个数
public:           // 栈运算的链式实现
    lnkStack(int defSize);
    ~lnkStack();
    void clear();
    bool push(const T item);
    bool pop(T &item);
    bool getTop(T &item);
};
template<class T>
lnkStack<T>::lnkStack(int defSize){
    top = NULL;
    size = 0;
}
template<class T>
lnkStack<T>::~lnkStack(){
    clear();
}
template<class T>
void lnkStack<T>::clear(){

}
template<class T>
bool lnkStack<T>::push(const T item){
    Link<T> *tmp = new Link<T>(item,top);
    top = tmp;
    size++;
    return true;
}
template<class T>
bool  lnkStack<T>::pop(T &item){
    Link<T> * tmp;
    if(size == 0){
        cout<<"栈为空"<<endl;
        return false;
    }
    item = top->data;
    tmp = top->next;
    delete top;
    top = tmp;
    size--;
    return true;
}
int main(){
    lnkStack<int> l(10);
    l.push(5);
    int t;
    l.pop(t);
    cout<<t<<endl;
    return 0;
}
