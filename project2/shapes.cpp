#include <vector>
#include <iostream>
#include <cmath>
#include <memory>
#include <fstream>

using namespace std;
class Point
{
private:
    double x_;
    double y_;

public:
    ~Point()
    {
        // cout << "**************Point被销毁" << endl;
    }
    Point() = default;
    Point(double x, double y);
    void print();
    friend class Edge;
    friend ostream &operator<<(ostream &os, Point p);
};

Point::Point(double x, double y) : x_{x}, y_{y}
{
}
void Point::print()
{
    cout << *this;
}
ostream &operator<<(ostream &os, Point p)
{
    return os << "x= " << p.x_ << " y= " << p.y_;
}

/****************************************/
class Edge
{
private:
    Point p1_;
    Point p2_;

public:
    ~Edge()
    {
        // cout << "**************Edge被销毁" << endl;
    }
    Edge(const Point &p1, const Point &p2);
    double length();
    void print();
    friend ostream &operator<<(ostream &os, Edge e);
};

Edge::Edge(const Point &p1, const Point &p2) : p1_{p1}, p2_{p2}
{
}

ostream &operator<<(ostream &os, Edge e)
{
    return os << "边的长度: " << e.length()
              << "点1坐标: " << e.p1_
              << "点2坐标: " << e.p2_;
}
double Edge::length()
{
    return sqrt(pow(p1_.x_ - p2_.x_, 2) + pow(p1_.y_ - p2_.y_, 2));
}
void Edge::print()
{
    cout << *this;
}

//  Edge e(1,2);
/****************************************/
class Shape
{
public:
    static const int UnknowValue = -1;
    Shape() = default;
    virtual double circumference() const = 0;
    virtual double area() = 0;
    virtual void print() = 0;
    virtual bool isValid() const;
};

bool Shape::isValid() const
{
    return true;
}
/****************************************/

class Circle : public Shape
{
private:
    Point center_;
    double radius_;

public:
    Circle() = default;
    ~Circle()
    {
        // cout << "**************Circle被销毁" << endl;
    }
    Circle(Point center, double radius);
    virtual double area() override;
    virtual void print() override;
    virtual bool isValid() const override;
    virtual double circumference() const override;
    friend shared_ptr<Shape> operator&(const Shape &p1, const Shape &p2);
    friend shared_ptr<Shape> operator|(const Shape &p1, const Shape &p2);
};

const double PI = 3.14;
Circle::Circle(Point center, double radius) : center_{center}, radius_{radius}
{
}
shared_ptr<Shape> operator&(const Shape &p1, const Shape &p2)
{
    return shared_ptr<Shape>(new Circle);
}
shared_ptr<Shape> operator|(const Shape &p1, const Shape &p2)
{
    return shared_ptr<Shape>(new Circle);
}

double Circle::area()
{
    return PI * radius_ * radius_;
}
void Circle::print()
{
    cout << "圆心: " << center_ << endl;
    cout << "半径: " << radius_ << endl;
    cout << "周长: " << this->circumference() << endl;
    cout << "面积: " << this->area() << endl;
}
bool Circle::isValid() const
{
    return (radius_ >= 0);
}

double Circle::circumference() const
{
    return 2 * PI * radius_;
}
/****************************************/

class Polygon : public Shape
{
private:
    std::vector<Edge> edges_;

public:
    ~Polygon()
    {
        // cout << "**************Polygon被销毁" << endl;
    }
    Polygon() = default;
    Polygon(vector<Edge> edges);
    virtual double area() override;
    virtual void print() override;
    virtual bool isValid() const override;
    virtual double circumference() const override;
};

Polygon::Polygon(std::vector<Edge> edges)
{
    edges_ = edges;
}
double Polygon::area()
{
    return Shape::UnknowValue;
}
void Polygon::print()
{
    cout << "多边形周长: " << circumference() << endl;
    cout << "多边形面积: " << area() << endl;
    for (int i = 0; i < edges_.size(); i++)
    {
        cout << "*打印第[" << i + 1 << "]条边*" << endl;
        cout << edges_.at(i) << endl;
    }
}
bool Polygon::isValid() const
{
    return (edges_.size() > 0);
}
double Polygon::circumference() const
{
    double s = 0.0;
    for (Edge i : edges_)
    {
        s += i.length();
    }
    return s;
}

class ShapeFile
{
private:
    vector<shared_ptr<Shape>> compositeShapes_;
    vector<shared_ptr<Shape>> shapes_;

public:
    ShapeFile(string path);
    void Generate();
    void print();
};

vector<int> getNumber(const string str, vector<int> num)
{
    int len = str.size();
    int index = 0;
    int t;
    for (int i = 0; i < len; i++)
    {
        num.push_back(0);
        while (!(str[i] > '0' && str[i] < '9'))
        {
            i++;
        }
        while (str[i] >= '0' && str[i] < '9')
        {
            t = int(str[i] - '0');
            num[index] = num[index] * 10 + t;
            i++;
        }
        index++;
    }
    return num;
}

ShapeFile::ShapeFile(string path)
{
    ifstream input{path};
    if (input)
    {
        cout << "**读取文件成功**" << endl;
        string line;
        vector<shared_ptr<Point>> points_;
        while (getline(input, line))
        {

            if (line[0] == '#')
                continue;
            else if (line[0] == 'P' && line[line.size() - 1] == ')')
            {
                vector<int> num;
                num = getNumber(line, num);
                points_.push_back(shared_ptr<Point>(new Point(double(num[1]), double(num[num.size() - 1]))));
            }
            else if (line[0] == 'C')
            {
                vector<int> num;
                num = getNumber(line, num);
                shapes_.push_back(shared_ptr<Shape>(new Circle(*(points_[num[0] - 1]), double(num[1]))));
            }
            else if (line[0] == 'P')
            {
                vector<int> num;
                vector<Edge> edges;
                num = getNumber(line, num);
                for (unsigned int i = 0; i < num.size(); i++)
                    edges.push_back(Edge(*points_[num[i] - 1], *points_[num[(i + 1) % num.size()] - 1]));
                shapes_.push_back(shared_ptr<Polygon>(new Polygon(edges)));
            }
        }
    }
    else
    {
        cout << "**读取文件失败**" << endl;
    }
}
void ShapeFile::Generate()
{
    if (shapes_.size() > 0)
    {
        cout << "**生成新的Shape对象**" << endl;
        for (size_t i = 0; i < shapes_.size(); i++)
        {
            for (size_t j = i + 1; j < shapes_.size(); j++)
            {
                if (typeid(*shapes_[i]) == typeid(Circle) && typeid(*shapes_[j]) == typeid(Circle))
                {
                    compositeShapes_.push_back((*shapes_[i] & *shapes_[j]));
                    compositeShapes_.push_back((*shapes_[i] | *shapes_[j]));
                }
                if (typeid(*shapes_[i]) == typeid(Polygon) && typeid(*shapes_[j]) == typeid(Polygon))
                {
                    compositeShapes_.push_back((*shapes_[i] & *shapes_[j]));
                    compositeShapes_.push_back((*shapes_[i] | *shapes_[j]));
                }
            }
        }
    }
}

void ShapeFile::print()
{
    if (shapes_.size() > 0)
    {
        cout << "**开始打印**" << endl;
        for (shared_ptr<Shape> i : shapes_)
        {
            i->print();
            cout << "" << endl;
        }
        for (auto i : compositeShapes_)
        {
            i->print();
            cout << "" << endl;
        }
    }
}

int main(int argc, char** argv)
{

    if (argc == 2){
        string filename = argv[1];//"/home/wy/Documents/cpp/project2/shapes.txt";
        ShapeFile shapeFile{filename};
        shapeFile.Generate();
        shapeFile.print();
    }else
    {
        cout<<"请输入文件参数"<<endl;
    }
    
    
    return 0;
}