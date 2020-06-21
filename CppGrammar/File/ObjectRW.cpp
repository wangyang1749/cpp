#include <fstream>
#include <iostream>
using namespace std;
//对象序列化
// https://www.icourse163.org/learn/BUPT-1003564002?tid=1450339466#/learn/content?type=detail&id=1214630953&cid=1218614118


class Student
{
public:
    char num[10];  //学号
    int age;       //年龄
    char name[20]; //姓名
    char sex[5];   //性别
    Student()
    {
    }
};

void insert()
{
    Student stu;

    cout << "请输入学生的学号" << endl; //输入学生信息
    cin >> stu.num;
    cout << "请输入学生的姓名" << endl;
    cin >> stu.name;
    cout << "请输入学生的年龄" << endl;
    cin >> stu.age;
    cout << "请输入学生的性别" << endl;
    cin >> stu.sex;

    fstream file("student.txt", ios::out | ios::binary | ios::app);
    file.write((char *)&stu, sizeof(Student)); //把该学生对象写入文件
    file.close();
}

void display()
{
    fstream file("student.txt", ios::binary | ios::in);
    Student stu;
    file.read((char *)&stu, sizeof(Student)); //从文件读出所有学生信息
    cout << stu.num << "\t    " << stu.name << " \t" << stu.age << "\t" << stu.sex << "\t"<<endl;
}

int main()
{
    // insert();
    display();
    return 0;
}
