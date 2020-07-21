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
    // Teacher teachers[];
public:
    // void add(Teacher s[]); //添加一条教师信息
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
            cout << "感谢使用教师工资管理系统" << endl;
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
    cout << endl << "添加记录";
    while (t != 'n' && t != 'N')
    {
        cout << "请输入教师信息：" << endl;
        cout << "教师号：" << endl; cin >> s[n].m_id;
        cout << "姓名：" << endl; cin >> s[n].m_name;
        cout << "单位：" << endl; cin >> s[n].m_unit;
        cout << "联系电话：" << endl; cin >> s[n].m_phone;
        cout << "基本工资：" << endl; cin >> s[n].m_basic_salary;
        cout << "津贴：" << endl; cin >> s[n].m_sum_salary;
        cout << "所得税：" << endl; cin >> s[n].m_income_tax;
        cout << "公积金：" << endl; cin >> s[n].m_accumulation_fund;
        cout << "插入成功";
        cout << "********************\n";
        cout << "继续添加(y/n)";
        cout << "请选择";
        cin >> t;
    }
    save(s, n);
}


int menu(Teacher s[]) {
    char c;
    do {
        system("cls");
        cout << "**************\n" << endl;
        cout << "欢迎使用教师工资管理系统\n" << endl;
        cout << "**************\n" << endl;
        cout << "1添加记录" << endl;
        cout << "2删除记录" << endl;
        cout << "3查找记录" << endl;
        cout << "4修改记录" << endl;
        cout << "5排序" << endl;
        cout << "6求平均值" << endl;
        cout << "0退出系统" << endl;
        cout << "**************\n" << endl;
        cout << "请选择" << endl;
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
    cout << "请输入需要计算工资的单位" << endl;
    cin >> a;
    cout << "**********";
    cout << "教师号  姓名   单位   联系电话   基本工资   津贴   所得税   公积金";
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
            cout << "信息不存在";
    }
    cout << "请输入该单位的教师数：" << endl;
    cin >> x;
    cout << "基本工资平均：" << g1;
    cout << "标准差：" << h1;
    cout << "津贴平均:" << g2;
    cout << "标准差：" << h2;
    cout << "所得税平均：" << g3;
    cout << "标准差：" << h3;
    cout << "公积金平均：" << g4;
    cout << "标准差：" << 4;

}
void count(double m, double p, double o)
{
    int i = 0, x = 0;
    int n = read(s);
    double sum1(0), sum2(0), sum3(0), sum4(0), f1(0), f2(0), f3(0), f4(0), g1(0), g2(0), g3(0), g4(0), h1(0), h2(0), h3(0), h4(0), l1(0), l2(0), l3(0), j1(0), j2(0), j3(0);
    char a[50], b[50], c[50], d[50], e[50];
    cout << "请输入需要计算工资的单位:";
    cin >> a;
    cout << "**********";
    cout << "教师号  姓名   单位   联系电话   基本工资   津贴   所得税   公积金";
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
            cout << "信息不存在";
        return;
    }

    cout << "请输入该单位的教师数：" << endl;
    cin >> x;
    cout << "基本工资平均：" << g1;
    cout << "标准差：" << h1;
    cout << "津贴平均:" << g2;
    cout << "标准差：" << h2;
    cout << "所得税平均：" << g3;
    cout << "标准差：" << h3;
    cout << "公积金平均：" << g4;
    cout << "标准差：" << h4;
    m = sum1 / x + sum2 / x;
    p = sum3 / x + sum4 / x;
    o = m - p;
    l1 = (a[i] + b[i] - m) * (a[i] + b[i] - m);
    l2 = (d[i] + e[i] - p) * (d[i] + e[i] - p);
    l3 = (a[i] + b[i] - d[i] - e[i] - o) * (a[i] + b[i] - d[i] - e[i] - o);
    j1 = sqrt(l1 / x);
    j2 = sqrt(l1 / x);
    j3 = sqrt(l1 / x);

    cout << "应发工资平均：" << m;
    cout << "标准差：" << h4;
    cout << "合计扣款平均:" << p;
    cout << "标准差：" << h4;
    cout << "实发平均:" << o;
    cout << "标准差：" << h4;
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
    while (!fin.eof())            //判断文件是否读结束
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
    cout << "1教师号2姓名查找3范围查找";
    cout << "请选择";
    cin >> m;
    if (m == 1)
    {
        system("cls");
        int n = read(s);
        cout << "请输入需要查找的教师号\n";
        cin >> a;
        cout << "*************";
        while ((s[i].m_id - a) != 0 && i < n)i++;
        if (i == n)
        {
            cout << "无记录";
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
        cout << "请输入需要查找的姓名\n";
        cin >> t;
        cout << "*************";
        while ((s[i].m_name - t) != 0 && i < m)i++;
        if (i == m)
        {
            cout << "无记录";
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
        cout << "1按应发工资查找" << "2按实发工资查找" << "3按公积金查找";
        cout << "请输入\n";
        int n =read(s) ;
        cin >> p;
        if (p == 1)
        {
            cout << "请输入下限和上限";
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
            cout << "请输入下限和上限";
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
            cout << "请输入下限和上限";
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
    cout << "1继续查询2返回";
    cout << "请选择";
    cin >> x;
    if (x == 1)search(s);
    if (x == 2)menu(s);

}
void cut(Teacher s[])
{
    int n = read(s);
    int i = 0, j, x = 0;
    char a[20];
    cout << "请输入需要删除信息的教师号";
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
    cout << "1确定删除并保存  2返回主菜单";
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
        cout << "是否保存y/n";
        char c;
        cin >> c;
        if (c != 'n' && c != 'N')
            save(s, n);
        if (x == 2)
            menu(s);
        if (i == n)
            cout << "无该记录";
    }
}
void revise(Teacher s[])
{
    int t, a;
    int i = 0;
    int n = read(s);
    system("cls");
    cout << "请输入需要修改信息的教师号";
    cin >> t;
    while ((s[i].m_id) != 0 && i < n)i++;
    if (i = n)
    {
        cout << "无记录";
    }

    else {
        cout << "*************";
        cout << "教师号  姓名   单位   联系电话   基本工资   津贴   所得税   公积金";
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
        cout << "1修改教师号\n2修改姓名\n3修改单位\n4修改联系电话\n5修改基本工资\n6修改津贴\n7修改所得税\n8修改公积金\n";
        cout << "请选择\n";
        cin >> a;
        if (a == 1)
        {
            cout << "请输入修改信息\n";
            cin >> s[i].m_id;
        }
        if (a == 2)
        {
            cout << "请输入修改信息";
            cin >> s[i].m_name;
        }
        if (a == 3)
        {
            cout << "请输入修改信息";
            cin >> s[i].m_unit;
        }
        if (a == 4)
        {
            cout << "请输入修改信息";
            cin >> s[i].m_phone;
        }
        if (a == 5)
        {
            cout << "请输入修改信息";
            cin >> s[i].m_basic_salary;
        }
        if (a == 6)
        {
            cout << "请输入修改信息\n";
            cin >> s[i].m_sum_salary;
        }
        if (a == 7)
        {
            cout << "请输入修改信息\n";
            cin >> s[i].m_income_tax;
        }
        if (a == 8)
        {
            cout << "请输入修改信息";
            cin >> s[i].m_accumulation_fund;
        }

    }
    cout << "*************";
    char c;
    cout << "是否保存y/n";
    cout << "请选择";
    cin >> c;
    if (c != 'n' && c != 'N')
        save(s, n); menu(s);
}

void save(Teacher s[], int n)
{
    ofstream myFile;
    myFile.open("data.txt", ios::out|ios::binary| ios::in);
    if (!myFile) {
        cout << "文件不能打开" << endl;
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







