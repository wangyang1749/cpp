#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream input{"02.txt"};
    if(!input.fail()){
        char x;
        while(!input.get(x).eof()){
            // cout<<x;
            cout<<input.get()<<endl;
         
        }
    }
    input.close();
}