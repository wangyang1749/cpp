#pragma once
#include "stdafx.h"
#include<vector>
using namespace std;
class DoStudent
{
public:
	/*DoStudent(void);
	~DoStudent(void);*/
	vector<Student> vStudent;//User向量，用来存储磁盘文件的内容
	void init();//初始化，读取磁盘文件，赋值给Student向量
	void displayallStudent();//显示所有用户的个人信息
	void modifyoneStudent();//修改用户记录
	void insertoneStudent();//插入一条新用户记录
	void deleteoneStudent();//删除一条用户记录
	void selectoneStudent();//查找并显示一条用户记录
	void saveall();//存盘，将vuser写入磁盘文件
	void menu();
};