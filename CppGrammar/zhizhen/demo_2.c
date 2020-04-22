/**
 * 指针 point *， 保存地址变量，指向一个变量的地址
 * https://www.icourse163.org/learn/ZJU-1001614008?tid=1003007003#/learn/content?type=detail&id=1004237422&cid=1005256135&replay=true
 * 2020 4 22
 * int *p,q; *是一个int，没有int* int* p;
 * void f(int *p); 
 * int i = 0; f(&i);
 *  
 * 访问地址变量 * 可以作为左值，也可以作为右值
 * 
 * 2020 4 22
 **/
#include <stdio.h>
void f(int *p);
void g(int k);

int main(){
    int i = 6;
    printf("i=%p\n",&i);
    f(&i);
    g(i);
    return 0;
}

void f(int *p){
    printf("p= %p\n",p);
    printf("p= %d\n",*p);
    *p=88;
}
void g(int k){
    printf("k=%d",k);
}


