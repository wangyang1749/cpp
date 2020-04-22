#include <iostream>
#include <stdio.h>
void test1();
int main(int argc, char **argv)
{
    /**
     * argc : argument counter 参数计数器，即参数个数
     * argv：argument values 参数值，另有argument vectors，参数向量
     */
    // for (int i = 0; i < argc; i++)
    //     printf("Argument %d is %s\n", i, argv[i]);

    if(argc!=2){
        printf("please input argument! \n");
        // 返回-1，退出程序运行
        return -1;
    }

    test1();
    
    int n = std::stoi(argv[1]);

    for(int i=1;i<n;i<<=1){
        for(int j=0;j<i;j++){
            printf("i=%d,j=%d \n",i,j);
        }
    }
    // std::cout<<"Hello Word"<<std::endl;
    return 0;
}