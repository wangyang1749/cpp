#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

//������������
class Student
{
 public:
	 double number;
	 double age;
	 int classes;
	 string name;
	 int sex;
	 void toString();
	 void input();
};
void Student::toString(){
	cout<<number<<"\t"<<name<<"\t"<<(sex?"��":"Ů")<<"\t"<<age<<"\t"<<classes;
}
void Student::input(){
		cout<<"����ѧ��:";
	cin>>number;
	cout<<"��������:";
	cin>>name;
	cout<<"��������:";
	cin>>name;
	cout<<"�����Ա�(0:�� 1:Ů):";
	cin>>sex;
	cout<<"��������:";
	cin>>age;
	cout<<"����༶:";
	cin>>classes;
}
class Pupil:public Student
{
  public:
	  double English;
	  double maths;
	  double Chinese;
};
class Middle:public Pupil
{
  public:
	  double geography;
      double history;
	  string address;
};
class College:public Student
{
  public:
	  string major;
	  string home;
	  double contact;
};


//�����Ƕ�����������Ķ���
Pupil pupil[50];
int pupilCount=0;
Middle middle[50];
College clooege[50];

//����Сѧ��
void inputPupile(){
	cout<<"����ѧ��:";
	cin>>pupil[pupilCount].number;
	for(int i=0;i<pupilCount;i++){
		if(pupil[i].number==pupil[pupilCount].number){
			cout<<"ѧ��ѧ���Ѿ����ڲ����ظ����"<<endl;
			return;
		}
	}
	cout<<"��������:";
	cin>>pupil[pupilCount].name;
	cout<<"��������:";
	cin>>pupil[pupilCount].name;
	cout<<"�����Ա�(0:�� 1:Ů):";
	cin>>pupil[pupilCount].sex;
	cout<<"��������:";
	cin>>pupil[pupilCount].age;
	cout<<"����༶:";
	cin>>pupil[pupilCount].classes;
	
}
//��ʾСѧ��
void showPupile(){
	for(int i=0;i<pupilCount;i++){
		pupil[i].toString();
	}
}
//ͳ��Сѧ��
void statistic(){

}


//��ȡ����
void read(){

}
//������������
void save(){

}




//������������
int main()
{
	Student stu;
	stu.input();

	// int flag=1,operate;
	// do
	// {
	// 	cout<<"                   ���ѧ����Ϣ����ϵͳ���\n";
	// 	cout<<"                ������������������������������\n";
	// 	cout<<"                ��    ��ѡ��������Ĳ���    ��\n";
	// 	cout<<"                ��  �������룺1�������س��� ��\n";
	// 	cout<<"                ��  ������ʾ��2�������س��� ��\n";
	// 	cout<<"                ��  ����ͳ�ƣ�3�������س��� ��\n";
	// 	cout<<"                ��  ���ݱ��棺4�������س��� ��\n";
	// 	cout<<"                ��  �˳�ϵͳ��5�������س��� ��\n";
	// 	cout<<"                ������������������������������\n";
	// 	cout<<"                      ��ѡ��һ������:   ";
	// 	cin>>operate;
	// 	switch(operate)
	// 	{
	// 	case 1:
	// 		cout<<"���������ݣ�"<<endl;
	// 		{
	// 			cout<<"������������......"<<endl;
	// 			//�ڴ���Ӵ��룬����������빦��
	// 		}
	// 		break;
			
	// 	case 2:
	// 		cout<<"��ȴ�......."<<endl;
	// 		{
	// 			cout<<"���ڽ�������ͳ��......"<<endl;
	// 			//�ڴ���Ӵ��룬�������ͳ�ƹ���
	// 		}
	// 		break;
			
	// 	case 3:
	// 		cout<<"��ȴ�........"<<endl;
	// 		{
	// 			cout<<"���ڽ������ݴ�ӡ......"<<endl;
	// 			//�ڴ���Ӵ��룬������ݴ�ӡ����
	// 		};
	// 		break;
			
	// 	case 4:
	// 		cout<<"��ȴ�........"<<endl;
	// 		{
	// 			cout<<"���ڽ������ݱ���......"<<endl;
	// 			//�ڴ���Ӵ��룬������ݱ��湦��
	// 		}
	// 		break;
	// 	case 5:
	// 		exit(0);//ǿ�ƽ����������У�
	// 		break;
	// 	default:
	// 		cout<<"�������������1-5�������"<<endl;
	// 		break;
	// 	}
	// }while(1);

	return 0;
}