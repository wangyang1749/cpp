/**
 * 指针与const
 * 指针不能修改 const在*之后
 * 通过指针不能修改 const在*之前
 * 2020 4 22
 **/
#include <stdio.h>

int main(){
    int i;
    int * const q = &i; //指针q不能再指向其它变量
    *q = 26; //OK
    // q++; Error 不能进行指针运算

    int j;
    const int *p2 = &i; //不能通过指针修改变量
    p2++; //Ok
    i = 50;// i可以修改
    p2 = &j; // p2可以指向其它变量
    
    return 0;
}



