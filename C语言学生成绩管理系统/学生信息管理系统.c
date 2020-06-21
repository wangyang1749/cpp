#include <stdio.h>
// #include<conio.h>
#include <stdlib.h>
#include <string.h>
struct stu_type
{
  char num[15];  // 学号
  char name[10]; // 姓名
  int age;       // 年龄
  int c;         // C语言分数
  int math;      // 数学分数
  int en;        // 英语分数
  int sum;       // 总分
  float ave;     // 平均分
};
int stu_num;           // 已输入的学生人数
struct stu_type stu[]; // 学生数组
void add();
int display(char str[]);
void modify();
void del();
void find();
void compute();
void sort();
void save_txt();
void load_txt();
void save_bin();
void load_bin();

void main()
{
  while (1)
  {
    int choice;
    printf("\n                 欢迎使用学生信息管理系统\n");
    printf("-----------------------------------------------------------------\n");
    printf("\n 1.添加学生信息            2.显示学生信息\n");
    printf("\n 3.修改学生信息            4.删除学生信息\n");
    printf("\n 5.查找学生信息            6.统计不及格人数、最高分和平均分\n");
    printf("\n 7.按总分排序              8.保存至文件(文本方式)\n");
    printf("\n 9.从文件读入(文本方式)    10.保存至文件(二进制方式)\n");
    printf("\n 11.从文件读入(二进制方式) 12.退出程序\n");
    printf("\n----------------------------------------------------------------\n");
    printf("\n请选择功能模块，输入1-12：");
    while (1)
    {
      scanf("%d", &choice);
      if (choice >= 1 && choice <= 12)
        break;

      printf("输入数字不正确，请重新输入1-12：");
    }
    switch (choice)
    {
    case 1:
      add();
      break;
    case 2:
      display("");
      break;
    case 3:
      modify();
      break;
    case 4:
      del();
      break;
    case 5:
      find();
      break;
    case 6:
      compute();
      break;
    case 7:
      sort();
      break;
    case 8:
      save_txt();
      break;
    case 9:
      load_txt();
      break;
    case 10:
      save_bin();
      break;
    case 11:
      load_bin();
      break;
    case 12:
      exit(0);
      break;
    }
  }
}

struct stu_type stu[100];
int stu_num = 0;
void add()
{
  int i = stu_num;
  printf("说明：一次输入学生信息，当输入的学号为0时表示输入结束\n");
  while (1)
  {
    printf("请输入第%d个学生的信息\n", i + 1);
    printf("请输入学号：");
    scanf("%s", stu[i].num);
    if (strcmp(stu[i].num, "0") == 0)
      break;
    printf("请输入姓名：");
    scanf("%s", stu[i].name);
    printf("请输入年龄：");
    scanf("%d", &stu[i].age);
    printf("请输入C语言成绩：");
    scanf("%d", &stu[i].c);
    printf("请输入数学成绩：");
    scanf("%d", &stu[i].math);
    printf("请输入英语成绩：");
    scanf("%d", &stu[i].en);
    stu[i].sum = stu[i].c + stu[i].math + stu[i].en;
    stu[i].ave = (float)stu[i].sum / 3;
    i++;
  }
  stu_num = i;
  printf("总共输入%d个学生的信息\n", stu_num);
}

int display(char str[])
{
  int i, k = -1;
  if (strlen(str) == 0)
  {
    if (stu_num > 0)
    {
      printf("学生学号\t姓名\t年龄\tC语言\t数学\t英语\t总分\t平均分\n");
      for (i = 0; i < stu_num; i++)
        printf("%-16s%s\t%d\t%d\t%d\t%d\t%d\t%5.1f\n", stu[i].num, stu[i].name, stu[i].age, stu[i].c, stu[i].math, stu[i].en, stu[i].sum, stu[i].ave);
    }
    else
      printf("学生信息为空！");
  }
  else
  {
    for (i = 0; i < stu_num; i++)
      if (strcmp(str, stu[i].num) == 0)
      {
        printf("学生学号\t姓名\t年龄\tC语言\t数学\t英语\t总分\t平均分\n");
        printf("%-16s%s\t%d\t%d\t%d\t%d\t%d\t%5.1f\n", stu[i].num, stu[i].name, stu[i].age, stu[i].c, stu[i].math, stu[i].en, stu[i].sum, stu[i].ave);
        k = i;
      }
    if (k == -1)
      printf("没有找到符合条件的学生\n");
  }
  return k;
}

void modify()
{
  char str[15], m;
  int i;
  printf("请输入要修改的学生学号：");
  scanf("%s", str);
  i = display(str);
  if (i != -1)
  {
    printf("确认修改该学生的信息吗？（y/n）:");
    m = getche();
    if (m == 'y' || m == 'Y')
    {
      printf("\n请重新输入该学生的信息\n");
      printf("请输入学号：");
      scanf("%s", stu[i].num);
      printf("请输入姓名：");
      scanf("%s", stu[i].name);
      printf("请输入年龄：");
      scanf("%d", &stu[i].age);
      printf("请输入C语言成绩：");
      scanf("%d", &stu[i].c);
      printf("请输入数学成绩：");
      scanf("%d", &stu[i].math);
      printf("请输入英语成绩：");
      scanf("%d", &stu[i].en);
      stu[i].sum = stu[i].c + stu[i].math + stu[i].en;
      stu[i].ave = (float)stu[i].sum / 3;
    }
  }
}

void del()
{
  char str[15], m;
  int i, j;
  printf("请输入要删除的学生学号：");
  scanf("%s", str);
  i = display(str);
  if (i != -1)
  {
    printf("确认删除该学生的信息吗？（y/n）:");
    m = getche();
    if (m == 'y' || m == 'Y')
    {
      stu_num--;
      for (j = i; j < stu_num; j++)
        stu[j] = stu[j + 1];
      printf("\n记录删除成功！\n");
    }
  }
}

void find()
{
  char str[15];
  printf("请输入要查找的学生学号：");
  scanf("%s", str);
  display(str);
}

void compute()
{
  int i, n = 0, max = 0, sum = 0;
  for (i = 0; i < stu_num; i++)
  {
    if (stu[i].c < 60)
      n++;
    if (max < stu[i].c)
      max = stu[i].c;
    sum = sum + stu[i].c;
  }
  printf("       C语言统计结果如下：\n");
  printf("不及格人数\t最高分\t平均分\n");
  printf("    %d    \t  %d  \t %5.2f\n", n, max, (float)sum / stu_num);
}

void sort()
{
  int i, j;
  struct stu_type temp;
  for (i = 1; i < stu_num; i++)
    for (j = 0; j < stu_num - i; j++)
      if (stu[j].sum < stu[j + 1].sum)
      {
        temp = stu[j];
        stu[j] = stu[j + 1];
        stu[j + 1] = temp;
      }
  printf("排序结果如下：\n");
  printf("名次\t学生学号\t姓名\t年龄\tC语言\t数学\t英语\t总分\t平均分\n");
  for (i = 0; i < stu_num; i++)
    printf("%d\t%-16s%s\t%d\t%d\t%d\t%d\t%d\t%5.1f\n", i + 1, stu[i].num, stu[i].name, stu[i].age, stu[i].c, stu[i].math, stu[i].en, stu[i].sum, stu[i].ave);
}

void save_txt()
{
  FILE *fp;
  char fname[20];
  int i;
  printf("请输入文件名（如：stu.txt）：");
  scanf("%s", fname);
  if ((fp = fopen(fname, "w")) == NULL)
  {
    printf("不能打开文件，文件保存失败！\n");
    return;
  }
  for (i = 0; i < stu_num; i++)
    fprintf(fp, "%s %s %d %d %d %d %d %5.2f\n", stu[i].num, stu[i].name, stu[i].age, stu[i].c, stu[i].math, stu[i].en, stu[i].sum, stu[i].ave);
  printf("文件保存成功！\n");
  fclose(fp);
}

void load_txt()
{
  FILE *fp;
  char fname[20];
  int i = 0, flag;
  printf("请输入文件名（如：stu.txt）：");
  scanf("%s", fname);
  if ((fp = fopen(fname, "r")) == NULL)
  {
    printf("不能打开文件，文件读取失败！\n");
    return;
  }
  while (1)
  {
    flag = fscanf(fp, "%s %s %d %d %d %d %d  %f\n", stu[i].num, stu[i].name, &stu[i].age, &stu[i].c, &stu[i].math, &stu[i].en, &stu[i].sum, &stu[i].ave);
    if (flag == EOF)
      break;
    i++;
  }
  stu_num = i;
  printf("从文件中成功读取%d条记录\n", i);
  fclose(fp);
}

void save_bin()
{
  FILE *fp;
  char fname[20];
  printf("请输入文件名（如：stu.txt）：");
  scanf("%s", fname);
  if ((fp = fopen(fname, "wb")) == NULL)
  {
    printf("不能打开文件，文件保存失败！\n");
    return;
  }
  fwrite(stu, sizeof(struct stu_type), stu_num, fp);
  printf("文件保存成功！\n");
  fclose(fp);
}

void load_bin()
{
  FILE *fp;
  char fname[20];
  int i = 0, flag;
  printf("请输入文件名（如：stu.txt）：");
  scanf("%s", fname);
  if ((fp = fopen(fname, "rb")) == NULL)
  {
    printf("不能打开文件，文件读取失败！\n");
    return;
  }
  while (1)
  {
    flag = fread(&stu[i], sizeof(struct stu_type), 1, fp);
    if (flag == 0)
      break;
    i++;
  }
  stu_num = i;
  printf("从文件中成功读取%d条记录\n", i);
  fclose(fp);
}
