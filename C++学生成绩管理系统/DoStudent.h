#pragma once
#include "stdafx.h"
#include<vector>
using namespace std;
class DoStudent
{
public:
	/*DoStudent(void);
	~DoStudent(void);*/
	vector<Student> vStudent;//User�����������洢�����ļ�������
	void init();//��ʼ������ȡ�����ļ�����ֵ��Student����
	void displayallStudent();//��ʾ�����û��ĸ�����Ϣ
	void modifyoneStudent();//�޸��û���¼
	void insertoneStudent();//����һ�����û���¼
	void deleteoneStudent();//ɾ��һ���û���¼
	void selectoneStudent();//���Ҳ���ʾһ���û���¼
	void saveall();//���̣���vuserд������ļ�
	void menu();
};