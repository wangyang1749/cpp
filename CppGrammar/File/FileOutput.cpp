#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ofstream output{"02.txt"};
    
    double lileiScore{90.5};
    int hanmeiScore{84};
    output<<"lilei666666"<<lileiScore<<endl;
    output<<"hanmei"<<hanmeiScore<<endl;
    output.close();

    

    return 0;
}
