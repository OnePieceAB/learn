// 练习：编写一个基类包含value成员，包含set value与show value接口。派生一个派生类，包含value成员，包含
// set value与show value接口。调用派生类和基类的所有接口。
#include <iostream>
#include <string.h>
using namespace std;

class base
{
public:
    int value;
    void setvalue(int v)
    {
        value = v;
    }
    void showvalue()
    {
        cout << "base::value=" << value << endl;
    }
};
class derived : public base
{
public:
    void setvalue(int v)
    {
        value = v;
    }
    void showvalue()
    {
        cout << "derived::value=" << value << endl;
    }
};

int main(int argc, char const *argv[])
{
    derived d;
    d.setvalue(10);
    d.showvalue();
    d.base::setvalue(20);
    d.base::showvalue();

    return 0;
}
