#include <stdio.h>
void swap(int *a,int *b);
int main()
{
    int stu[] = {1, 2, 5, 6, 2, 6};
    int n = 6;
    int sorted = 1;
    while (sorted == 1)
    {
        sorted = 0;
        n = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (stu[i - 1] > stu[i])
            {
                swap(&stu[i - 1], &stu[i]);
                sorted = 1;
            }
        }
    }



    for (int i = 0;i<6;i++){
        printf("%d\n",stu[i]);
    }
}

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}



