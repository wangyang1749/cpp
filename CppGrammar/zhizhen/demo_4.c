/**
 * 指针与数组
 * 数组是常量指针，两个数组之间不能赋值
 * 数组变量是特殊的指针
 * int a[10];int *p = a = &a[0]; //取地址不用&
 * int b = 10;int *p = &b; *p = p[0]
 * 数组单元取地址需要& 
 * 函数参数表里的数组就是指针
 * 以下四种原型是等价的
 * int sum(int *a,int n)
 * int sum(int *,int n)
 * int sum(int a[],int n)
 * int sum(int [],int n)
 * https://www.icourse163.org/learn/ZJU-1001614008?tid=1003007003#/learn/content?type=detail&id=1004237422&cid=1005256137&replay=true
 * 2020 4 22
 **/
#include <stdio.h>

void minmax(int a[],int len,int *max,int *min);
void minmax2(int *a,int len,int *max,int *min);

int main(){
    int c[] = {1,2,3,4,5};
    int min,max;
    minmax(c,sizeof(c)/sizeof(c[0]),&min,&max);
    printf("min=%d,max=%d\n",max,min);

    minmax2(c,sizeof(c)/sizeof(c[0]),&min,&max);
    printf("min=%d,max=%d\n",max,min);


    return 0;
}

/**
 * int a[] 就是指针，空的方括号
 * **/
void minmax(int a[],int len,int *max,int *min){
    *max=*min=a[0];
    for (int i = 0; i < len; i++)
    {
        if(a[i]<*min){
            *min = a[i];
        }

        if(a[i]>*max){
            *max = a[i];
        }
    }
}

/**
 * int *a 就是指针
 * **/
void minmax2(int *a,int len,int *max,int *min){
    *max=*min=a[0];
    for (int i = 0; i < len; i++)
    {
        if(a[i]<*min){
            *min = a[i];
        }

        if(a[i]>*max){
            *max = a[i];
        }
    }
}


