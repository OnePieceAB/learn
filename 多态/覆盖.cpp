// 练习：设计一个运动会函数，不同的运动员，参加的运动项目不一样。
// void do_sport(sportsman*p)/运动会函数
// sportsman->派生田径，游泳，跳远
// I

#include <iostream>
#include <string.h>
using namespace std;
class sportsman
{

public:
    virtual void do_sport()
    {
        cout << "sportsman " << endl;
    }
};

class athletics : public sportsman
{
public:
    void do_sport()
    {
        cout << "sportsman paly basketball " << endl;
    }
};

class swimmer : public sportsman
{
public:
    void do_sport()
    {
        cout << "sportsman paly swimming " << endl;
    }
};

class runing : public sportsman
{
public:
    void do_sport()
    {
        cout << "sportsman paly runing " << endl;
    }
};

void do_sport(sportsman *p)
{
    p->do_sport();
}

int main(int argc, char const *argv[])
{
    do_sport(new athletics);
    do_sport(new swimmer);
    do_sport(new runing);
    return 0;
}
