#include <iostream>

class Time
{
private:
    int hour_;
    int minute_;
    int second_;
public:
    Time();
    Time(int hour,int minute,int second);
    ~Time();
};
Time::Time(){}

Time::Time(int hour,int minute,int second)
{
    std::cout<<"Time被构造"<<std::endl;
    hour_ = hour;
    minute_ = minute;
    second_ =second;
   
}

Time::~Time()
{
}

class Action
{
private:
    Time time;
public:
    Action(int hour,int minute,int second);
    ~Action();
};

Action::Action(int hour,int minute,int second):time{20,50,60}
{
    std::cout<<"Action被构造"<<std::endl;
    // time = Time{10,20,50};
}

Action::~Action()
{
}

int main(){
    Action action{10,20,50};
    return 0;
}