#include <fstream>
#include <vector>
#include <string.h>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

class Money
{

public:
    double jb = 0;   //基本工资
    double jt = 0;   //津贴
    double shbt = 0; // 生活补贴
    double dhf = 0;  // 电话费
    double sdf = 0;  //水电费
    double fz = 0;   //房租
    double sds = 0;  //所得税
    double wsf = 0;  // 卫生费
    double gjj = 0;  // 公积金
};

class Resident
{
public:
    char id_[20];
    char name_[20];
    int sex_;
    char workName_[20];
    int familyId_;
    char address_[20];
    char phone_[20];
    int status_;
    Money money;
};

string path = "data.txt";

void input(Resident &resident)
{
    cout << "\n---------添加数据-----------" << endl;

    cout << "请输入居民身份证号码:";
    cin >> resident.id_;
    cout << "请输入居民身姓名:";
    cin >> resident.name_;
    cout << "请输入居民身性别:";
    cin >> resident.sex_;
    cout << "请输入居民单位名称:";
    cin >> resident.workName_;
    cout << "请输入居民家庭编号:";
    cin >> resident.familyId_;
    cout << "请输入居民家庭住址:";
    cin >> resident.address_;
    cout << "请输入居民联系电话:";
    cin >> resident.phone_;
    cout << "请输入居民工作状态:";
    cin >> resident.status_;
}

void inputMoney(Resident &resident)
{
    cout << "请输入" << resident.name_ << "的基本工资:";
    cin >> resident.money.jb;
    cout << "请输入" << resident.name_ << "的津贴:";
    cin >> resident.money.jt;
    cout << "请输入" << resident.name_ << "的生活补贴:";
    cin >> resident.money.shbt;
    cout << "请输入" << resident.name_ << "的电话费:";
    cin >> resident.money.dhf;
    cout << "请输入" << resident.name_ << "的水电费:";
    cin >> resident.money.sdf;
    cout << "请输入" << resident.name_ << "的房租:";
    cin >> resident.money.fz;
    cout << "请输入" << resident.name_ << "的所得税:";
    cin >> resident.money.sds;
    cout << "请输入" << resident.name_ << "的卫生费:";
    cin >> resident.money.wsf;
    cout << "请输入" << resident.name_ << "的公积金:";
    cin >> resident.money.gjj;
}

void print(Resident &resident)
{
    cout << resident.id_ << "\t    " << resident.name_
         << " \t" << resident.sex_ << "\t" << resident.workName_
         << "\t" << resident.familyId_ << " \t"
         << resident.address_ << "\t\t "
         << resident.phone_ << "\t" << resident.status_
         << "\t" << resident.money.jb << endl;
}

void printMoney(Resident &resident)
{
    double yfgz = resident.money.jb + resident.money.jt + resident.money.shbt;                                                                //应发工资
    double hjkk = resident.money.dhf + resident.money.sdf + resident.money.fz + resident.money.sds + resident.money.wsf + resident.money.gjj; //合计扣款
    double sfgz = yfgz - hjkk;
    cout << resident.id_
         << "\t" << resident.name_
         << "\t" << resident.money.jb
         << "\t" << resident.money.jt
         << "\t" << resident.money.shbt
         << "\t" << resident.money.dhf
         << "\t" << resident.money.sdf
         << "\t" << resident.money.fz
         << "\t" << resident.money.sds
         << "\t" << resident.money.wsf
         << "\t" << resident.money.gjj
         << " | " << yfgz
         << " | " << hjkk
         << " | " << sfgz << endl;
}

void printDetails(Resident &resident)
{
    double yfgz = resident.money.jb + resident.money.jt + resident.money.shbt;                                                                //应发工资
    double hjkk = resident.money.dhf + resident.money.sdf + resident.money.fz + resident.money.sds + resident.money.wsf + resident.money.gjj; //合计扣款
    double sfgz = yfgz - hjkk;

    cout << "身份证号码: " << resident.id_
         << "\n姓名:  " << resident.name_
         << "\n性别: " << resident.sex_
         << "\n单位名称: " << resident.workName_
         << "\n家庭编号: " << resident.familyId_
         << "\n家庭住址: " << resident.address_
         << "\n联系电话: " << resident.phone_
         << "\n工作状态: " << resident.status_
         << "\n基本工资: " << resident.money.jb
         << "\n津贴:" << resident.money.jt
         << "\n生活补贴: " << resident.money.shbt
         << "\n电话费: " << resident.money.dhf
         << "\n房租: " << resident.money.sdf
         << "\n所得税: " << resident.money.fz
         << "\n所得税: " << resident.money.sds
         << "\n卫生费: " << resident.money.wsf
         << "\n公积金: " << resident.money.gjj
         << "\n应发工资:  " << yfgz
         << "\n合计扣款: " << hjkk
         << "\n实发工资:" << sfgz << endl;
}

void insertResident()
{
    // Resident resident{"456", "78949", 20, "xian", 789, "beijing", "1230789", 1};
    Resident resident;
    input(resident);
    fstream file(path, ios::out | ios::binary | ios::app);
    file.write((char *)&resident, sizeof(Resident));
    file.close();
}

void display()
{
    cout << "\n---------显示数据-----------" << endl;
    fstream file(path, ios::binary | ios::in);

    cout << "身份证号码"
         << "  "
         << "姓名"
         << "  "
         << "性别"
         << "  "
         << "单位名称"
         << "  "
         << "家庭编号"
         << "   "
         << "家庭住址"
         << "   "
         << "联系电话"
         << "  "
         << "工作状态" << endl;
    while (file.peek() != EOF)
    {
        Resident resident;
        file.read((char *)&resident, sizeof(Resident)); //从文件读出所有学生信息
        print(resident);
    }
    file.close();
}

void modify()
{
    int item, number;
    char str[20];
    cout << "\n---------修改数据-----------" << endl;
    cout << "请输入用户身份证证号：";
    cin >> str;

    fstream file(path, ios::binary | ios::in | ios::out);
    while (file.peek() != EOF)
    {
        Resident resident;
        file.read((char *)&resident, sizeof(Resident)); //读取文件
        if (strcmp(resident.id_, str) == 0)             //如果存在学生信息输出
        {
            print(resident);
            input(resident);
            file.seekp(-sizeof(Resident), ios::cur);
            file.write((char *)&resident, sizeof(Resident));
            break;
        }
    }
}

void find()
{
    int item, number;
    char str[20];
    cout << "\n---------查找用户数据-----------" << endl;
    cout << "请输入用户身份证证号：";
    cin >> str;

    fstream file(path, ios::binary | ios::in | ios::out);
    while (file.peek() != EOF)
    {
        Resident resident;
        file.read((char *)&resident, sizeof(Resident)); //读取文件
        if (strcmp(resident.id_, str) == 0)             //如果存在学生信息输出
        {
            printDetails(resident);
        }
    }
}

void modifyMoney()
{
    int item, number;
    char str[20];
    cout << "\n---------输入或修改用户数据-----------" << endl;
    cout << "请输入用户身份证证号：";
    cin >> str;

    fstream file(path, ios::binary | ios::in | ios::out);
    while (file.peek() != EOF)
    {
        Resident resident;
        file.read((char *)&resident, sizeof(Resident)); //读取文件
        if (strcmp(resident.id_, str) == 0)             //如果存在学生信息输出
        {
            printMoney(resident);
            inputMoney(resident);
            file.seekp(-sizeof(Resident), ios::cur);
            file.write((char *)&resident, sizeof(Resident));
            break;
        }
    }
}

void delById()
{
    cout << "\n---------删除数据-----------" << endl;
    int item, number;
    char str[20];
    cout << "请输入用户身份证证号：";
    cin >> str;

    fstream file(path, ios::binary | ios::in);
    vector<Resident> residents;
    while (file.peek() != EOF)
    {
        Resident resident;
        file.read((char *)&resident, sizeof(Resident)); //读取文件
        if (strcmp(resident.id_, str) == 0)
        {
            cout << "删除用户:" << resident.name_ << endl;
            continue;
        }
        residents.push_back(resident);
    }
    file.close();
    file.open(path, ios::out | ios::trunc);
    for (Resident resi : residents)
    {
        file.write((char *)&resi, sizeof(Resident)); //将容器中的学生对象写入文件
    }
    file.close();
}

void statistic()
{
    cout << "\n---------统计居民信息-----------" << endl;

    fstream file(path, ios::binary | ios::in);
    int male = 0;
    int female = 0;
    double zsu = 0; //本地区居民总输入
    vector<Resident> residents;
    while (file.peek() != EOF)
    {
        Resident resident;
        file.read((char *)&resident, sizeof(Resident));
        double yfgz = resident.money.jb + resident.money.jt + resident.money.shbt;                                                                //应发工资
        double hjkk = resident.money.dhf + resident.money.sdf + resident.money.fz + resident.money.sds + resident.money.wsf + resident.money.gjj; //合计扣款
        double sfgz = yfgz - hjkk;
        zsu += sfgz; //总输入每个人输入之和
        if (resident.sex_ == 1)
        {
            male += 1;
        }
        else
        {
            female += 1;
        }
        residents.push_back(resident);
    }
    double bdjmpjsr = zsu / residents.size(); //本地居民平均输入
    cout << "本地区总人数: " << residents.size() << " 人均输入: " << bdjmpjsr << endl;
    cout << "男性居民数量:" << male << "女性居民数量:" << female << endl;
    map<int, vector<Resident>> residentMap;
    cout << "\n---------要发放补助的家庭，每人发放的金额，总金额-----------" << endl;
    for (Resident resident : residents)
    {
        map<int, vector<Resident>>::iterator it = residentMap.find(resident.familyId_);
        if (it == residentMap.end())
        {
            std::vector<Resident> vec;
            vec.push_back(resident);
            residentMap.insert(make_pair(resident.familyId_, vec));
        }
        else
        {
            it->second.push_back(resident);
        }
    }
    map<int, vector<Resident>>::iterator it;
    it = residentMap.begin();
    double zffje = 0; //本地居民总发放金额
    while (it != residentMap.end())
    {
        double jtzq = 0; // 家庭的总钱数
        for (Resident resident : it->second)
        {
            double yfgz = resident.money.jb + resident.money.jt + resident.money.shbt;                                                                //应发工资
            double hjkk = resident.money.dhf + resident.money.sdf + resident.money.fz + resident.money.sds + resident.money.wsf + resident.money.gjj; //合计扣款
            double sfgz = yfgz - hjkk;
            jtzq += sfgz;
        }
        double jtpjsr = jtzq / it->second.size();   //家庭平均输入
        double rjffje = (bdjmpjsr - jtpjsr) * 0.75; //人均发放金额
        if (rjffje > 0)
        {
            double jtzje = rjffje * it->second.size(); //家庭总金额
            zffje += jtzje;
            cout << "家庭编号是[" << it->first
                 << "]有[" << it->second.size()
                 << "]个成员"
                 << "家庭平均输入[" << jtpjsr << "]"
                 << "人均发放金额[" << rjffje << "]"
                 << "总金额[" << jtzje << "]"
                 << endl;
        }

        it++;
    }
    cout << "---本地居民总发放金额" << zffje << endl;
}

void sortResident()
{
    cout << "\n---------居民信息排序-----------" << endl;
    fstream file(path, ios::binary | ios::in);
    vector<Resident> residents;
    while (file.peek() != EOF)
    {
        Resident resident;
        file.read((char *)&resident, sizeof(Resident));
        residents.push_back(resident);
    }

    int item;
    while (true)
    {
        cout << "==============================" << endl;
        cout << "1.按照姓名排序" << endl;
        cout << "2.按基本工资" << endl;
        cout << "0.返回上一层" << endl;
        cout << "==============================" << endl;
        cout << "请输入数字(0-2):";
        cin >> item;
        switch (item)
        {
        case 0:
            return;
            break;
        case 1:
            sort(residents.begin(), residents.end(), [](Resident x, Resident y) { return x.name_ > y.name_; }); //使用sort进行排序
            for (Resident r : residents)
            {
                print(r);
            }
            break;
        case 2:
            sort(residents.begin(), residents.end(), [](Resident x, Resident y) { return x.money.jb > y.money.jb; }); //使用sort进行排序
            for (Resident r : residents)
            {
                print(r);
            }
            break;
        default:
            cout << "输入有误请重新输入：";
            break;
        }
    }
}

void menu()
{
    cout << "==============================" << endl;
    cout << "1.添加居民" << endl;
    cout << "2.删除居民" << endl;
    cout << "3.修改居民" << endl;
    cout << "4.显示所有居民" << endl;
    cout << "5.添加居民资金数据" << endl;
    cout << "6.统计居民信息" << endl;
    cout << "7.查找用户数据" << endl;
    cout << "8.居民信息排序" << endl;
    cout << "0.退出本系统" << endl;
    cout << "==============================" << endl;
    cout << "请输入数字(1-5):";
}
int main()
{
    while (true)
    {
        int item;
        menu();
        cin >> item;
        switch (item)
        {
        case 0:
            return 0;
            break;
        case 1:
            insertResident();
            break;
        case 2:
            delById();
            break;
        case 3:
            modify();
            break;
        case 4:
            display();
            break;
        case 5:
            modifyMoney();
            break;
        case 6:
            statistic();
            break;
        case 7:
            find();
            break;
        case 8:
            sortResident();
            break;
        default:
            cout << "输入有误请重新输入：";
            break;
        }
    }
    return 0;
}
