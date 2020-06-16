#include <stdio.h>
int main(){
    FILE* fp = fopen("01.txt","r");
    if(fp){
        int num;
        fscanf(fp,"%d",&num);
        printf("%d\n",num);
        fclose(fp);
    }else
    {
        printf("无法打开文件！");
    }
    
    return 0;
}