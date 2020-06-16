#include <stdio.h>

int main()
{
    int a[8] = {3, 2, 5, 8, 4, 7, 6, 9};
    for (int i = 0; i <8; i++)
    {
        for (int j = 0; j < 8 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 8; i++)
    {
        printf("%5d \n", a[i]);
    }
}