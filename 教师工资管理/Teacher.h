#pragma once
#ifndef HEAD_H
#define HEAD_H
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;
class Teacher
{//数据域
private:
    char m_id[32],
        m_name[32],
        m_unit[32],
        m_phone[32],//教职工号，姓名，单位，联系电话
        m_basic_salary[32],
        m_sum_salary[32],
        m_income_tax[32],
        m_accumulation_fund[32],
        m_wages_payable[32],
        m_total_deduction[32],
        m_net_salary[32];//基本工资，津贴，所得税，公积金，应发工资，合计扣款，实发工资
    int order;
public:
    int a();
    int b();
    int c(int r1, int r2);
    friend void count(Teacher s[]);//各自平均
    friend void count(double m, double p, double o);//总平均
    friend int  menu(Teacher s[]);//菜单
    friend int read(Teacher s[]);//读取文件内容
   
    friend void save(Teacher s[], int n);//保存信息
    friend void search(Teacher s[]);//查找一条教师信息
    friend void cut(Teacher s[]);//并删除一条教师信息
    friend void revise(Teacher s[]);//修正一条教师信息
    friend void paixu(Teacher s[]);//排序函数
}s[100];

class Management {
private:
    Teacher teachers[];
public:
    void add(Teacher s[]); //添加一条教师信息
};
#endif
