#include <stdio.h>

#ifndef _STUDNET_H_
#define _STUDNET_H_

const int STR_LEN = 20;
typedef struct _student
{
    char name[20];
    int gender;
    int age;
} Student;

#endif

void read(FILE *fp,int index);

int main(){
    FILE *fp = fopen("Student.data","r");
    if(fp){
        // 读写位置移动到从结尾开始倒数0L的位置，也就是文件末尾
        fseek(fp,0L,SEEK_END); 
        long size = ftell(fp);// 获取当前位置
        int number = size/sizeof(Student);
        int index = 0;
        printf("有%d个数据，你要看第几个：",number);
        scanf("%d",&index);
        read(fp,index-1);
        fclose(fp);
    }
    return 0;
}

void read(FILE *fp,int index){
    // 从文件的头部开始到相应的位置
    fseek(fp,index*sizeof(Student),SEEK_SET);
    Student stu;
    // stu读或写的内存 这块内存的大小 有几个这样的内存 文件指针
    if(fread(&stu,sizeof(Student),1,fp)==1){
        printf("第%d个学生：\n",index+1);
        printf("\t姓名：%s\n",stu.name);
        printf("\t性别：");
        switch (stu.gender)
        {
        case 0:
            printf("男\n");
            break;
        case 1:
            printf("女\n");
            break;
        }
        printf("\t年龄：%d\n",stu.age);
    }
}
