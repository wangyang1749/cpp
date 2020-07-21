#pragma once
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include "DoStudent.h"
#pragma warning(disable : 4996)
using namespace std;

void DoStudent::menu()
{
    cout << "**************************************************" << endl;
    cout << "*                 学生成绩管理系统               *" << endl;
    cout << "*           作者：郑雪薇，郑冰榕，曾淑桢         *" << endl;
    cout << "*                 时间：2020.06.01               *" << endl;
    cout << "**************************************************" << endl;
    cout << "            **************************" << endl;
    cout << "            *   主菜单命令如下所示： *" << endl;
    cout << "            *     1、输入成绩        *" << endl;
    cout << "            *     2、插入数据        *" << endl;
    cout << "            *     3、修改数据      　*" << endl;
    cout << "            *     4、分数查询        *" << endl;
    cout << "            *     5、分数显示        *" << endl;
    cout << "            *     6、删除分数        *" << endl;
    cout << "            *     7、退出系统        *" << endl;
    cout << "            **************************" << endl;
    cout << "             请输入您的指令数字（1~6）" << endl
         << "  ";

    char p;
    char w;
    Student stu[50];
    Student *s[50];
    ifstream in;
    ofstream out;
    fstream f; //输入输出对象
    int i = 0;
    int j = 0;
    int flag = 0;

    do //flag判断输入是否有效
    {
        cin >> p;
        if (p >= '0' && p <= '6')
            flag = 1;
        else
            cout << "  指令错误！请重新输入：" << endl;
    } while (flag == 0);

    do
    { //最外层循环

        switch (p) //接收功能选项
        {

        case '1': //信息输入

        {
            char name[20];
            int number;
            double yuwen, shuxue, waiyu;
            char c;
            out.open("E:\\a.dat", ios::out);
            do
            {
                cout << "  请输入学生姓名:";
                cin >> name;
                cout << endl
                     << "  请输入学生学号:";
                cin >> number;
                cout << endl
                     << "  请输入语文成绩:";
                cin >> shuxue;
                cout << endl
                     << "  请输入数学成绩:";
                cin >> yuwen;
                cout << endl
                     << "  请输入外语成绩:";
                cin >> waiyu;
                cout << endl;

                out << setw(2) << name << setw(7) << number << setw(6) << yuwen << setw(6) << shuxue << setw(6) << waiyu; //文件输入

                cout << "  数据输入成功，想继续输入吗？   y / n  : " << endl
                     << " ";
                cin >> c;
                cout << endl;
                do
                {
                    if (c != 'y' && c != 'n')
                    {
                        cout << "  指令错误！请重新输入！" << endl
                             << "     ";
                        char c;
                        cin >> c;
                    }
                    else
                        flag = 1;
                } while (flag == 0);
            } while (c == 'y');
            out.close();
            break;
        }

        case '2': //增加数据
        {
            char name[20];
            int number;
            double yuwen, shuxue, waiyu;
            char c;

            out.open("E:\\a.dat", ios::app);
            do
            {
                cout << "请输入您要增加的学生的姓名:";
                cin >> name;
                cout << endl
                     << "            请输入学生学号:";
                cin >> number;
                cout << endl
                     << "            请输入语文成绩:";
                cin >> yuwen;
                cout << endl
                     << "            请输入数学成绩:";
                cin >> shuxue;
                cout << endl
                     << "            请输入外语成绩:";
                cin >> waiyu;
                cout << endl;

                out << setw(2) << name << setw(7) << number << setw(6) << yuwen << setw(6) << shuxue << setw(6) << waiyu; //文件录入

                cout << "  数据添加成功，想继续添加吗？  y / n  :" << endl;
                cin >> c;
                cout << endl;
                if (c == 'n')
                    break;
                if (c != 'y' && c != 'n')
                {
                    cout << "  指令错误！请重新输入！" << endl
                         << "     ";
                    cin >> c;
                }

            } while (c == 'y');
            out.close();
            break;
        }

        case '3': //修改数据
        {
            char name[20];
            int number;
            double yuwen, shuxue, waiyu;
            char na[20];
            int nu;
            double y, sh, w;
            char c;

            do
            {
                int flag = 0;
                cout << "  请输入您要修改的学生的姓名:" << endl;
                cin >> na;
                cout << endl;

                f.open("E:\\a.dat", ios::in | ios::out);
                f.seekg(0, ios::beg);
                f.clear();

                while (!f.eof())
                {
                    f >> name;
                    if (strcmp(name, na) == 0)
                    {
                        flag = 1;
                        cout << "  请输入新的学号:";
                        cin >> nu;
                        cout << endl
                             << "  请输入语文成绩:";
                        cin >> y;
                        cout << endl
                             << "  请输入数学成绩:";
                        cin >> sh;
                        cout << endl
                             << "  请输入外语成绩:";
                        cin >> w;
                        cout << endl;

                        number = nu; //修改过程
                        yuwen = y;
                        shuxue = sh;
                        waiyu = w;

                        f.seekp(0, ios::cur);
                        f << setw(7) << nu << setw(6) << y << setw(6) << sh << setw(6) << w;
                        cout << "  修改成功!  " << endl
                             << endl;
                        break;
                    }
                }
                f.close();

                if (flag == 0)
                    cout << "  您要修改的学生不存在！" << endl
                         << endl;

                cout << "  您想继续修改吗？ y / n   :" << endl;
                cin >> c;
                cout << endl;
                if (c == 'n')
                    break;
                if (c != 'y' && c != 'n')
                {
                    cout << "  指令错误！请重新输入！" << endl
                         << "     ";
                    cin >> c;
                }

            } while (c == 'y');

            break;
        }

        case '4': //信息查询
        {
            char name[20];
            int number;
            double yuwen, shuxue, waiyu;

            cout << "请选择您要进行查询的方式：" << endl
                 << endl
                 << "1.按姓名查询" << endl
                 << endl
                 << "2.按学号查询" << endl;
            int k;
            cin >> k;
            switch (k)

            case 1: //按姓名查询

            {
                char na[20];
                char c;
                //if(i==0)
                // {cout<<"  管理系统中没有输入数据！"<<endl;break;}

                do
                {
                    in.open("E:\\a.dat", ios::in);
                    in.seekg(0, ios::beg);
                    in.clear();
                    int flag = 0;

                    cout << "  请输入你要查询的学生姓名:" << endl;
                    cin >> na;
                    cout << endl;

                    while (!in.eof())
                    {
                        in >> name >> number >> yuwen >> shuxue >> waiyu;
                        if (strcmp(name, na) == 0)
                        {
                            flag = 1;
                            cout << "您要查询的学生:" << name << "的成绩是: " << endl
                                 << endl;
                            cout << "姓名   学号  语文  数学  外语    " << endl;
                            cout << setw(2) << name << setw(7) << number << setw(6) << yuwen << setw(6) << shuxue << setw(6) << waiyu << endl;
                        }
                    }
                    in.close();

                    if (flag == 0)
                        cout << "  对不起!您要查询的学生不存在!" << endl
                             << endl;
                    cout << "  您想继续查询吗？ y / n  :";
                    cin >> c;
                    cout << endl;
                    if (c == 'n')
                        break;
                    if (c != 'y' && c != 'n')
                    {
                        cout << "  指令错误！请重新输入！" << endl;
                        cin >> c;
                    }

                } while (c == 'y');
                break;

            case 2: //按学号查询

            {
                int n;

                do
                {
                    int flag = 0;
                    cout << "  请输入你要查询的学生的学号:" << endl;
                    cin >> n;
                    cout << endl;

                    in.open("E:\\a.dat", ios::in);
                    in.seekg(0, ios::beg);
                    in.clear();

                    while (!in.eof())
                    {
                        in >> name >> number >> yuwen >> shuxue >> waiyu;
                        if (number == n)
                        {
                            flag = 1;
                            cout << "您要查询的学生:" << name << "的成绩是: " << endl
                                 << endl;
                            cout << "姓名   学号  语文  数学  外语    " << endl;
                            cout << setw(2) << name << setw(7) << number << setw(6) << yuwen << setw(6) << shuxue << setw(6) << waiyu << endl;
                        }
                    }

                    in.close();
                    if (flag == 0)
                        cout << "  对不起!您要查询的学生不存在!" << endl;
                    cout << "  您想继续查询吗？  y / n  :";
                    char c;
                    cin >> c;
                    cout << endl;
                    if (c == 'n')
                        break;
                    if (c != 'y' && c != 'n')
                    {
                        cout << "  指令错误！请重新输入！" << endl;
                        cin >> c;
                    }

                } while (c == 'y');
                break;

            default:
                cout << "对不起，您输入的指令有误：";
            }
            break;
            }
            break;

            case '5': //信息浏览
            {
                char name[20];
                int number;
                double yuwen, shuxue, waiyu;

                in.open("E:\\a.dat", ios::in);
                in.seekg(0, ios::beg);
                in.clear();
                if (in.get() == EOF)
                {
                    cout << "  文件中已无数据" << endl
                         << endl;
                    in.close();
                    break;
                }
                cout << "  本系统所有学生数据如下：" << endl
                     << endl;
                cout << "姓名   学号  语文  数学  外语    " << endl;
                while (!in.eof())
                {
                    in >> name >> number >> yuwen >> shuxue >> waiyu;
                    cout << setw(2) << name << setw(7) << number << setw(6) << yuwen << setw(6) << shuxue << setw(6) << waiyu << endl;
                }
                in.close();

                break;
            }

            case '6': //信息删除
            {
                char name[20], na[20];
                int number;
                double yuwen, shuxue, waiyu;
                char c;
                int k;
                do
                {
                    int n = 0;
                    int flag = 0;
                    cout << "  请输入您要删除的学生的姓名:" << endl;
                    cin >> na;
                    cout << endl;

                    in.clear();
                    in.open("E:\\a.dat", ios::in);
                    in.seekg(0, ios::beg);

                    while (!in.eof())
                    {
                        in >> name >> number >> yuwen >> shuxue >> waiyu;
                        [sn] = new Student(name, number, yuwen, shuxue, waiyu);
                        stu[n] = *s[n];
                        delete s[n];
                        n++;
                    }
                    in.close();

                    for (i = 0; i < n; i++)
                    {
                        if (strcmp(stu[i].name, na) == 0)
                        {
                            flag = 1;
                            k = i;
                        }
                    }

                    if (flag == 1)
                    {
                        out.open("E:\\a.dat", ios::out);
                        out.seekp(0, ios::beg);
                        if (n > 1)
                        {
                            for (i = 0; i < k; i++)
                            {
                                out << setw(2) << stu[i].name << setw(7) << stu[i].number << setw(6) << stu[i].yuwen << setw(6) << stu[i].shuxue << setw(6) << stu[i].waiyu;
                            }
                            for (i = k + 1; i < n; i++)
                            {
                                out << setw(2) << stu[i].name << setw(7) << stu[i].number << setw(6) << stu[i].yuwen << setw(6) << stu[i].shuxue << setw(6) << stu[i].waiyu;
                            }
                            cout << "   信息删除成功" << endl
                                 << endl;
                        }
                        if (n = 1)
                        {
                        }
                        out.close();
                    }

                    else
                        cout << "  您要删除的学生不存在！" << endl
                             << endl;

                    cout << "  您想继续删除吗？ y / n   :" << endl;
                    cin >> c;
                    cout << endl;
                    if (c == 'n')
                        break;
                    if (c != 'y' && c != 'n')
                    {
                        cout << "  指令错误！请重新输入！" << endl
                             << "     ";
                        cin >> c;
                    }

                } while (c == 'y');

                break;
            }

            case '7': //退出
            {
                cout << "Bye bye! See you next time." << endl
                     << endl;
                cout << "                   王建制作" << endl
                     << endl
                     << endl;
                exit(0);
            }
            break;
        }

        } //以上为menu菜单中switch控制语句

        cout << "  您想继续进行其他操作吗？  y / n  :" << endl
             << " "; //以下控制循环语句
        int flag = 0;

        do
        {
            cin >> w;
            cout << endl;
            if (w == 'n')
                exit(0);
            if (w != 'y' && w != 'n')
                cout << "  指令错误！请重新输入！" << endl;
            else
                flag = 1;
        } while (flag == 0);

        if (w == 'y')
        {
            cout << "  请输入操作代码: 1 输入数据" << endl;
            cout << "                  2 增加数据" << endl;
            cout << "                  3 修改数据" << endl;
            cout << "                  4 信息查询" << endl;
            cout << "                  5 信息浏览" << endl;
            cout << "                  6 信息删除" << endl;
            cout << "                  7 退出系统" << endl;
        }

        cin >> p;

    } while (w == 'y'); //最外层的do-while循环

} //menu函数结束
