#pragma once
#include <string>
#include "stdafx.h"
#ifndef Student_H
#define Student_H
using namespace std;


class Student     //Student 类
{
private:
    
public:
    char name[20]; //学生姓名
    double shuxue, yuwen, waiyu;//课程
    int  number; //学生学号
    Student() {}
    Student(char n[20], int nu, double yu, double shu, double wai)
    {
        //string (name,n);
        number = nu;
        yuwen = yu, shuxue = shu, waiyu = wai;
    }
    void Demo1();
    void Demo2();
    friend void menu();//友元函数
    
};
#endif //Student_H