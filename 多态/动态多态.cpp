// 设计一个基类（Shape），表达几何形状，并由它派生出圆（Circle）、矩形（Rectangle）两个子类。
// 基类包含成员方法：
// 求面积（area）
// 求周长（perimeter）
// 显示相关信息（info）（比如图形的位置、圆的半径、矩形的边长等）
// 设计一个get_area(Shape *p )；函数实现求出不同图形的面积和周长，并显示当前图型的信息。
#include <iostream>
#include <string.h>
using namespace std;
class Shape
{

public:
    Shape()
    {
    }

    virtual void info() {}
    virtual int area() {}
    virtual int perimeter(){}

protected:
};

class Circle : public Shape
{
private:
    int r;

public:
    Circle(int r) : Shape()
    {
        this->r = r;
    }
    int area()
    {

        cout << "Circle area=";
        return 3.14 * r * r;
    }
    int perimeter()
    {
        return 2 * 3.14 * r;
    }
    void info()
    {
        cout << " r = " << r << endl;
    }
};

class Rectangle : public Shape
{
private:
    int l;
    int w;

public:
    Rectangle(int l, int w) : Shape()
    {
        this->l = l;
        this->w = w;
    }
    int area()
    {
        cout << "Rectangle area=";
        return l * w;
    }
    int perimeter()
    {
        return 2 * (l + w);
    }
    void info()
    {
        cout << " l = " << l << " w = " << w << endl;
    }
};

int get_area(Shape *p)
{

    cout << p->area() << endl;
    return 0;
}

int main(int argc, char const *argv[])
{
    get_area(new Circle(3));
    get_area(new Rectangle(3, 4));
    return 0;
}
