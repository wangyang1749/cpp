#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>

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
class StudentInfo
{
private:
    string id;
    string name;
    int sex;
    Date birthday;
    string school_year;
    string birthplace;

public:
    friend class StudentManager;
    friend class StudentCourse;
    friend class StuAndCourse;
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
};

class StudentCourse
{
private:
    string id;
    string course;
    string credit;
    double score;
    StudentInfo *student;

public:
    friend class StudentManager;
    friend class StuAndCourse;
    void print()
    {
        cout << student->id
             << "  " << student->name
             << "  " << (student->sex ? "男" : "女")
             << "  " << student->birthday
             << "  " << student->school_year
             << "  " << student->birthplace
             << "  " << course
             << "  " << credit
             << "  " << score << endl;
    }
};
class StuAndCourse
{
    StudentInfo *p_stu_;
    StudentCourse *p_sc_;
public:
  
    friend class StudentManager;
    StuAndCourse(StudentInfo *p_stu, StudentCourse *p_sc)
        : p_stu_{p_stu}, p_sc_{p_sc}
    {
    }
    void print()
    {
        cout << p_stu_->id
             << "  " << p_stu_->name
             << "  " << (p_stu_->sex ? "男" : "女")
             << "  " << p_stu_->birthday
             << "  " << p_stu_->school_year
             << "  " << p_stu_->birthplace
             << "  " << p_sc_->course
             << "  " << p_sc_->credit
             << "  " << p_sc_->score << endl;
    }
};

class StudentManager
{
private:
    vector<StudentInfo> stus;
    vector<StudentCourse> scs;
    vector<StuAndCourse> stussacs_;

public:
    StudentManager(string p1, string p2);
    void sortByName();
    void SortByScore();
    void sortByTotalScore();
    void print();
    void find();
};

void StudentManager::sortByName()
{
    
    this->print();
}
void StudentManager::SortByScore(){
    sort(sacs_.begin(), sacs_.end(), [](StuAndCourse &s1, StuAndCourse &s2) {
        return s1.p_stu_->id > s2.p_stu_->id;
    });
    this->print();
}

void StudentManager::find()
{
    for (auto i : sacs_)
    {
        if(i.p_stu_ ->school_year=="2018" && i.p_sc_->course=="C语言" && i.p_sc_->score<60){
            i.print();
        }
    }
}
StudentManager::StudentManager(string p1, string p2)
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
            this->scs.push_back(sc);
        }
        for (auto i = scs.begin();i!=scs.end();i++)
        {
            auto iter = std::find(stus.begin(), stus.end(), i->id);
            if (iter != stus.end())
            {
                sacs_.push_back(StuAndCourse(&*iter, &*i));
            }
        }

    }
}

void StudentManager::print()
{

    sort(sacs_.begin(), sacs_.end(), [](StuAndCourse &s1, StuAndCourse &s2) {
        return s1.p_stu_->id > s2.p_stu_->id;
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
         <<" "
         << "选课"
         << " "
         << "学分"
         << " "
         << "分数"
         << endl;
    for (auto i : sacs_)
    {
        i.print();
    }
    // map<string, vector<StudentCourse>> map1;
    // map<string, vector<StudentCourse>>::iterator p;
    // for (auto i : scs)
    // {
    //     p = map1.find(i.id);
    //     if (p == map1.end())
    //     {
    //         vector<StudentCourse> vsc;
    //         vsc.push_back(i);
    //         map1.insert(pair<string, vector<StudentCourse>>(i.id, vsc));
    //     }
    //     else
    //     {
    //         p->second.push_back(i);
    //     }
    // }
    // cout << "学号"
    //      << " "
    //      << "姓名"
    //      << " "
    //      << "性别"
    //      << " "
    //      << "出生年月"
    //      << "      "
    //      << "学年"
    //      << " "
    //      << "籍贯"
    //      <<" "
    //      << "选课"
    //      << " "
    //      << "学分"
    //      << " "
    //      << "分数"
    //      << endl;
    // sort(stus.begin(), stus.end(), [](StudentInfo &s1, StudentInfo &s2) {
    //     return s1.id > s2.id;
    // });
    // for (auto stu : stus)
    // {
    //     p = map1.find(stu.id);
    //     if (p != map1.end())
    //     {
    //         for (auto i : p->second)
    //         {

    //             cout << stu.id
    //                  << "  " << stu.name
    //                  << "  " << (stu.sex ? "男" : "女")
    //                  << "  " << stu.birthday
    //                  << "  " << stu.school_year
    //                  << "  " << stu.birthplace
    //                  << "  " << i.course
    //                  << "  " << i.credit
    //                  << "  " << i.score<<endl;
    //         }
    //     }
    //     else
    //     {
    //         cout << stu.id
    //              << "  " << stu.name
    //              << "  " << (stu.sex ? "男" : "女")
    //              << "  " << stu.birthday
    //              << "  " << stu.school_year
    //              << "  " << stu.birthplace<<endl;
    //     }
    // }
}

int main()
{
    StudentManager sm("StudentInfo.txt", "StudentCourse.txt");
    sm.print();
    // sm.find();
    // sm.sortByName();
    return 0;
}