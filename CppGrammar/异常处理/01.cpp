#include <iostream>

using namespace std;
int main(){
    cout<<"请输入两个数字"<<endl;
    int number1,number2;
    cin >>number1>>number2;
    try{
        if(number2==0)
            throw number2;
        cout<<number1<<"/"<<number2<<" is "<<(number1/number2)<<endl;
    }catch(int e){
        cout<<"Exception: an integer "<<e<<" cannot be divided by zero"<<endl;
    }
    cout<<"Exception contunues ...."<<endl;
}