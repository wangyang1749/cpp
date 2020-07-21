#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

//以下是类的设计
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
	cout<<number<<"\t"<<name<<"\t"<<(sex?"男":"女")<<"\t"<<age<<"\t"<<classes;
}
void Student::input(){
		cout<<"输入学号:";
	cin>>number;
	cout<<"输入姓名:";
	cin>>name;
	cout<<"输入姓名:";
	cin>>name;
	cout<<"输入性别(0:男 1:女):";
	cin>>sex;
	cout<<"输入年龄:";
	cin>>age;
	cout<<"输入班级:";
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


//以下是对象或对象数组的定义
Pupil pupil[50];
int pupilCount=0;
Middle middle[50];
College clooege[50];

//输入小学生
void inputPupile(){
	cout<<"输入学号:";
	cin>>pupil[pupilCount].number;
	for(int i=0;i<pupilCount;i++){
		if(pupil[i].number==pupil[pupilCount].number){
			cout<<"学生学号已经存在不能重复添加"<<endl;
			return;
		}
	}
	cout<<"输入姓名:";
	cin>>pupil[pupilCount].name;
	cout<<"输入姓名:";
	cin>>pupil[pupilCount].name;
	cout<<"输入性别(0:男 1:女):";
	cin>>pupil[pupilCount].sex;
	cout<<"输入年龄:";
	cin>>pupil[pupilCount].age;
	cout<<"输入班级:";
	cin>>pupil[pupilCount].classes;
	
}
//显示小学生
void showPupile(){
	for(int i=0;i<pupilCount;i++){
		pupil[i].toString();
	}
}
//统计小学生
void statistic(){

}


//读取数据
void read(){

}
//保存所有数据
void save(){

}




//以下是主函数
int main()
{
	Student stu;
	stu.input();

	// int flag=1,operate;
	// do
	// {
	// 	cout<<"                   ★★学生信息管理系统★★\n";
	// 	cout<<"                ┌─────────────┐\n";
	// 	cout<<"                │    请选择您所需的操作    │\n";
	// 	cout<<"                │  数据输入：1，并按回车键 │\n";
	// 	cout<<"                │  数据显示：2，并按回车键 │\n";
	// 	cout<<"                │  数据统计：3，并按回车键 │\n";
	// 	cout<<"                │  数据保存：4，并按回车键 │\n";
	// 	cout<<"                │  退出系统：5，并按回车键 │\n";
	// 	cout<<"                └─────────────┘\n";
	// 	cout<<"                      请选择一个操作:   ";
	// 	cin>>operate;
	// 	switch(operate)
	// 	{
	// 	case 1:
	// 		cout<<"请输入数据："<<endl;
	// 		{
	// 			cout<<"正在输入数据......"<<endl;
	// 			//在此添加代码，完成数据输入功能
	// 		}
	// 		break;
			
	// 	case 2:
	// 		cout<<"请等待......."<<endl;
	// 		{
	// 			cout<<"正在进行数据统计......"<<endl;
	// 			//在此添加代码，完成数据统计功能
	// 		}
	// 		break;
			
	// 	case 3:
	// 		cout<<"请等待........"<<endl;
	// 		{
	// 			cout<<"正在进行数据打印......"<<endl;
	// 			//在此添加代码，完成数据打印功能
	// 		};
	// 		break;
			
	// 	case 4:
	// 		cout<<"请等待........"<<endl;
	// 		{
	// 			cout<<"正在进行数据保存......"<<endl;
	// 			//在此添加代码，完成数据保存功能
	// 		}
	// 		break;
	// 	case 5:
	// 		exit(0);//强制结束程序运行！
	// 		break;
	// 	default:
	// 		cout<<"输入错误，请重新1-5间的输入"<<endl;
	// 		break;
	// 	}
	// }while(1);

	return 0;
}