#include <stdio.h>
// #include<conio.h>
#include <stdlib.h>
#include <string.h>
struct stu_type
{
  char num[15];  // ѧ��
  char name[10]; // ����
  int age;       // ����
  int c;         // C���Է���
  int math;      // ��ѧ����
  int en;        // Ӣ�����
  int sum;       // �ܷ�
  float ave;     // ƽ����
};
int stu_num;           // �������ѧ������
struct stu_type stu[]; // ѧ������
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
    printf("\n                 ��ӭʹ��ѧ����Ϣ����ϵͳ\n");
    printf("-----------------------------------------------------------------\n");
    printf("\n 1.���ѧ����Ϣ            2.��ʾѧ����Ϣ\n");
    printf("\n 3.�޸�ѧ����Ϣ            4.ɾ��ѧ����Ϣ\n");
    printf("\n 5.����ѧ����Ϣ            6.ͳ�Ʋ�������������߷ֺ�ƽ����\n");
    printf("\n 7.���ܷ�����              8.�������ļ�(�ı���ʽ)\n");
    printf("\n 9.���ļ�����(�ı���ʽ)    10.�������ļ�(�����Ʒ�ʽ)\n");
    printf("\n 11.���ļ�����(�����Ʒ�ʽ) 12.�˳�����\n");
    printf("\n----------------------------------------------------------------\n");
    printf("\n��ѡ����ģ�飬����1-12��");
    while (1)
    {
      scanf("%d", &choice);
      if (choice >= 1 && choice <= 12)
        break;

      printf("�������ֲ���ȷ������������1-12��");
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
  printf("˵����һ������ѧ����Ϣ���������ѧ��Ϊ0ʱ��ʾ�������\n");
  while (1)
  {
    printf("�������%d��ѧ������Ϣ\n", i + 1);
    printf("������ѧ�ţ�");
    scanf("%s", stu[i].num);
    if (strcmp(stu[i].num, "0") == 0)
      break;
    printf("������������");
    scanf("%s", stu[i].name);
    printf("���������䣺");
    scanf("%d", &stu[i].age);
    printf("������C���Գɼ���");
    scanf("%d", &stu[i].c);
    printf("��������ѧ�ɼ���");
    scanf("%d", &stu[i].math);
    printf("������Ӣ��ɼ���");
    scanf("%d", &stu[i].en);
    stu[i].sum = stu[i].c + stu[i].math + stu[i].en;
    stu[i].ave = (float)stu[i].sum / 3;
    i++;
  }
  stu_num = i;
  printf("�ܹ�����%d��ѧ������Ϣ\n", stu_num);
}

int display(char str[])
{
  int i, k = -1;
  if (strlen(str) == 0)
  {
    if (stu_num > 0)
    {
      printf("ѧ��ѧ��\t����\t����\tC����\t��ѧ\tӢ��\t�ܷ�\tƽ����\n");
      for (i = 0; i < stu_num; i++)
        printf("%-16s%s\t%d\t%d\t%d\t%d\t%d\t%5.1f\n", stu[i].num, stu[i].name, stu[i].age, stu[i].c, stu[i].math, stu[i].en, stu[i].sum, stu[i].ave);
    }
    else
      printf("ѧ����ϢΪ�գ�");
  }
  else
  {
    for (i = 0; i < stu_num; i++)
      if (strcmp(str, stu[i].num) == 0)
      {
        printf("ѧ��ѧ��\t����\t����\tC����\t��ѧ\tӢ��\t�ܷ�\tƽ����\n");
        printf("%-16s%s\t%d\t%d\t%d\t%d\t%d\t%5.1f\n", stu[i].num, stu[i].name, stu[i].age, stu[i].c, stu[i].math, stu[i].en, stu[i].sum, stu[i].ave);
        k = i;
      }
    if (k == -1)
      printf("û���ҵ�����������ѧ��\n");
  }
  return k;
}

void modify()
{
  char str[15], m;
  int i;
  printf("������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
  scanf("%s", str);
  i = display(str);
  if (i != -1)
  {
    printf("ȷ���޸ĸ�ѧ������Ϣ�𣿣�y/n��:");
    m = getche();
    if (m == 'y' || m == 'Y')
    {
      printf("\n�����������ѧ������Ϣ\n");
      printf("������ѧ�ţ�");
      scanf("%s", stu[i].num);
      printf("������������");
      scanf("%s", stu[i].name);
      printf("���������䣺");
      scanf("%d", &stu[i].age);
      printf("������C���Գɼ���");
      scanf("%d", &stu[i].c);
      printf("��������ѧ�ɼ���");
      scanf("%d", &stu[i].math);
      printf("������Ӣ��ɼ���");
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
  printf("������Ҫɾ����ѧ��ѧ�ţ�");
  scanf("%s", str);
  i = display(str);
  if (i != -1)
  {
    printf("ȷ��ɾ����ѧ������Ϣ�𣿣�y/n��:");
    m = getche();
    if (m == 'y' || m == 'Y')
    {
      stu_num--;
      for (j = i; j < stu_num; j++)
        stu[j] = stu[j + 1];
      printf("\n��¼ɾ���ɹ���\n");
    }
  }
}

void find()
{
  char str[15];
  printf("������Ҫ���ҵ�ѧ��ѧ�ţ�");
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
  printf("       C����ͳ�ƽ�����£�\n");
  printf("����������\t��߷�\tƽ����\n");
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
  printf("���������£�\n");
  printf("����\tѧ��ѧ��\t����\t����\tC����\t��ѧ\tӢ��\t�ܷ�\tƽ����\n");
  for (i = 0; i < stu_num; i++)
    printf("%d\t%-16s%s\t%d\t%d\t%d\t%d\t%d\t%5.1f\n", i + 1, stu[i].num, stu[i].name, stu[i].age, stu[i].c, stu[i].math, stu[i].en, stu[i].sum, stu[i].ave);
}

void save_txt()
{
  FILE *fp;
  char fname[20];
  int i;
  printf("�������ļ������磺stu.txt����");
  scanf("%s", fname);
  if ((fp = fopen(fname, "w")) == NULL)
  {
    printf("���ܴ��ļ����ļ�����ʧ�ܣ�\n");
    return;
  }
  for (i = 0; i < stu_num; i++)
    fprintf(fp, "%s %s %d %d %d %d %d %5.2f\n", stu[i].num, stu[i].name, stu[i].age, stu[i].c, stu[i].math, stu[i].en, stu[i].sum, stu[i].ave);
  printf("�ļ�����ɹ���\n");
  fclose(fp);
}

void load_txt()
{
  FILE *fp;
  char fname[20];
  int i = 0, flag;
  printf("�������ļ������磺stu.txt����");
  scanf("%s", fname);
  if ((fp = fopen(fname, "r")) == NULL)
  {
    printf("���ܴ��ļ����ļ���ȡʧ�ܣ�\n");
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
  printf("���ļ��гɹ���ȡ%d����¼\n", i);
  fclose(fp);
}

void save_bin()
{
  FILE *fp;
  char fname[20];
  printf("�������ļ������磺stu.txt����");
  scanf("%s", fname);
  if ((fp = fopen(fname, "wb")) == NULL)
  {
    printf("���ܴ��ļ����ļ�����ʧ�ܣ�\n");
    return;
  }
  fwrite(stu, sizeof(struct stu_type), stu_num, fp);
  printf("�ļ�����ɹ���\n");
  fclose(fp);
}

void load_bin()
{
  FILE *fp;
  char fname[20];
  int i = 0, flag;
  printf("�������ļ������磺stu.txt����");
  scanf("%s", fname);
  if ((fp = fopen(fname, "rb")) == NULL)
  {
    printf("���ܴ��ļ����ļ���ȡʧ�ܣ�\n");
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
  printf("���ļ��гɹ���ȡ%d����¼\n", i);
  fclose(fp);
}
