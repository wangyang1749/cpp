// #include "Teacher.h"
// #include "Teacher.h"
// using namespace std;
// #include "Teacher.h"
// using namespace std;

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
    // Teacher teachers[];
public:
    // void add(Teacher s[]); //���һ����ʦ��Ϣ
};
#endif





int main() {
    for (;;) {
        switch (menu(s)) {
        case 1:
            add(s);
            cout << "***";
            system("pause");
            break;
        case 2:
            cut(s);
            cout << "***";
            system("pause");
            break;
        case 3:
            search(s);
            cout << "***";
            system("pause");
            break;
        case 4:
            revise(s);
            cout << "***";
            system("pause");
            break;
        case 5:
            paixu(s);
            cout << "***";
            system("pause");
            break;

        case 6:
            count(s);
            cout << "***";
            system("pause");
            break;
        case 0:
            cout << "��лʹ�ý�ʦ���ʹ���ϵͳ" << endl;
            cout << "***";
            system("pause");
            exit(0);
        }
    }
}

void add(Teacher s[])
{
    int n = read(s);
    char t = 0;
    system("cls");
    cout << endl << "��Ӽ�¼";
    while (t != 'n' && t != 'N')
    {
        cout << "�������ʦ��Ϣ��" << endl;
        cout << "��ʦ�ţ�" << endl; cin >> s[n].m_id;
        cout << "������" << endl; cin >> s[n].m_name;
        cout << "��λ��" << endl; cin >> s[n].m_unit;
        cout << "��ϵ�绰��" << endl; cin >> s[n].m_phone;
        cout << "�������ʣ�" << endl; cin >> s[n].m_basic_salary;
        cout << "������" << endl; cin >> s[n].m_sum_salary;
        cout << "����˰��" << endl; cin >> s[n].m_income_tax;
        cout << "������" << endl; cin >> s[n].m_accumulation_fund;
        cout << "����ɹ�";
        cout << "********************\n";
        cout << "�������(y/n)";
        cout << "��ѡ��";
        cin >> t;
    }
    save(s, n);
}


int menu(Teacher s[]) {
    char c;
    do {
        system("cls");
        cout << "**************\n" << endl;
        cout << "��ӭʹ�ý�ʦ���ʹ���ϵͳ\n" << endl;
        cout << "**************\n" << endl;
        cout << "1��Ӽ�¼" << endl;
        cout << "2ɾ����¼" << endl;
        cout << "3���Ҽ�¼" << endl;
        cout << "4�޸ļ�¼" << endl;
        cout << "5����" << endl;
        cout << "6��ƽ��ֵ" << endl;
        cout << "0�˳�ϵͳ" << endl;
        cout << "**************\n" << endl;
        cout << "��ѡ��" << endl;
        c = getchar();

    } while (c < '0' || c>'6');
    return (c - '0');
}
int Teacher::a() {
    return(m_basic_salary[32]+ m_sum_salary[32]);
}
int Teacher::b() {
    return(m_income_tax [32]+ m_accumulation_fund[32]);
}
int Teacher::c(int r1,int r2) {
    r1 = a();
    r2 = b();
    return(r1+r2);
}
void count(Teacher s[])
{
    int n = read(s);
    int i, x = 0;
    double sum1(0), sum2(0), sum3(0), sum4(0), f1(0), f2(0), f3(0), f4(0), g1(0), g2(0), g3(0), g4(0), h1(0), h2(0), h3(0), h4(0);
    char a[20], b[32] = { 0 }, c[32] = { 0 }, d[32] = { 0 }, e[32] = { 0 };
    cout << "��������Ҫ���㹤�ʵĵ�λ" << endl;
    cin >> a;
    cout << "**********";
    cout << "��ʦ��  ����   ��λ   ��ϵ�绰   ��������   ����   ����˰   ������";
    cout << "**********";
    for (i = 0; i < n; i++)
    {
        if (strcmp(a, s[i].m_unit) == 0)
        {
            cout << s[i].m_id;
            cout << s[i].m_name;
            cout << s[i].m_unit;
            cout << s[i].m_phone;
            cout << s[i].m_basic_salary;
            cout << s[i].m_sum_salary;
            cout << s[i].m_income_tax;
            cout << s[i].m_accumulation_fund;
            cout << "**********";
            strcpy(b, s[i].m_basic_salary);
            strcpy(c, s[i].m_sum_salary);
            strcpy(d, s[i].m_income_tax);
            strcpy(e, s[i].m_accumulation_fund);
            sum1 += b[i];
            f1 += (b[i] - sum1 / x) * (b[i] - sum1 / x);
            sum2 += c[i];
            f2 += (c[i] - sum2 / x) * (c[i] - sum2 / x);
            sum3 += d[i];
            f3 += (d[i] - sum3 / x) * (d[i] - sum3 / x);
            sum4 += e[i];
            f4 += (e[i] - sum4 / x) * (e[i] - sum4 / x);
            g1 = sum1 / x; h1 = sqrt(f1 / x);
            g2 = sum2 / x; h2 = sqrt(f2 / x);
            g3 = sum3 / x; h3 = sqrt(f3 / x);
            g4 = sum4 / x; h4 = sqrt(f4 / x);
        }if (i = n)
            cout << "��Ϣ������";
    }
    cout << "������õ�λ�Ľ�ʦ����" << endl;
    cin >> x;
    cout << "��������ƽ����" << g1;
    cout << "��׼�" << h1;
    cout << "����ƽ��:" << g2;
    cout << "��׼�" << h2;
    cout << "����˰ƽ����" << g3;
    cout << "��׼�" << h3;
    cout << "������ƽ����" << g4;
    cout << "��׼�" << 4;

}
void count(double m, double p, double o)
{
    int i = 0, x = 0;
    int n = read(s);
    double sum1(0), sum2(0), sum3(0), sum4(0), f1(0), f2(0), f3(0), f4(0), g1(0), g2(0), g3(0), g4(0), h1(0), h2(0), h3(0), h4(0), l1(0), l2(0), l3(0), j1(0), j2(0), j3(0);
    char a[50], b[50], c[50], d[50], e[50];
    cout << "��������Ҫ���㹤�ʵĵ�λ:";
    cin >> a;
    cout << "**********";
    cout << "��ʦ��  ����   ��λ   ��ϵ�绰   ��������   ����   ����˰   ������";
    cout << "**********";
    for (i = 0; i < n; i++)
    {
        if (strcmp(a, s[i].m_unit) == 0)
        {
            cout << s[i].m_id;
            cout << s[i].m_name;
            cout << s[i].m_unit;
            cout << s[i].m_phone;
            cout << s[i].m_basic_salary;
            cout << s[i].m_sum_salary;
            cout << s[i].m_income_tax;
            cout << s[i].m_accumulation_fund;
            cout << "**********";
            strcpy(b, s[i].m_basic_salary);
            strcpy(c, s[i].m_sum_salary);
            strcpy(d, s[i].m_income_tax);
            strcpy(e, s[i].m_accumulation_fund);
            sum1 += b[i];
            f1 += (b[i] - sum1 / x) * (b[i] - sum1 / x);
            sum2 += c[i];
            f2 += (c[i] - sum2 / x) * (c[i] - sum2 / x);
            sum3 += d[i];
            f3 += (d[i] - sum3 / x) * (d[i] - sum3 / x);
            sum4 += e[i];
            f4 += (e[i] - sum4 / x) * (e[i] - sum4 / x);
            m = sum1 / x + sum2 / x;
            p = sum3 / x + sum4 / x;
            o = m - p;
            l1 = (a[i] + b[i] - m) * (a[i] + b[i] - m);
            l2 = (d[i] + e[i] - p) * (d[i] + e[i] - p);
            l3 = (a[i] + b[i] - d[i] - e[i] - o) * (a[i] + b[i] - d[i] - e[i] - o);
            j1 = sqrt(l1 / x);
            j2 = sqrt(l1 / x);
            j3 = sqrt(l1 / x);
        }if (i = n)
            cout << "��Ϣ������";
        return;
    }

    cout << "������õ�λ�Ľ�ʦ����" << endl;
    cin >> x;
    cout << "��������ƽ����" << g1;
    cout << "��׼�" << h1;
    cout << "����ƽ��:" << g2;
    cout << "��׼�" << h2;
    cout << "����˰ƽ����" << g3;
    cout << "��׼�" << h3;
    cout << "������ƽ����" << g4;
    cout << "��׼�" << h4;
    m = sum1 / x + sum2 / x;
    p = sum3 / x + sum4 / x;
    o = m - p;
    l1 = (a[i] + b[i] - m) * (a[i] + b[i] - m);
    l2 = (d[i] + e[i] - p) * (d[i] + e[i] - p);
    l3 = (a[i] + b[i] - d[i] - e[i] - o) * (a[i] + b[i] - d[i] - e[i] - o);
    j1 = sqrt(l1 / x);
    j2 = sqrt(l1 / x);
    j3 = sqrt(l1 / x);

    cout << "Ӧ������ƽ����" << m;
    cout << "��׼�" << h4;
    cout << "�ϼƿۿ�ƽ��:" << p;
    cout << "��׼�" << h4;
    cout << "ʵ��ƽ��:" << o;
    cout << "��׼�" << h4;
}
int read(Teacher s[])
{
    ifstream fin("data.txt", ios::in | ios::binary);
    if (!fin)
    {
        cout << "File open error!\n";
        return 0;
    }
    char c[80];
    while (!fin.eof())            //�ж��ļ��Ƿ������
    {
        fin.read(c, 80);
        cout.write(c, fin.gcount());
    }
    fin.close();
    return 0; 
}

void search(Teacher s[])
{
    int i = 0, x, m, p = 0;
    char a[20], q[20], r[20];
    system("cls");
    cout << "1��ʦ��2��������3��Χ����";
    cout << "��ѡ��";
    cin >> m;
    if (m == 1)
    {
        system("cls");
        int n = read(s);
        cout << "��������Ҫ���ҵĽ�ʦ��\n";
        cin >> a;
        cout << "*************";
        while ((s[i].m_id - a) != 0 && i < n)i++;
        if (i == n)
        {
            cout << "�޼�¼";
        }
        else 
        {
            cout << s[i].m_id;
            cout << s[i].m_name;
            cout << s[i].m_unit;
            cout << s[i].m_phone;
            cout << s[i].m_basic_salary;
            cout << s[i].m_sum_salary;
            cout << s[i].m_income_tax;
            cout << s[i].m_accumulation_fund;
            cout << "*************";
        }
    }
    if (m == 2)
    {
        system("cls");
        int m = read(s);
        char t;
        cout << "��������Ҫ���ҵ�����\n";
        cin >> t;
        cout << "*************";
        while ((s[i].m_name - t) != 0 && i < m)i++;
        if (i == m)
        {
            cout << "�޼�¼";
        }
        
        {
            cout << s[i].m_id;
            cout << s[i].m_name;
            cout << s[i].m_unit;
            cout << s[i].m_phone;
            cout << s[i].m_basic_salary;
            cout << s[i].m_sum_salary;
            cout << s[i].m_income_tax;
            cout << s[i].m_accumulation_fund;
            cout << "*************";
        }
    }
    if (m == 3)
    {
        cout << "1��Ӧ�����ʲ���" << "2��ʵ�����ʲ���" << "3�����������";
        cout << "������\n";
        int n =read(s) ;
        cin >> p;
        if (p == 1)
        {
            cout << "���������޺�����";
            cin >> q;
            cin >> r;
            while (q < s[i].m_wages_payable && s[i].m_wages_payable < r)
                for (i = 0; i < n; i++)
                {
                    cout << s[i].m_id;
                    cout << s[i].m_name;
                    cout << s[i].m_unit;
                    cout << s[i].m_phone;
                    cout << s[i].m_basic_salary;
                    cout << s[i].m_sum_salary;
                    cout << s[i].m_income_tax;
                    cout << s[i].m_accumulation_fund;
                }

        }
        if (p == 2)
        {
            cout << "���������޺�����";
            cin >> q;
            cin >> r;
            while (q <= s[i].m_net_salary && s[i].m_net_salary < r)
                cout << s[i].m_id;
            for (i = 0; i < n; i++) {
                cout << s[i].m_name;
                cout << s[i].m_unit;
                cout << s[i].m_phone;
                cout << s[i].m_basic_salary;
                cout << s[i].m_sum_salary;
                cout << s[i].m_income_tax;
                cout << s[i].m_accumulation_fund;
            }
        }
        if (p == 2)
        {
            cout << "���������޺�����";
            cin >> q;
            cin >> r;
            while (q < s[i].m_accumulation_fund && s[i].m_accumulation_fund < r)
                for (i = 0; i < n; i++) 
                {
                    cout << s[i].m_id;
                    cout << s[i].m_name;
                    cout << s[i].m_unit;
                    cout << s[i].m_phone;
                    cout << s[i].m_basic_salary;
                    cout << s[i].m_sum_salary;
                    cout << s[i].m_income_tax;
                    cout << s[i].m_accumulation_fund;
                }
        }

    }
    cout << "1������ѯ2����";
    cout << "��ѡ��";
    cin >> x;
    if (x == 1)search(s);
    if (x == 2)menu(s);

}
void cut(Teacher s[])
{
    int n = read(s);
    int i = 0, j, x = 0;
    char a[20];
    cout << "��������Ҫɾ����Ϣ�Ľ�ʦ��";
    cin >> a;
    while (strcmp(a, s[i].m_id) != 0 && i < n) i++;
    cout << s[i].m_id;
    cout << s[i].m_name;
    cout << s[i].m_unit;
    cout << s[i].m_phone;
    cout << s[i].m_basic_salary;
    cout << s[i].m_sum_salary;
    cout << s[i].m_income_tax;
    cout << s[i].m_accumulation_fund;
    cout << "1ȷ��ɾ��������  2�������˵�";
    cin >> x;
    if (x == 1) {
        for (j = i; j < n + 1; j++)
        {
            strcpy(s[i].m_id, s[i].m_id);
            strcpy(s[i].m_id, s[i].m_id);
            strcpy(s[i].m_id, s[i].m_id);
            strcpy(s[i].m_id, s[i].m_id);
            strcpy(s[i].m_id, s[i].m_id);
            strcpy(s[i].m_id, s[i].m_id);
            strcpy(s[i].m_id, s[i].m_id);
            strcpy(s[i].m_id, s[i].m_id);
        }
        cout << "�Ƿ񱣴�y/n";
        char c;
        cin >> c;
        if (c != 'n' && c != 'N')
            save(s, n);
        if (x == 2)
            menu(s);
        if (i == n)
            cout << "�޸ü�¼";
    }
}
void revise(Teacher s[])
{
    int t, a;
    int i = 0;
    int n = read(s);
    system("cls");
    cout << "��������Ҫ�޸���Ϣ�Ľ�ʦ��";
    cin >> t;
    while ((s[i].m_id) != 0 && i < n)i++;
    if (i = n)
    {
        cout << "�޼�¼";
    }

    else {
        cout << "*************";
        cout << "��ʦ��  ����   ��λ   ��ϵ�绰   ��������   ����   ����˰   ������";
        cout << "*************";
        cout << s[i].m_id;
        cout << s[i].m_name;
        cout << s[i].m_unit;
        cout << s[i].m_phone;
        cout << s[i].m_basic_salary;
        cout << s[i].m_sum_salary;
        cout << s[i].m_income_tax;
        cout << s[i].m_accumulation_fund;
        cout << "*************\n";
        cout << "1�޸Ľ�ʦ��\n2�޸�����\n3�޸ĵ�λ\n4�޸���ϵ�绰\n5�޸Ļ�������\n6�޸Ľ���\n7�޸�����˰\n8�޸Ĺ�����\n";
        cout << "��ѡ��\n";
        cin >> a;
        if (a == 1)
        {
            cout << "�������޸���Ϣ\n";
            cin >> s[i].m_id;
        }
        if (a == 2)
        {
            cout << "�������޸���Ϣ";
            cin >> s[i].m_name;
        }
        if (a == 3)
        {
            cout << "�������޸���Ϣ";
            cin >> s[i].m_unit;
        }
        if (a == 4)
        {
            cout << "�������޸���Ϣ";
            cin >> s[i].m_phone;
        }
        if (a == 5)
        {
            cout << "�������޸���Ϣ";
            cin >> s[i].m_basic_salary;
        }
        if (a == 6)
        {
            cout << "�������޸���Ϣ\n";
            cin >> s[i].m_sum_salary;
        }
        if (a == 7)
        {
            cout << "�������޸���Ϣ\n";
            cin >> s[i].m_income_tax;
        }
        if (a == 8)
        {
            cout << "�������޸���Ϣ";
            cin >> s[i].m_accumulation_fund;
        }

    }
    cout << "*************";
    char c;
    cout << "�Ƿ񱣴�y/n";
    cout << "��ѡ��";
    cin >> c;
    if (c != 'n' && c != 'N')
        save(s, n); menu(s);
}

void save(Teacher s[], int n)
{
    ofstream myFile;
    myFile.open("data.txt", ios::out|ios::binary| ios::in);
    if (!myFile) {
        cout << "�ļ����ܴ�" << endl;
    }
    int count = n;

   myFile << count << endl;
    for (int i = 0; i <= count; i++) {
        myFile << s[i].m_id<< "" << s[i].m_name << "" << s[i].m_unit << "" << s[i].m_phone << "" << s[i].m_basic_salary << "" << s[i].m_sum_salary << "" << s[i].m_income_tax << "" << s[i].m_accumulation_fund;
    }myFile.close();
}
void paixu(Teacher s[])
{
    int i = 0, j;
    int n = read(s);
    char a[20];
    for (j = 0; j < n - 1; j++)
    {
        for (i = 0; i < n - j - 1; i++)
            if (strcmp(s[i].m_net_salary, s[i + 1].m_net_salary) == -1)
            {
                strcpy(a, s[i].m_net_salary);
                strcpy(s[i + 1].m_id, s[i].m_net_salary);
                strcpy(s[i + 1].m_net_salary, a);
            }
        if (strcmp(s[i].m_net_salary, s[i + 1].m_net_salary) == 0)
        {
            strcpy(a, s[i].m_accumulation_fund);
            strcpy(s[i + 1].m_accumulation_fund, s[i].m_accumulation_fund);
            strcpy(s[i + 1].m_accumulation_fund, a);
        }

        if (strcmp(s[i].m_net_salary, s[i + 1].m_net_salary) == 0 && strcmp(s[i].m_net_salary, s[i + 1].m_net_salary) == 0)
        {
            strcpy(a, s[i].m_id);
            strcpy(s[i + 1].m_id, s[i].m_id);
            strcpy(s[i + 1].m_id, a);
        }
    }
    for (j = 0; j < n; j++) 
    {
        s[j].order = j + 1;
        cout << s[i].m_id;
        cout << s[i].m_name;
        cout << s[i].m_unit;
        cout << s[i].m_phone;
        cout << s[i].m_basic_salary;
        cout << s[i].m_sum_salary;
        cout << s[i].m_income_tax;
        cout << s[i].m_accumulation_fund;
    }
    save(s, n);
    menu(s);
}







