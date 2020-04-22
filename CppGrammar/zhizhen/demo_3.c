/**
 * 指针案例
 * 函数返回多个值，某些值就只能通过指针返回
 * 传入的参数实际上是需要保存带会的结果变量
 * 
 * 2020 4 22
 **/
#include <stdio.h>

void swap(int *pa,int *pb);
// 计算最大值和最小值
void minmax(int a[],int len,int *max,int *min);
// 函数返回运算状态，结果通过指针返回
int divide(int a,int b,int *result);

int main(){
    int a=5,b=10;
    printf("a=%d,b=%d\n",a,b);
    swap(&a,&b);
    printf("a=%d,b=%d\n",a,b);

    int c[] = {1,2,3,4,5};
    int min,max;
    minmax(c,sizeof(c)/sizeof(c[0]),&min,&max);
    printf("min=%d,max=%d\n",max,min);


    int d;
    if(divide(a,b,&d)){
        printf("%d/%d=%d\n",a,b,d);
    }

    return 0;
}

void swap(int *pa,int *pb){
    int temp = *pa;
    *pa=*pb;
    *pb = temp;
}

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

int divide(int a,int b,int *result){
    int ret = 1;
    if(b==0) ret = 0;
    else{
        *result = a/b;
    }
    return ret;
}
