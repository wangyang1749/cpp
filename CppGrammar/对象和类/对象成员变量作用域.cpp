#include <iostream>

using namespace std;
class Studnet
{
private:
    int id;
public:
    Studnet(int id);
    ~Studnet();
    int getId();
};

Studnet::Studnet(int id)
{
    this->id=id;
}
int Studnet::getId(){
    return id;
}


Studnet::~Studnet()
{
}

Studnet* createStudent(){
    Studnet stu{5};
    
    cout<<stu.getId()<<endl;
    return &stu;
}

Studnet* createStudent2(){
    Studnet* stu = new Studnet{10};
    cout<<stu->getId()<<endl;
    return stu;
}

int main(){
    Studnet *stu =  createStudent2();
    cout<<stu->getId()<<endl;
}


