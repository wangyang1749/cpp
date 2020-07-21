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
    cout << "*                 ѧ���ɼ�����ϵͳ               *" << endl;
    cout << "*           ���ߣ�֣ѩޱ��֣���ţ�������         *" << endl;
    cout << "*                 ʱ�䣺2020.06.01               *" << endl;
    cout << "**************************************************" << endl;
    cout << "            **************************" << endl;
    cout << "            *   ���˵�����������ʾ�� *" << endl;
    cout << "            *     1������ɼ�        *" << endl;
    cout << "            *     2����������        *" << endl;
    cout << "            *     3���޸�����      ��*" << endl;
    cout << "            *     4��������ѯ        *" << endl;
    cout << "            *     5��������ʾ        *" << endl;
    cout << "            *     6��ɾ������        *" << endl;
    cout << "            *     7���˳�ϵͳ        *" << endl;
    cout << "            **************************" << endl;
    cout << "             ����������ָ�����֣�1~6��" << endl
         << "  ";

    char p;
    char w;
    Student stu[50];
    Student *s[50];
    ifstream in;
    ofstream out;
    fstream f; //�����������
    int i = 0;
    int j = 0;
    int flag = 0;

    do //flag�ж������Ƿ���Ч
    {
        cin >> p;
        if (p >= '0' && p <= '6')
            flag = 1;
        else
            cout << "  ָ��������������룺" << endl;
    } while (flag == 0);

    do
    { //�����ѭ��

        switch (p) //���չ���ѡ��
        {

        case '1': //��Ϣ����

        {
            char name[20];
            int number;
            double yuwen, shuxue, waiyu;
            char c;
            out.open("E:\\a.dat", ios::out);
            do
            {
                cout << "  ������ѧ������:";
                cin >> name;
                cout << endl
                     << "  ������ѧ��ѧ��:";
                cin >> number;
                cout << endl
                     << "  ���������ĳɼ�:";
                cin >> shuxue;
                cout << endl
                     << "  ��������ѧ�ɼ�:";
                cin >> yuwen;
                cout << endl
                     << "  ����������ɼ�:";
                cin >> waiyu;
                cout << endl;

                out << setw(2) << name << setw(7) << number << setw(6) << yuwen << setw(6) << shuxue << setw(6) << waiyu; //�ļ�����

                cout << "  ��������ɹ��������������   y / n  : " << endl
                     << " ";
                cin >> c;
                cout << endl;
                do
                {
                    if (c != 'y' && c != 'n')
                    {
                        cout << "  ָ��������������룡" << endl
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

        case '2': //��������
        {
            char name[20];
            int number;
            double yuwen, shuxue, waiyu;
            char c;

            out.open("E:\\a.dat", ios::app);
            do
            {
                cout << "��������Ҫ���ӵ�ѧ��������:";
                cin >> name;
                cout << endl
                     << "            ������ѧ��ѧ��:";
                cin >> number;
                cout << endl
                     << "            ���������ĳɼ�:";
                cin >> yuwen;
                cout << endl
                     << "            ��������ѧ�ɼ�:";
                cin >> shuxue;
                cout << endl
                     << "            ����������ɼ�:";
                cin >> waiyu;
                cout << endl;

                out << setw(2) << name << setw(7) << number << setw(6) << yuwen << setw(6) << shuxue << setw(6) << waiyu; //�ļ�¼��

                cout << "  ������ӳɹ�������������  y / n  :" << endl;
                cin >> c;
                cout << endl;
                if (c == 'n')
                    break;
                if (c != 'y' && c != 'n')
                {
                    cout << "  ָ��������������룡" << endl
                         << "     ";
                    cin >> c;
                }

            } while (c == 'y');
            out.close();
            break;
        }

        case '3': //�޸�����
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
                cout << "  ��������Ҫ�޸ĵ�ѧ��������:" << endl;
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
                        cout << "  �������µ�ѧ��:";
                        cin >> nu;
                        cout << endl
                             << "  ���������ĳɼ�:";
                        cin >> y;
                        cout << endl
                             << "  ��������ѧ�ɼ�:";
                        cin >> sh;
                        cout << endl
                             << "  ����������ɼ�:";
                        cin >> w;
                        cout << endl;

                        number = nu; //�޸Ĺ���
                        yuwen = y;
                        shuxue = sh;
                        waiyu = w;

                        f.seekp(0, ios::cur);
                        f << setw(7) << nu << setw(6) << y << setw(6) << sh << setw(6) << w;
                        cout << "  �޸ĳɹ�!  " << endl
                             << endl;
                        break;
                    }
                }
                f.close();

                if (flag == 0)
                    cout << "  ��Ҫ�޸ĵ�ѧ�������ڣ�" << endl
                         << endl;

                cout << "  ��������޸��� y / n   :" << endl;
                cin >> c;
                cout << endl;
                if (c == 'n')
                    break;
                if (c != 'y' && c != 'n')
                {
                    cout << "  ָ��������������룡" << endl
                         << "     ";
                    cin >> c;
                }

            } while (c == 'y');

            break;
        }

        case '4': //��Ϣ��ѯ
        {
            char name[20];
            int number;
            double yuwen, shuxue, waiyu;

            cout << "��ѡ����Ҫ���в�ѯ�ķ�ʽ��" << endl
                 << endl
                 << "1.��������ѯ" << endl
                 << endl
                 << "2.��ѧ�Ų�ѯ" << endl;
            int k;
            cin >> k;
            switch (k)

            case 1: //��������ѯ

            {
                char na[20];
                char c;
                //if(i==0)
                // {cout<<"  ����ϵͳ��û���������ݣ�"<<endl;break;}

                do
                {
                    in.open("E:\\a.dat", ios::in);
                    in.seekg(0, ios::beg);
                    in.clear();
                    int flag = 0;

                    cout << "  ��������Ҫ��ѯ��ѧ������:" << endl;
                    cin >> na;
                    cout << endl;

                    while (!in.eof())
                    {
                        in >> name >> number >> yuwen >> shuxue >> waiyu;
                        if (strcmp(name, na) == 0)
                        {
                            flag = 1;
                            cout << "��Ҫ��ѯ��ѧ��:" << name << "�ĳɼ���: " << endl
                                 << endl;
                            cout << "����   ѧ��  ����  ��ѧ  ����    " << endl;
                            cout << setw(2) << name << setw(7) << number << setw(6) << yuwen << setw(6) << shuxue << setw(6) << waiyu << endl;
                        }
                    }
                    in.close();

                    if (flag == 0)
                        cout << "  �Բ���!��Ҫ��ѯ��ѧ��������!" << endl
                             << endl;
                    cout << "  ���������ѯ�� y / n  :";
                    cin >> c;
                    cout << endl;
                    if (c == 'n')
                        break;
                    if (c != 'y' && c != 'n')
                    {
                        cout << "  ָ��������������룡" << endl;
                        cin >> c;
                    }

                } while (c == 'y');
                break;

            case 2: //��ѧ�Ų�ѯ

            {
                int n;

                do
                {
                    int flag = 0;
                    cout << "  ��������Ҫ��ѯ��ѧ����ѧ��:" << endl;
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
                            cout << "��Ҫ��ѯ��ѧ��:" << name << "�ĳɼ���: " << endl
                                 << endl;
                            cout << "����   ѧ��  ����  ��ѧ  ����    " << endl;
                            cout << setw(2) << name << setw(7) << number << setw(6) << yuwen << setw(6) << shuxue << setw(6) << waiyu << endl;
                        }
                    }

                    in.close();
                    if (flag == 0)
                        cout << "  �Բ���!��Ҫ��ѯ��ѧ��������!" << endl;
                    cout << "  ���������ѯ��  y / n  :";
                    char c;
                    cin >> c;
                    cout << endl;
                    if (c == 'n')
                        break;
                    if (c != 'y' && c != 'n')
                    {
                        cout << "  ָ��������������룡" << endl;
                        cin >> c;
                    }

                } while (c == 'y');
                break;

            default:
                cout << "�Բ����������ָ������";
            }
            break;
            }
            break;

            case '5': //��Ϣ���
            {
                char name[20];
                int number;
                double yuwen, shuxue, waiyu;

                in.open("E:\\a.dat", ios::in);
                in.seekg(0, ios::beg);
                in.clear();
                if (in.get() == EOF)
                {
                    cout << "  �ļ�����������" << endl
                         << endl;
                    in.close();
                    break;
                }
                cout << "  ��ϵͳ����ѧ���������£�" << endl
                     << endl;
                cout << "����   ѧ��  ����  ��ѧ  ����    " << endl;
                while (!in.eof())
                {
                    in >> name >> number >> yuwen >> shuxue >> waiyu;
                    cout << setw(2) << name << setw(7) << number << setw(6) << yuwen << setw(6) << shuxue << setw(6) << waiyu << endl;
                }
                in.close();

                break;
            }

            case '6': //��Ϣɾ��
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
                    cout << "  ��������Ҫɾ����ѧ��������:" << endl;
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
                            cout << "   ��Ϣɾ���ɹ�" << endl
                                 << endl;
                        }
                        if (n = 1)
                        {
                        }
                        out.close();
                    }

                    else
                        cout << "  ��Ҫɾ����ѧ�������ڣ�" << endl
                             << endl;

                    cout << "  �������ɾ���� y / n   :" << endl;
                    cin >> c;
                    cout << endl;
                    if (c == 'n')
                        break;
                    if (c != 'y' && c != 'n')
                    {
                        cout << "  ָ��������������룡" << endl
                             << "     ";
                        cin >> c;
                    }

                } while (c == 'y');

                break;
            }

            case '7': //�˳�
            {
                cout << "Bye bye! See you next time." << endl
                     << endl;
                cout << "                   ��������" << endl
                     << endl
                     << endl;
                exit(0);
            }
            break;
        }

        } //����Ϊmenu�˵���switch�������

        cout << "  ���������������������  y / n  :" << endl
             << " "; //���¿���ѭ�����
        int flag = 0;

        do
        {
            cin >> w;
            cout << endl;
            if (w == 'n')
                exit(0);
            if (w != 'y' && w != 'n')
                cout << "  ָ��������������룡" << endl;
            else
                flag = 1;
        } while (flag == 0);

        if (w == 'y')
        {
            cout << "  �������������: 1 ��������" << endl;
            cout << "                  2 ��������" << endl;
            cout << "                  3 �޸�����" << endl;
            cout << "                  4 ��Ϣ��ѯ" << endl;
            cout << "                  5 ��Ϣ���" << endl;
            cout << "                  6 ��Ϣɾ��" << endl;
            cout << "                  7 �˳�ϵͳ" << endl;
        }

        cin >> p;

    } while (w == 'y'); //������do-whileѭ��

} //menu��������
