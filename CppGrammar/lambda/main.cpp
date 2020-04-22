#include <iostream>
using namespace std;
//这里使用auto自动判断类型  其实是函数指针
auto fun = [](int x, int y)->int {cout << x + y << endl; return y;};
int main(int argc,char **argv){
   [](){cout<<"Hello Word"<<endl;}();
   cout<<fun(1,2)<<endl;
   return 0;    					
}