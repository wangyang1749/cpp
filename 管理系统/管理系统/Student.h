#pragma once
#include <string>
#include "stdafx.h"
#ifndef Student_H
#define Student_H
using namespace std;


class Student     //Student ��
{
private:
    
public:
    char name[20]; //ѧ������
    double shuxue, yuwen, waiyu;//�γ�
    int  number; //ѧ��ѧ��
    Student() {}
    Student(char n[20], int nu, double yu, double shu, double wai)
    {
        //string (name,n);
        number = nu;
        yuwen = yu, shuxue = shu, waiyu = wai;
    }
    void Demo1();
    void Demo2();
    friend void menu();//��Ԫ����
    
};
#endif //Student_H