/*----------------------------------------------------------------------------------------
---------原文地址：https://blog.csdn.net/qq_33832591/article/details/78076816-------------
------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <string.h>
using namespace std;
#define MAX 100 //宏定义


//学生的出生日期类
class CDate
{
public:
    CDate(int y = 0, int m = 0, int d = 0);
    //重载<运算符
    bool operator < (CDate d);
    //重载非成员函数和成员函数两者的参数会有变化，详情请百度
    //重载流运算符
    friend istream & operator >> (istream &in, CDate &d);
    friend ostream & operator << (ostream &out, CDate &d);

    friend bool CheckValid(CDate d);
    friend bool LeapYear(int year);

    void setDate(int y, int m, int d);
    ~CDate();

private:
    unsigned short int year, month, day;
};

CDate::CDate(int y, int m, int d) :year(y), month(m), day(d)
{
    //构造函数后面加'：'---->初始化参数列表
    //设置日期
}

CDate::~CDate()
{
    //~函数名----->析构函数
}
void CDate::setDate(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}

//--------定义成员函数，就是那个流运算符的重载函数
istream &operator >> (istream &in, CDate &d)
{
    char ch1, ch2;
    cout << "请输入日期(格式：YYYY-MM-DD)：";
    while (1)
    {
        cin >> d.year >> ch1 >> d.month >> ch2 >> d.day;
        if (ch1 == '-' && ch2 == '-')
            if (CheckValid(d)) break;
        cerr << "时间格式不正确\n";
    }
    return cin;
}

ostream &operator << (ostream &out, CDate &d)
{
    out << d.year << "年" << d.month << "月" << d.day << "日";
    return out;
}

//用处：日期判断 ------ < 运算符重载函数定义
bool CDate::operator < (CDate d)
{
    if (year < d.year) return true;
    if (month < d.month) return true;
    if (day < d.day) return true;
    if (year > d.year) return false;
    if (month > d.month) return false;
    return false;
}

//检查是否为闰年
bool LeapYear(int year)
{
    //能被4整除而不能被100整除.
    //能被400整除.
    //就是闰年
    if (year % 4 == 0 && year % 100 || year % 400 == 0)
        return true;
    else
        return false;
}

//检查用户输入的日期的合法性
bool CheckValid(CDate d)
{
    int n;
    if (d.month < 1 || d.month>12) return false;
    if (d.day < 1) return false;
    n = 31;
    switch (d.month)
    {
    case 2:
        if (LeapYear(d.year))//判断是否为闰年
            n = 29;
        else
            n = 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        n = 30;
        break;
    }
    if (d.day > n) return false;//遇到return，函数结束(?)
    return true;
}


//--------------------------------------------------
//-----------------定义学生信息类-------------------
class CStudent
{
public:
    static int num;//学生人数
    CStudent();

    void InputData();
    friend void Sort();//排序
    friend void FindName();//按姓名查询
    friend void Statistic();//按性别统计
    friend void display();//显示全部信息


    ~CStudent();

private:
    char* name;//姓名
    bool sex;//性别
    CDate date;//出生日期，CDate类对象为数据成员
}stu[MAX];//对象数组

int CStudent::num = 0;//这里定义了学生信息类的num变量的值，代表学生编号(数量？)

CStudent::CStudent()
{
}

CStudent::~CStudent()
{
}

//输入学生信息功能函数
void CStudent::InputData()
{
    int p;
    char s[41];
    cout << "请输入学生信息(NO." << num << "):\n";
    cout << "姓名:";
    cin >> s;
    name = new char[strlen(s) + 1];
    strcpy(name, s);//strcpy函数：复制字符串，遇到'\0'为止
    cout << "性别（输入1-男，输入2-女）:";
    cin >> p;
    if (p) sex = true;//sex的值为1或0，一般除了0以外的都代表true
    else sex = false;
    cin >> date;
    cout << endl;
}

//友元函数，根据出生日期data从小到大排序
void Sort()
{
    int i, j, p, num;
    char* tn;
    bool ts;
    CDate td;
    num = CStudent::num;//前面定义了num变量值为0，所以当学生数量为1或者0的时候不会调用下面for循环的语句
    for (i = 1; i < num; i++)
    {
        p = i;
        for (j = i + 1; j <= num; j++)
            if (stu[i].date < stu[p].date) p = j;
        if (p == i) continue;
        //排序，姓名
        tn = stu[i].name;
        stu[i].name = stu[p].name;
        stu[p].name = tn;
        //排序，性别
        ts = stu[i].sex;
        stu[i].sex = stu[p].sex;
        stu[p].sex = ts;
        //排序，出生日期
        td = stu[i].date;
        stu[i].date = stu[p].date;
        stu[p].date = td;
    }
}
//根据学生姓名查询学生信息函数
void FindName()
{
    char name[41];
    int i, num;
    cout << "请输入姓名:";
    cin >> name;
    num = CStudent::num;
    for (i = 1; i <= num; i++)
        if (strcmp(stu[i].name, name) == 0) break;
    //strcmp函数：比较两个参数，相同返回0，参数1>参数2，返回正数；参数1<参数2，返回负数
    if (i < num)
    {
        cout << "查无此人" << endl << endl;
        return;
    }

    cout << "姓名：" << stu[i].name << endl;
    cout << "性别：";
    if (stu[i].sex)
        cout << "男" << endl;
    else
        cout << "女" << endl;
    cout << endl;
}

//统计各性别人数
void Statistic()
{
    //int i, num, s1, s0;
    //我的显示错误：使用未初始化的变量：s1，s0
    //给这两个值初始化
    int i, num, s1=0, s0=0;
    num = CStudent::num;
    for (i = 1; i <= num; i++)
    {
        if (stu[i].sex == 1)    s1++;
        else s0++;
    }
    cout << "-----男生人数：" << s1 << "\n----女生人数：" << s0 << endl << endl;
}

void display()
{
    int i, num;
    num = CStudent::num;
    for (i = 1; i <= num; i++)
    {
        cout << stu[i].name << "\t";
        if (stu[i].sex == 1)    cout << "男";
        else    cout << "女";
        cout << "\t" << stu[i].date << endl;
    }
}


//-----------------------------------------------
//--------------------主函数---------------------
int main()
{
    //char* menu[] = { "","输入信息","排序","按姓名查询",
    //            "按性别统计", "显示全部信息", "推出"};
    //这个按照原作者代码我的显示错误（VS2017），我加了个const约束
    const char* menu[] = { "","输入信息","排序","按姓名查询",
       "按性别统计","显示全部信息","退出" };
    int i, p;
    bool end;
    end = false;
    while (!end)
    {
        for (i = 1; i < 7; i++)
            cout << i << "        " << menu[i] << endl;
        cin >> p;
        switch (p)
        {
        case 1:
            CStudent::num++;
            stu[CStudent::num].InputData();
            break;
        case 2:
            Sort();
            break;
        case 3:
            FindName();
            break;
        case 4:
            Statistic();
            break;
        case 5:
            display();
            break;
        case 6:
            end = true;
            break;
        }
    }
    return 0;
}