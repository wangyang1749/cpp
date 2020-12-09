#include <iostream>
using namespace std;

template <class T> // 栈的元素类型为 T
class Stack
{
public:						 // 栈的运算集
	void clear();			 // 变为空栈
	bool push(const T item); // item入栈，成功则返回真，否则返回假
	bool pop(T &item);		 // 返回栈顶内容并弹出，成功返回真，否则返回假,
	bool getTop(T &item);	 // 返回栈顶内容但不弹出成功返回真，否则返回假,
	bool isEmpty();			 // 若栈已空返回真
	bool isFull();			 // 若栈已满返回真
};

template <class T>
class arrStack : public Stack<T>
{
private:	   // 栈的顺序存储
	int mSize; // 栈中最多可存放的元素个数
	T *st;	   // 存放栈元素的数组
	int top;   // 栈顶位置，应小于mSize
public:		   // 栈的运算的顺序实现
	arrStack(int size);
	arrStack();
	~arrStack();
	void clear();
	bool push(const T item);
	bool pop(T &item);
	bool getTop(T *item);
	bool isEmpty();
	bool isFull();
	void print();
};
template <class T>
arrStack<T>::arrStack(){
	top = -1;
}
template <class T>
arrStack<T>::arrStack(int size){
	mSize = size;
	top = -1;
	st = new T[mSize];
}
template <class T>
arrStack<T>::~arrStack(){
	delete [] st;
}
template <class T>
bool arrStack<T>::push(const T item){
	if(top==mSize-1){
		cout<<"栈满溢出！"<<endl;
		return false;
	}else
	{
		st[++top] = item;
		return true;
	}
	
}
template <class T>
bool arrStack<T>::pop(T& item){
	if(top==-1){
		cout<<"栈为空"<<endl;
		return false;
	}else{
		item = st[top--];
		return true;
	}
}
template <class T>
void arrStack<T>::clear(){
	top = -1;
}

template <class T>
void arrStack<T>::print(){
	cout<<endl;
	cout<<"*************************"<<endl;
}

int main(){
	arrStack<int> as(10);
	as.push(1);
	int t;
	as.pop(t);
	cout<<t<<endl;
	as.print();
	return 0;
}