// (抽象基类、纯虚函数、普通虚函数)
// 【2】设计一个基类(airCraft),表达飞行器，并由它派生出直升机(Copter))和轰炸机(Bomber)两个子类。
// 基类包含成员数据：
// ·无
// 基类包含成员方法：
// ·加油(refuel):普通虚函数
// ·飞行(fly)：纯虚函数，必须有特定的实现
// 假定：
// 1.不同的飞行器可以加充通用航空然油，同时允许特定飞行器加充适合其机型的特定然油；
// 2.不同的飞行器没有通用的飞行方式，每一种特定的飞行器必须定义其特定的飞行方式。

#include <iostream>
#include <string.h>
using namespace std;

class airCraft
{
public:
    virtual void refuel()
    {
        cout << "airCraft refuel" << endl;
    }
    virtual void fly() = 0;
};

class Copter : public airCraft
{
public:
    void refuel()
    {
        cout << "Copter refuel" << endl;
    }
    void fly()
    {
        cout << "Copter fly" << endl;
    }
};

class Bomber : public airCraft
{

public:
    void refuel()
    {
        cout << "Bomber refuel" << endl;
    }
    void fly()
    {
        cout << "Bomber fly" << endl;
    }
};

void test(airCraft *p)
{
    p->refuel();
    p->airCraft::refuel();
    p->fly();

    cout << "----------------------" << endl;
}



int main(int argc, char const *argv[])
{

  test(new Bomber());
  test(new Copter());
    return 0;
}
