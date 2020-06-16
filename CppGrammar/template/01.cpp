//求两个整数、浮点数、字符的最大值？
#include <stdio.h>

int maxInt(int x,int y);
double maxDouble(double x, double y);
char maxChar(char x,char y);

int maxValue(const int& x,const int& y);
double maxValue(const double& x, const double& y);
char maxValue(const char& x,const char& y);

int maxValue(const int& x,const int& y){
    if(x>y)return x;
    return y;
}
double maxValue(const double& x, const double& y){
    if(x>y)return x;
    return y;
}
char maxValue(const char& x,const char& y){
    if(x>y)return x;
    return y;
}



int main(){
    printf("%d",maxValue(5,6));
    return 0;
}