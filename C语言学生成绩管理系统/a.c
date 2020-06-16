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
		printf("               ѧ���ɼ�����ϵͳ\n");
		printf("           ----------------------\n");
		printf("              1---ѧ���ɼ�����\n");
		printf("              2---ѧ���ɼ�ͳ��\n");
		printf("              3---ѧ���ɼ�����\n");
		printf("              4---ѧ���ɼ���ѯ\n");
		printf("              0---�˳�\n");
		printf("           ----------------------\n");
		printf("           ����������ѡ��(0--4)��");
		scanf("%d",&menu_main);
		switch(menu_main)
		{
			case 0: printf("�˳�ϵͳ��\n"); exit(0);
			case 1: cjsr(); break;
			case 2: cjtj(); break;
			case 3: cjpx(); break;
			case 4: cjcx(); break;
			default: printf("�˵�ѡ�����\n");
		}
	}

}

void cjsr()
{
	char name[10];
    printf("���������λѧ���ĳɼ�����һ��������ĳһλѧ���������Լ����ġ���ѧ��Ӣ��ĳɼ�������������0 �������룩��\n");
	while (1)
	{
		printf("%3d��:",idx+1); //�ڼ���ѧ��
		scanf("%s",name);
		if (name[0]=='0')
			break;
		stu[idx].num=idx+1;
		strcpy(stu[idx].name ,name);
		printf("����%d�ŵĳɼ�:",idx+1); //�ڼ���ѧ��
		scanf(" %f %f %f",&stu[idx].ch ,&stu[idx].math ,&stu[idx].en );
		idx++;
	}

}

// �ɼ�ͳ��
void cjtj()
{
	void xstj();
	void kctj();
	int option;
	while (1){
		printf("\nѧ���ɼ�ͳ��\n");
		printf("----------------------\n");
		printf("1---ͳ��ÿλѧ�����ܷ�\n");
		printf("2---ͳ��ÿ�ſε�ƽ����\n");
		printf("0---����\n");
		printf("��ѡ��(0--2)��");
		scanf("%d",&option);
		if(option ==0){
			break;
		}else if(option ==1){
			xstj();
		}else if(option ==2){
			kctj();
		}else{
			printf("��������");
		}
	}
}

// ѧ���ܷ�
void xstj()
{
	int i; 
	printf("===ѧ���ܷ�===\n");
	for(i=0;i<idx;i++){
		printf("����%s ���ܷ�%f \n",stu[i].name,stu[i].ch+stu[i].math+stu[i].en);
	}
}

// �γ�ƽ����
void kctj()
{
	int i; 
	float ch,math,en;
	printf("====�γ�ƽ����====\n");
	

	for(i=0;i<idx;i++){
		ch += stu[i].ch;
		math += stu[i].math;
		en += stu[i].en;
	}
	printf("����ƽ���֣�%f ��ѧƽ���֣�%f Ӣ��ƽ���֣�%f\n",ch/idx,math/idx,en/idx);
}

void swap(STU *a,STU *b){
    STU temp = *a;
    *a = *b;
    *b = temp;
}

// �ɼ�����
void cjpx()
{
	int option;
	int i;
	while (1){
		printf("\nѧ���ɼ�ͳ��\n");
		printf("----------------------\n");
		printf("1---���γ�����\n");
		printf("2---��ѧ���ܷ�����\n");
		printf("0---����\n");
		printf("��ѡ��(0--2)��");
		scanf("%d",&option);
		if(option ==0){
			break;
		}else if (option == 1){
			int kemu;
			while (1){
				printf("\n����Ŀ����\n");
				printf("----------------------\n");
				printf("1---����������\n");
				printf("2---����ѧ����\n");
				printf("3---��Ӣ������\n");
				printf("0---����\n");
				printf("��ѡ��(0--3)��");
				scanf("%d",&kemu);
				if (kemu==0){
					break;
				}else if (kemu==1){
					//������������
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
						printf("����%s ѧ��%ld ����%f ��ѧ%f Ӣ�� %f\n",stu[i].name,stu[i].num,stu[i].ch,stu[i].math,stu[i].en);//ch,math,en
					}
					
					
				}else if (kemu==2){
					//������ѧ����
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
						printf("����%s ѧ��%ld ����%f ��ѧ%f Ӣ�� %f\n",stu[i].name,stu[i].num,stu[i].ch,stu[i].math,stu[i].en);//ch,math,en
					}
					
				}else if (kemu==3){
					//����Ӣ������
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
						printf("����%s ѧ��%ld ����%f ��ѧ%f Ӣ�� %f\n",stu[i].name,stu[i].num,stu[i].ch,stu[i].math,stu[i].en);//ch,math,en
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
					float zfb = stu[i-1].ch + stu[i-1].math + stu[i-1].en; //ǰһ���ܷ�
					float zfa = stu[i].ch + stu[i].math + stu[i].en; //��һ���ܷ�
					if(zfb>zfa){
						swap(&stu[i-1],&stu[i]);
						sorted=1;
					}
				}
			}
			for(i=0;i<idx;i++){
				printf("����%s ѧ��%ld ����%f ��ѧ%f Ӣ��%f �ܷ�%f \n ",stu[i].name,stu[i].num,stu[i].ch,stu[i].math,stu[i].en,stu[i].ch+stu[i].math+stu[i].en);//ch,math,en
			}
		}
	}
}

// �ɼ���ѯ
void cjcx(){
	int option;
	int i;
	while (1){
		printf("\n�ɼ���ѯ\n");
		printf("----------------------\n");
		printf("1---���տγ̲�ѯ\n");
		printf("2---����ѧ����ѯ\n");
		printf("0---����\n");
		printf("��ѡ��(0--2)��");
		scanf("%d",&option);
		if(option ==0){
			break;
		}else if (option == 1){
			int optinKm;
			while (1){
				printf("\n����Ŀ��ѯ\n");
				printf("----------------------\n");
				printf("1---�����Ĳ�ѯ\n");
				printf("2---����ѧ��ѯ\n");
				printf("3---��Ӣ���ѯ\n");
				printf("0---����\n");
				printf("��ѡ��(0--3)��");
				scanf("%d",&optinKm);
				if (optinKm==0){
					break;
				}else if(optinKm == 1){
					for(i=0;i<idx;i++){
						printf("����%s ѧ��%ld ����%f\n",stu[i].name,stu[i].num,stu[i].ch);//ch,math,en
					}
				}else if(optinKm == 2){
					for(i=0;i<idx;i++){
						printf("����%s ѧ��%ld ��ѧ%f \n",stu[i].name,stu[i].num,stu[i].math);//ch,math,en
					}
				}else if(optinKm == 3){
					for(i=0;i<idx;i++){
						printf("����%s ѧ��%ld Ӣ�� %f\n",stu[i].name,stu[i].num,stu[i].en);//ch,math,en
					}
				}
			}

		}else if (option == 2){
			int optionXs;
			int i;
			while (1){
				printf("\n��ѧ����ѯ\n");
				printf("----------------------\n");
				printf("1---����ѧ�Ų�ѯ\n");
				printf("2---����������ѯ\n");
				printf("0---����\n");
				printf("��ѡ��(0--2)��");
				scanf("%d",&optionXs);
				if(optionXs == 0) {
					break;
				}else if (optionXs==1){
					long num;
					while (1){
						printf("������ѧ�ţ�0 �������룩:");
						scanf("%ld",&num);
						if (num == 0)
							break;
						//����ѧ��
						for(i=0;i<idx;i++){
							if(stu[i].num == num){
								printf("����%s ѧ��%ld ����%f ��ѧ%f Ӣ�� %f\n",stu[i].name,stu[i].num,stu[i].ch,stu[i].math,stu[i].en);//ch,math,en
							}
						}
					}
				}else if (optionXs==2){
					char name[10];
					while (1){
						printf("������ѧ��������0 �������룩:");
						scanf("%s",name);
						if (name[0]=='0')
							break;
						//��������
						for(i=0;i<idx;i++){
							if(strcmp(stu[i].name,name)==0){
								printf("����%s ѧ��%ld ����%f ��ѧ%f Ӣ�� %f\n",stu[i].name,stu[i].num,stu[i].ch,stu[i].math,stu[i].en);//ch,math,en
							}
						}
					}
				}

			}
		}	
	}
}

