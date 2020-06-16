#include <stdio.h>
int main()
{
    int i, j, t, n=8;
    // scanf("%d", &n);         //输入一个数n，表示接下来有n个数
    // for (i = 1; i <= n; i++) //循环读入n个数到数组a中
    //     scanf("%d", &a[i]);
    int a[8] = {3, 2, 5, 8, 4, 7, 6, 9};
    
    //冒泡排序的核心部分
    for (i = 0; i <= n; i++) //n个数排序，只用进行n-1趟
    {
        for (j = 0; j <= n - i; j++) //从第1位开始比较直到最后一个尚未归位的数，想一想为什么到n-i就可以了。
        {
            if (a[j] < a[j + 1]) //比较大小并交换
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    for (i = 1; i <= n; i++) //输出结果
        printf("%d \n", a[i]);

    return 0;
}
