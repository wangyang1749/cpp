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
void Student::toString()
{

	cout << number << "\t" << name << "\t" << (sex ? "男" : "女") << "\t" << age << "\t" << classes << endl;
}
void Student::input()
{
	cout << "输入学号:";
	cin >> number;
	cout << "输入姓名:";
	cin >> name;
	cout << "输入性别(0:女 1:男):";
	cin >> sex;
	cout << "输入年龄:";
	cin >> age;
	cout << "输入班级:";
	cin >> classes;
}
class Pupil : public Student
{
public:
	double english;
	double maths;
	double chinese;
	void input();
	void toString();
};
void Pupil::input()
{
	Student::input();
	cout << "输入英语成绩:";
	cin >> english;
	cout << "输入数学成绩:";
	cin >> maths;
	cout << "输入语文成绩:";
	cin >> chinese;
}
void Pupil::toString()
{

	cout << number << "\t" << name << "\t" << sex << "\t"
		 << age << "\t" << classes << "\t" << chinese
		 << "\t" << maths << "\t" << english << endl;
}

class Middle : public Pupil
{
public:
	double geography;
	double history;
	string address;
	void input();
	void toString();
};
void Middle::input()
{
	Pupil::input();
	cout << "输入地理成绩:";
	cin >> geography;
	cout << "输入历史成绩:";
	cin >> history;
	cout << "输入地址成绩:";
	cin >> address;
}
void Middle::toString()
{
	cout << number << "\t" << name << "\t" << sex << "\t"
		 << age << "\t" << classes << "\t" << chinese
		 << "\t" << maths << "\t" << english << "\t" << geography
		 << "\t" << history << "\t" << address << endl;
}

class College : public Student
{
public:
	string major;
	string home;
	string contact;
	void input();
	void toString();
};
void College::input()
{
	Student::input();
	cout << "输入专业:";
	cin >> major;
	cout << "输入家庭住址:";
	cin >> home;
	cout << "输入联系方式:";
	cin >> contact;
}
void College::toString()
{

	cout << number << "\t" << name << "\t" << sex << "\t"
		 << age << "\t" << classes << "\t" << major
		 << "\t" << home << "\t" << contact << endl;
}

//以下是对象或对象数组的定义
Pupil pupils[50];
int pupilCount = 0;
Middle middles[50];
int middleCount = 0;
College colleges[50];
int collegeCount = 0;

//读取数据
void read()
{

	ifstream fin("pupil.txt");
	if (fin)
	{
		while (!fin.eof())
		{

			// cout<<pupilCount<<endl;
			// Pupil pupil;
			fin >> pupils[pupilCount].number >> pupils[pupilCount].name >> pupils[pupilCount].sex >> pupils[pupilCount].age >> pupils[pupilCount].classes >> pupils[pupilCount].chinese >> pupils[pupilCount].maths >> pupils[pupilCount].english;
			// pupils[pupilCount].toString();
			// pupils[pupilCount] = pupil;
			if (pupils[pupilCount].number == 0)
			{
				continue;
			}
			pupilCount++;
		}
		fin.close();
		fin.open("middle.txt");
		while (!fin.eof())
		{
			fin >> middles[middleCount].number >> middles[middleCount].name >> middles[middleCount].sex >> middles[middleCount].age >> middles[middleCount].classes >> middles[middleCount].chinese >> middles[middleCount].maths >> middles[middleCount].english >> middles[middleCount].geography >> middles[middleCount].history >> middles[middleCount].address;
			if (middles[middleCount].number == 0)
			{
				continue;
			}
			middleCount++;
		}
		fin.close();
		fin.open("college.txt");
		while (!fin.eof())
		{
			fin >> colleges[collegeCount].number >> colleges[collegeCount].name >> colleges[collegeCount].sex >> colleges[collegeCount].age >> colleges[collegeCount].classes >> colleges[collegeCount].major >> colleges[collegeCount].home >> colleges[collegeCount].contact;
			if (colleges[collegeCount].number == 0)
			{
				continue;
			}
			collegeCount++;
		}
	}
}
//保存所有数据
void save()
{
	ofstream fout("pupil.txt");
	for (int i = 0; i < pupilCount; i++)
	{
		// pupils[i].toString();
		fout << pupils[i].number << "\t" << pupils[i].name << "\t" << pupils[i].sex << "\t"
			 << pupils[i].age << "\t" << pupils[i].classes << "\t" << pupils[i].chinese
			 << "\t" << pupils[i].maths << "\t" << pupils[i].english << endl;
	}
	fout.close();
	fout.open("middle.txt");
	for (int i = 0; i < middleCount; i++)
	{
		fout << middles[i].number << "\t" << middles[i].name << "\t" << middles[i].sex << "\t"
			 << middles[i].age << "\t" << middles[i].classes << "\t" << middles[i].chinese
			 << "\t" << middles[i].maths << "\t" << middles[i].english << "\t" << middles[i].geography
			 << "\t" << middles[i].history << "\t" << middles[i].address << endl;
	}
	fout.close();
	fout.open("college.txt");
	for (int i = 0; i < collegeCount; i++)
	{
		fout << colleges[i].number << "\t" << colleges[i].name << "\t" << colleges[i].sex << "\t"
			 << colleges[i].age << "\t" << colleges[i].classes << "\t" << colleges[i].major
			 << "\t" << colleges[i].home << "\t" << colleges[i].contact << endl;
	}
}

void statistic()
{
	int male = 0, female = 0;
	for (int i = 0; i < pupilCount; i++)
	{
		if (pupils[i].sex == 0)
		{
			female++;
		}
		else
		{
			male++;
		}
	}
	for (int i = 0; i < middleCount; i++)
	{
		if (middles[i].sex == 0)
		{
			female++;
		}
		else
		{
			male++;
		}
	}

	for (int i = 0; i < collegeCount; i++)
	{
		if (colleges[i].sex == 0)
		{
			female++;
		}
		else
		{
			male++;
		}
	}
	cout << "小学生人数：" << pupilCount << " 中学生人数：" << middleCount << " 大学生人数" << collegeCount << endl;
	cout << "男生人数：" << male << " 女生人数:" << female << endl;
}
void findByNumber()
{
	int option;
	double number;
	cout << "请选择数据的类型(1.小学生 2.中学生 3.大学生):";
	cin >> option;
	switch (option)
	{
	case 1:
		cout << "请输入小学生学号:";
		cin >> number;
		for (int i = 0; i < pupilCount; i++)
		{
			if (pupils[i].number == number)
			{
				pupils[i].toString();
			}
		}
		break;
	case 2:
		cout << "请输入中学生学号:";
		cin >> number;
		for (int i = 0; i < middleCount; i++)
		{
			if (middles[i].number == number)
			{
				middles[i].toString();
			}
		}
		break;
	case 3:
		cout << "请输入大学生学号:";
		cin >> number;
		for (int i = 0; i < collegeCount; i++)
		{
			if (colleges[i].number == number)
			{
				colleges[i].toString();
			}
		}
		break;
	default:
		cout << "输入有误" << endl;
		break;
	}
}
void updateByNumber()
{
	int option;
	double number;
	Pupil pupil;
	Middle middle;
	College college;
	cout << "请选择数据的类型(1.小学生 2.中学生 3.大学生):";
	cin >> option;
	switch (option)
	{
	case 1:
		cout << "请输入小学生学号:";
		cin >> number;
		for (int i = 0; i < pupilCount; i++)
		{
			if (pupils[i].number == number)
			{
				pupil.input();
				pupils[i] = pupil;
				cout << "更新成功" << endl;
			}
		}
		break;
	case 2:
		cout << "请输入中学生学号:";
		cin >> number;
		for (int i = 0; i < middleCount; i++)
		{
			if (middles[i].number == number)
			{
				middle.input();
				middles[i] = middle;
				cout << "更新成功" << endl;
			}
		}
		break;
	case 3:
		cout << "请输入大学生学号:";
		cin >> number;
		for (int i = 0; i < collegeCount; i++)
		{
			if (colleges[i].number == number)
			{
				college.input();
				colleges[i] = college;
				cout << "更新成功" << endl;
			}
		}
		break;
	default:
		cout << "输入有误" << endl;
		break;
	}
}

void deleteByNumber()
{
	int option;
	double number;
	Pupil pupil;
	Middle middle;
	College college;
	cout << "请选择数据的类型(1.小学生 2.中学生 3.大学生):";
	cin >> option;
	switch (option)
	{
	case 1:
		cout << "请输入小学生学号:";
		cin >> number;
		for (int i = 0; i < pupilCount; i++)
		{
			if (pupils[i].number == number)
			{
				for (i; i < pupilCount - 1; i++)
				{
					pupils[i] = pupils[i + 1];
				}
				pupilCount--;
				cout << "删除成功" << endl;
				break;
			}
		}
		break;
	case 2:
		cout << "请输入中学生学号:";
		cin >> number;
		for (int i = 0; i < middleCount; i++)
		{
			if (middles[i].number == number)
			{
				for (i; i < middleCount - 1; i++)
				{
					middles[i] = middles[i + 1];
				}
				middleCount--;
				cout << "删除成功" << endl;
				break;
			}
		}
		break;
	case 3:
		cout << "请输入大学生学号:";
		cin >> number;
		for (int i = 0; i < collegeCount; i++)
		{
			if (colleges[i].number == number)
			{
				for (i; i < collegeCount - 1; i++)
				{
					colleges[i] = colleges[i + 1];
				}
				collegeCount--;
				cout << "删除成功" << endl;
				break;
			}
		}
		break;
	default:
		cout << "输入有误" << endl;
		break;
	}
}

void dataInput()
{
	int option;
	cout << "请选择数据的类型(1.小学生 2.中学生 3.大学生):";
	cin >> option;
	Pupil pupil;
	Middle middle;
	College college;
	switch (option)
	{
	case 1:
		pupil.input();
		pupils[pupilCount] = pupil;
		pupilCount++;
		break;
	case 2:
		middle.input();
		middles[middleCount] = middle;
		middleCount++;
		break;
	case 3:
		college.input();
		colleges[collegeCount] = college;
		collegeCount++;
		break;
	default:
		cout << "输入有误" << endl;
		break;
	}
}
//显示小学生
void showPupile()
{
	cout << "\n------------------小学生------------------" << endl;
	cout << "学号"<<"\t"
		 << "姓名"<<"\t"
		 << "性别"<<"\t"
		 << "年龄"<<"\t"
		 << "班级"<<"\t"
		 << "语文"<<"\t"
		 << "数学"<<"\t"
		 << "英语" << endl;
	for (int i = 0; i < pupilCount; i++)
	{
		pupils[i].toString();
	}
}
//显示中学生
void showMiddle()
{
	cout << "\n------------------中学生------------------" << endl;
	cout << "学号"<<"\t"
		 << "姓名"<<"\t"
		 << "性别"<<"\t"
		 << "年龄"<<"\t"
		 << "班级"<<"\t"
		 << "语文"<<"\t"
		 << "数学"<<"\t"
		 << "英语"<<"\t"
		 << "地理"<<"\t"
		 << "历史"<<"\t"
		 << "家庭住址" << endl;
	for (int i = 0; i < middleCount; i++)
	{
		middles[i].toString();
	}
}
//显示大学生
void showColege()
{
	cout << "\n------------------大学生------------------" << endl;
	cout << "学号"<<"\t"
		 << "姓名"<<"\t"
		 << "性别"<<"\t"
		 << "年龄"<<"\t"
		 << "班级"<<"\t"
		 << "专业"<<"\t"
		 << "家庭住址"<<"\t"
		 << "联系方式" << endl;

	for (int i = 0; i < collegeCount; i++)
	{
		colleges[i].toString();
	}
}
void dataPrint()
{
	showPupile();
	showMiddle();
	showColege();
}

//以下是主函数
int main()
{
	read();
	int flag = 1, operate;
	do
	{
		cout << "                   ★★学生信息管理系统★★\n";
		cout << "                ┌─────────────┐\n";
		cout << "                │    请选择您所需的操作    │\n";
		cout << "                │  数据输入：1，并按回车键 │\n";
		cout << "                │  数据统计：2，并按回车键 │\n";
		cout << "                │  数据显示：3，并按回车键 │\n";
		cout << "                │  数据保存：4，并按回车键 │\n";
		cout << "                │  数据查找：5，并按回车键 │\n";
		cout << "                │  数据更新：6，并按回车键 │\n";
		cout << "                │  数据删除：7，并按回车键 │\n";
		cout << "                │  退出系统：8，并按回车键 │\n";
		cout << "                └─────────────┘\n";
		cout << "                      请选择一个操作:   ";
		cin >> operate;
		switch (operate)
		{
		case 1:
			cout << "请输入数据：" << endl;
			{
				cout << "正在输入数据......" << endl;
				//在此添加代码，完成数据输入功能
				dataInput();
			}
			break;

		case 2:
			cout << "请等待......." << endl;
			{
				cout << "正在进行数据统计......" << endl;
				//在此添加代码，完成数据统计功能
				statistic();
			}
			break;

		case 3:
			cout << "请等待........" << endl;
			{
				cout << "正在进行数据打印......" << endl;
				//在此添加代码，完成数据打印功能
				dataPrint();
			};
			break;

		case 4:
			cout << "请等待........" << endl;
			{
				cout << "正在进行数据保存......" << endl;
				//在此添加代码，完成数据保存功能
				save();
			}
			break;
		case 5:
			cout << "数据查找" << endl;
			findByNumber();
			break;
		case 6:
			cout << "更新数据" << endl;
			updateByNumber();

			break;
		case 7:
			cout << "删除数据" << endl;
			deleteByNumber();
			break;
		case 8:
			exit(0); //强制结束程序运行！
			break;
		default:
			cout << "输入错误，请重新1-5间的输入" << endl;
			break;
		}
	} while (1);

	return 0;
}