#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <numeric>

using namespace std;
class Date
{
private:
    int year;
    int month;
    int day;

public:
    friend ostream &operator<<(ostream &os, const Date &t)
    {
        os << t.year << "年" << t.month << "月" << t.day << "日";
        return os;
    }
    friend istream &operator>>(istream &is, Date &t)
    {
        string temp;
        is >> temp;
        t.year = atoi(temp.substr(0, 4).c_str());
        t.month = atoi(temp.substr(5, 2).c_str());
        t.day = atoi(temp.substr(8, 2).c_str());
        return is;
    }
    friend class StudentManager;
};

class StudentCourse;
class StudentInfo
{
private:
public:
    string id;
    string name;
    int sex;
    Date birthday;
    string school_year;
    string birthplace;
    vector<StudentCourse *> p_scs_;
    friend class StudentManager;
    friend class StudentCourse;
    bool operator==(const string &str)
    {
        if (this->id == str)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    friend ostream &operator<<(ostream &os, StudentInfo &stu)
    {
        return os << stu.id
                  << "  " << stu.name
                  << "  " << (stu.sex ? "男" : "女")
                  << "  " << stu.birthday
                  << "  " << stu.school_year
                  << "  " << stu.birthplace;
    }
};

class StudentCourse
{
private:
    string id;
    string course;
    double credit;
    double score;
    StudentInfo *p_student;

public:
    friend class StudentManager;
    friend class StuAndCourse;
    double operator()(int nod, StudentCourse &sc)
    {
        return nod * sc.score;
    }

    friend ostream &operator<<(ostream &os, StudentCourse &sc)
    {
        return os << sc.p_student->id
                  << "  " << sc.p_student->name
                  << "  " << (sc.p_student->sex ? "男" : "女")
                  << "  " << sc.p_student->birthday
                  << "  " << sc.p_student->school_year
                  << "  " << sc.p_student->birthplace
                  << "  " << sc.course
                  << "  " << sc.credit
                  << "  " << sc.score;
    }
};

class StudentManager
{
private:
    vector<StudentInfo> stus;
    vector<StudentCourse> scs;
    string p1_, p2_;

public:
    StudentManager(string p1, string p2);
    vector<StudentInfo> check(double credit, double average);
    vector<StudentInfo> sortByName();
    vector<StudentCourse> SortByScore(string course);
    vector<StudentInfo> sortByTotalScore();
    void print();
    void write();
    void printStudentInfo();
    vector<StudentCourse> find(string school_year, string course, double score1, double score2);
    void del(string name);
};
/*根据总分排序*/
vector<StudentInfo> StudentManager::sortByTotalScore()
{
    sort(stus.begin(), stus.end(), [](StudentInfo &s1, StudentInfo &s2) {
        double sum1 = 0;
        for (auto i : s1.p_scs_)
        {
            sum1 += i->score;
        }
        double sum2 = 0;
        for (auto i : s2.p_scs_)
        {
            sum2 += i->score;
        }
        return sum1 > sum2;
    });

    vector<StudentInfo> si;
    for (auto i : stus)
    {
        si.push_back(i);
    }
    return si;
}

vector<StudentInfo> StudentManager::check(double credit, double average)
{
    vector<StudentInfo> si;
    for (auto i : stus)
    {
        double sum1 = 0;
        for (auto i : i.p_scs_)
        {
            sum1 += i->score;
        }
        double sum2 = 0;
        for (auto i : i.p_scs_)
        {
            sum2 += i->credit;
        }
        double sumAverage = sum1/i.p_scs_.size();
        if (sumAverage > average && sum2 < credit )
        {
            // cout << i << " " << sum1 << " " << sum2 << endl;
            si.push_back(i);
        }
    }
    return si;
}

/*根据学生姓名排序*/
vector<StudentInfo> StudentManager::sortByName()
{

    sort(stus.begin(), stus.end(), [](StudentInfo &s1, StudentInfo &s2) {
        return s1.name > s2.name;
    });
    vector<StudentInfo> si;
    for (auto i : stus)
    {
        si.push_back(i);
    }
    return si;
    // this->printStudentInfo();
}
/*根据某一门排序*/
vector<StudentCourse> StudentManager::SortByScore(string course)
{
    sort(scs.begin(), scs.end(), [](StudentCourse &s1, StudentCourse &s2) {
        return s1.score > s2.score;
    });
    vector<StudentCourse> sc;
    for (auto i : scs)
    {
        if (i.course == course)
        {
            sc.push_back(i);
        }
    }
    return sc;
}

vector<StudentCourse> StudentManager::find(string school_year, string course, double score1, double score2)
{
    vector<StudentCourse> sc;
    for (auto i : scs)
    {
        if (i.p_student->school_year == school_year && i.course == course && i.score > score1 && i.score < score2)
        {
            sc.push_back(i);
        }
    }
    return sc;
}

void StudentManager::del(string name)
{
    for (auto i = stus.begin(); i != stus.end(); i++)
    {
        if (i->name == name)
        {
            stus.erase(i);
        }
    }
    for (auto i = scs.begin(); i != scs.end(); i++)
    {
        if (i->p_student->name == name)
        {
            scs.erase(i);
        }
    }
}
void StudentManager::write()
{
    ofstream os1(p1_);
    ofstream os2(p2_);
    for (auto i = stus.begin(); i != stus.end(); i++)
    {
        os1 << i->id
            << " " << i->name
            << " " << i->sex
            << " " << i->birthday
            << " " << i->school_year
            << " " << i->birthplace << endl;
    }
    for (auto i = scs.begin(); i != scs.end(); i++)
    {
        os2 << i->id
            << " " << i->course
            << " " << i->credit
            << " " << i->score << endl;
    }
}
StudentManager::StudentManager(string p1, string p2) : p1_{p1}, p2_{p2}
{
    ifstream inputStu(p1);
    ifstream inputCourse(p2);
    if (inputStu)
    {
        cout << "**读取学生信息成功！**" << endl;
        while (inputStu.peek() != EOF)
        {
            StudentInfo stu;
            inputStu >> stu.id >> stu.name >> stu.sex >> stu.birthday >> stu.school_year >> stu.birthplace;
            this->stus.push_back(stu);
        }
    }

    if (inputCourse)
    {
        cout << "**读取课程信息成功！**" << endl;
        while (inputCourse.peek() != EOF)
        {
            StudentCourse sc;
            inputCourse >> sc.id >> sc.course >> sc.credit >> sc.score;
            auto iter = std::find(stus.begin(), stus.end(), sc.id);
            if (iter != stus.end())
            {
                sc.p_student = &*iter;
            }
            this->scs.push_back(sc);
        }

        map<string, vector<StudentCourse *>> map1;
        map<string, vector<StudentCourse *>>::iterator p;
        for (auto i = scs.begin(); i != scs.end(); i++)
        {
            p = map1.find(i->id);
            if (p == map1.end())
            {
                vector<StudentCourse *> vsc;
                vsc.push_back(&*i);
                map1.insert(pair<string, vector<StudentCourse *>>(i->id, vsc));
            }
            else
            {
                p->second.push_back(&*i);
            }
        }

        for (auto i = stus.begin(); i != stus.end(); i++)
        {
            auto p = map1.find(i->id);
            if (p != map1.end())
            {
                i->p_scs_ = p->second;
            }
        }
    }
}
void StudentManager::printStudentInfo()
{

    cout << "学号"
         << " "
         << "姓名"
         << " "
         << "性别"
         << " "
         << "出生年月"
         << "      "
         << "学年"
         << " "
         << "籍贯" << endl;
    for (auto i : stus)
    {
        cout << i << endl;
    }
}
void StudentManager::print()
{

    sort(scs.begin(), scs.end(), [](StudentCourse &s1, StudentCourse &s2) {
        return s1.id > s2.id;
    });
    cout << "学号"
         << " "
         << "姓名"
         << " "
         << "性别"
         << " "
         << "出生年月"
         << "      "
         << "学年"
         << " "
         << "籍贯"
         << " "
         << "选课"
         << " "
         << "学分"
         << " "
         << "分数"
         << endl;
    for (auto i : scs)
    {
        cout << i << endl;
    }
}

int main()
{
    ofstream os{"result.txt"};
    StudentManager sm("StudentInfo.txt", "StudentCourse.txt");
    // sm.print();
    // 学年 课程 最低分 最高分

    // sm.find("2018", "C语言", 0, 60);
    // sm.sortByName();
    // sm.sortByTotalScore();
    // sm.SortByScore("Python");

    os << "2018级选修C语言且成绩小于60学生" << endl;
    vector<StudentCourse> sc1 = sm.find("2018", "C语言", 0, 60);
    for (auto i : sc1)
    {
        os << i << endl;
    }
    os << "统计平均分大于80分的学生" << endl;
    //学分小于21 平均分大于
    vector<StudentInfo> sc2 = sm.check(21, 80);
    for (auto i : sc2)
    {
        os << i << endl;
    }
    os << "学分未修满20分的学生" << endl;
    vector<StudentInfo> sc3 = sm.check(20, 0);
    for (auto i : sc3)
    {
        os << i << endl;
    }
    return 0;
}