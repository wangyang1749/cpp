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
{//������
private:
    char m_id[32],
        m_name[32],
        m_unit[32],
        m_phone[32],//��ְ���ţ���������λ����ϵ�绰
        m_basic_salary[32],
        m_sum_salary[32],
        m_income_tax[32],
        m_accumulation_fund[32],
        m_wages_payable[32],
        m_total_deduction[32],
        m_net_salary[32];//�������ʣ�����������˰��������Ӧ�����ʣ��ϼƿۿʵ������
    int order;
public:
    int a();
    int b();
    int c(int r1, int r2);
    friend void count(Teacher s[]);//����ƽ��
    friend void count(double m, double p, double o);//��ƽ��
    friend int  menu(Teacher s[]);//�˵�
    friend int read(Teacher s[]);//��ȡ�ļ�����
   
    friend void save(Teacher s[], int n);//������Ϣ
    friend void search(Teacher s[]);//����һ����ʦ��Ϣ
    friend void cut(Teacher s[]);//��ɾ��һ����ʦ��Ϣ
    friend void revise(Teacher s[]);//����һ����ʦ��Ϣ
    friend void paixu(Teacher s[]);//������
}s[100];

class Management {
private:
    Teacher teachers[];
public:
    void add(Teacher s[]); //���һ����ʦ��Ϣ
};
#endif
