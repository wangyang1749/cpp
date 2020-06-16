#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student
{
	char name[10];
	long num;
	float ch,math,en;
} STU;
int idx=0;
STU stu[100];

int main()
{
	void cjsr();
	void cjtj();
	void cjpx();
	void cjcx();

	int menu_main;

	while (1)
	{
		// system("cls");
		printf("               学生成绩管理系统\n");
		printf("           ----------------------\n");
		printf("              1---学生成绩输入\n");
		printf("              2---学生成绩统计\n");
		printf("              3---学生成绩排序\n");
		printf("              4---学生成绩查询\n");
		printf("              0---退出\n");
		printf("           ----------------------\n");
		printf("           请输入您的选择(0--4)：");
		scanf("%d",&menu_main);
		switch(menu_main)
		{
			case 0: printf("退出系统！\n"); exit(0);
			case 1: cjsr(); break;
			case 2: cjtj(); break;
			case 3: cjpx(); break;
			case 4: cjcx(); break;
			default: printf("菜单选择错误！\n");
		}
	}

}

void cjsr()
{
	char name[10];
    printf("可以输入多位学生的成绩，在一行内输入某一位学生的姓名以及语文、数学、英语的成绩（以姓名输入0 结束输入）：\n");
	while (1)
	{
		printf("%3d号:",idx+1); //第几号学生
		scanf("%s",name);
		if (name[0]=='0')
			break;
		stu[idx].num=idx+1;
		strcpy(stu[idx].name ,name);
		printf("输入%d号的成绩:",idx+1); //第几号学生
		scanf(" %f %f %f",&stu[idx].ch ,&stu[idx].math ,&stu[idx].en );
		idx++;
	}

}

// 成绩统计
void cjtj()
{
	void xstj();
	void kctj();
	int option;
	while (1){
		printf("\n学生成绩统计\n");
		printf("----------------------\n");
		printf("1---统计每位学生的总分\n");
		printf("2---统计每门课的平均分\n");
		printf("0---返回\n");
		printf("请选择(0--2)：");
		scanf("%d",&option);
		if(option ==0){
			break;
		}else if(option ==1){
			xstj();
		}else if(option ==2){
			kctj();
		}else{
			printf("输入有误！");
		}
	}
}

// 学生总分
void xstj()
{
	int i; 
	printf("===学生总分===\n");
	for(i=0;i<idx;i++){
		printf("姓名%s ：总分%f \n",stu[i].name,stu[i].ch+stu[i].math+stu[i].en);
	}
}

// 课程平均分
void kctj()
{
	int i; 
	float ch,math,en;
	printf("====课程平均分====\n");
	

	for(i=0;i<idx;i++){
		ch += stu[i].ch;
		math += stu[i].math;
		en += stu[i].en;
	}
	printf("语文平均分：%f 数学平均分：%f 英语平均分：%f\n",ch/idx,math/idx,en/idx);
}

void swap(STU *a,STU *b){
    STU temp = *a;
    *a = *b;
    *b = temp;
}

// 成绩排序
void cjpx()
{
	int option;
	int i;
	while (1){
		printf("\n学生成绩统计\n");
		printf("----------------------\n");
		printf("1---按课程排序\n");
		printf("2---按学生总分排序\n");
		printf("0---返回\n");
		printf("请选择(0--2)：");
		scanf("%d",&option);
		if(option ==0){
			break;
		}else if (option == 1){
			int kemu;
			while (1){
				printf("\n按科目排序\n");
				printf("----------------------\n");
				printf("1---按语文排序\n");
				printf("2---按数学排序\n");
				printf("3---按英语排序\n");
				printf("0---返回\n");
				printf("请选择(0--3)：");
				scanf("%d",&kemu);
				if (kemu==0){
					break;
				}else if (kemu==1){
					//按照语文排序
					int n = idx+1;
					int sorted = 1;
					while (sorted==1)
					{
						sorted = 0;
						n = n-1;
						for(i = 0;i<n;i++){
							if(stu[i-1].ch>stu[i].ch){
								swap(&stu[i-1],&stu[i]);
								sorted=1;
							}
						}
					}
					for(i=0;i<idx;i++){
						printf("姓名%s 学号%ld 语文%f 数学%f 英语 %f\n",stu[i].name,stu[i].num,stu[i].ch,stu[i].math,stu[i].en);//ch,math,en
					}
					
					
				}else if (kemu==2){
					//按照数学排序
					int n = idx+1;
					int sorted = 1;
					while (sorted==1)
					{
						sorted = 0;
						n = n-1;
						for(i = 0;i<n;i++){
							if(stu[i-1].math>stu[i].math){
								swap(&stu[i-1],&stu[i]);
								sorted=1;
							}
						}
					}
					for(i=0;i<idx;i++){
						printf("姓名%s 学号%ld 语文%f 数学%f 英语 %f\n",stu[i].name,stu[i].num,stu[i].ch,stu[i].math,stu[i].en);//ch,math,en
					}
					
				}else if (kemu==3){
					//按照英语排序
					int n = idx+1;
					int sorted = 1;
					while (sorted==1)
					{
						sorted = 0;
						n = n-1;
						for(i = 0;i<n;i++){
							if(stu[i-1].en>stu[i].en){
								swap(&stu[i-1],&stu[i]);
								sorted=1;
							}
						}
					}
					for(i=0;i<idx;i++){
						printf("姓名%s 学号%ld 语文%f 数学%f 英语 %f\n",stu[i].name,stu[i].num,stu[i].ch,stu[i].math,stu[i].en);//ch,math,en
					}
				}
				
				
				
			}
		}else if (option == 2){
			int n = idx+1;
			int sorted = 1;
			int i;
			while (sorted==1)
			{
				sorted = 0;
				n = n-1;
				for(i = 0;i<n;i++){
					float zfb = stu[i-1].ch + stu[i-1].math + stu[i-1].en; //前一个总分
					float zfa = stu[i].ch + stu[i].math + stu[i].en; //后一个总分
					if(zfb>zfa){
						swap(&stu[i-1],&stu[i]);
						sorted=1;
					}
				}
			}
			for(i=0;i<idx;i++){
				printf("姓名%s 学号%ld 语文%f 数学%f 英语%f 总分%f \n ",stu[i].name,stu[i].num,stu[i].ch,stu[i].math,stu[i].en,stu[i].ch+stu[i].math+stu[i].en);//ch,math,en
			}
		}
	}
}

// 成绩查询
void cjcx(){
	int option;
	int i;
	while (1){
		printf("\n成绩查询\n");
		printf("----------------------\n");
		printf("1---按照课程查询\n");
		printf("2---按照学生查询\n");
		printf("0---返回\n");
		printf("请选择(0--2)：");
		scanf("%d",&option);
		if(option ==0){
			break;
		}else if (option == 1){
			int optinKm;
			while (1){
				printf("\n按科目查询\n");
				printf("----------------------\n");
				printf("1---按语文查询\n");
				printf("2---按数学查询\n");
				printf("3---按英语查询\n");
				printf("0---返回\n");
				printf("请选择(0--3)：");
				scanf("%d",&optinKm);
				if (optinKm==0){
					break;
				}else if(optinKm == 1){
					for(i=0;i<idx;i++){
						printf("姓名%s 学号%ld 语文%f\n",stu[i].name,stu[i].num,stu[i].ch);//ch,math,en
					}
				}else if(optinKm == 2){
					for(i=0;i<idx;i++){
						printf("姓名%s 学号%ld 数学%f \n",stu[i].name,stu[i].num,stu[i].math);//ch,math,en
					}
				}else if(optinKm == 3){
					for(i=0;i<idx;i++){
						printf("姓名%s 学号%ld 英语 %f\n",stu[i].name,stu[i].num,stu[i].en);//ch,math,en
					}
				}
			}

		}else if (option == 2){
			int optionXs;
			int i;
			while (1){
				printf("\n按学生查询\n");
				printf("----------------------\n");
				printf("1---按照学号查询\n");
				printf("2---按照姓名查询\n");
				printf("0---返回\n");
				printf("请选择(0--2)：");
				scanf("%d",&optionXs);
				if(optionXs == 0) {
					break;
				}else if (optionXs==1){
					long num;
					while (1){
						printf("请输入学号（0 结束输入）:");
						scanf("%ld",&num);
						if (num == 0)
							break;
						//按照学号
						for(i=0;i<idx;i++){
							if(stu[i].num == num){
								printf("姓名%s 学号%ld 语文%f 数学%f 英语 %f\n",stu[i].name,stu[i].num,stu[i].ch,stu[i].math,stu[i].en);//ch,math,en
							}
						}
					}
				}else if (optionXs==2){
					char name[10];
					while (1){
						printf("请输入学生姓名（0 结束输入）:");
						scanf("%s",name);
						if (name[0]=='0')
							break;
						//按照姓名
						for(i=0;i<idx;i++){
							if(strcmp(stu[i].name,name)==0){
								printf("姓名%s 学号%ld 语文%f 数学%f 英语 %f\n",stu[i].name,stu[i].num,stu[i].ch,stu[i].math,stu[i].en);//ch,math,en
							}
						}
					}
				}

			}
		}	
	}
}

