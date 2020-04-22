/**
 * 运算符 &， 取出变量的地址
 * https://www.icourse163.org/learn/ZJU-1001614008?tid=1003007003#/learn/content?type=detail&id=1004237422
 * 2020 4 22
 * 
 **/
#include <stdio.h>

int main(){
    int i = 0;
    printf("%p\n",&i); //输出变量的地址

    int p = (int)&i;
    printf("0x%x\n",p);

    /**
     * 说明地址和int变量不总是相等
     **/
    printf("%lu \n",sizeof(int)); // 4 64位int是四个字节
    printf("%lu \n",sizeof(&i)); // 8 64位地址是8个字节  

    /**
     * 64位相邻变量的地址是紧挨着的8个字节之差
     * **/
    int a1;int a2;
    printf("%p\n",&a1); // 0x7ffe952dbf74
    printf("%p\n",&a2); // 0x7ffe952dbf78

    /**
     * 数组的地址
     * **/
    int d[10];
    printf("%p\n",&d); // 0x7ffe952dbf80
    printf("%p\n",d); // 0x7ffe952dbf80
    printf("%p\n",&d[0]); // 0x7ffe952dbf80
    printf("%p\n",&d[1]); // 0x7ffe952dbf84
    
}