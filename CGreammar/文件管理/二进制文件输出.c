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

void getList(Student stu[],int number);
int save(Student stu[],int number);

int main(int argc,const int  *argv[]){
    int number = 0;
    printf("请输入学生数量：");
    scanf("%d",&number);
    Student stu[number];
    getList(stu,number);
    if(save(stu,number)){
        printf("保存成功\n");
    }else{
        printf("保存失败\n");
    }
    
    
}
void getList(Student stu[],int number){
    char format[STR_LEN];
    sprintf(format,"%%%ds",STR_LEN-1); //%19s格式字符串
    int i;
    for (i=0;i<number;i++){
        printf("第%d个学生:\n",i);
        printf("\t姓名:");
        scanf(format,stu[i].name);
        printf("\t性别(0-男，1-女)：");
        scanf("%d",&stu[i].gender);
        printf("\t年龄:");
        scanf("%d",&stu[i].age);
    }
}
int save(Student stu[],int number){
    int ret = -1;
    FILE *fp = fopen("Student.data","w");
    if(fp){
        ret = fwrite(stu,sizeof(Student),number,fp);
        fclose(fp);
    }
    return ret == number;
}