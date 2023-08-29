// 构造函数
// 作业：在定义时，用于初始化类中成员变量

// 构造函数特点
// 1、函数名与类名一样
// 2、函数可以有参也可以无参,没有返回值
// 3、构造函数可重载
// 4、构造函数必须写在public区，不然类外无权访问构造函数
// 5、构造函数会在声明对象时自动调用

#include <iostream>
#include <string.h>
using namespace std;

class base
{
    // 定义构造函数
public:
    char name[521];
    int age;
    base()
    {
        strcpy(name, "张三");
        age = 18;
        cout << "我是构造函数" << endl;
        cout << "name=" << name << endl;
        cout << "age=" << age << endl;
    }
};

class dog
{

public:
    dog()
    {
        strcpy(name, "旺财");
        strcpy(color, "白色");
        strcpy(varieties, "哈士奇");
        cout << "我是无参构造函数\n"
             << endl;
    }

    dog(const char *name, const char *color, const char *varieties)
    {

        strcpy(this->name, name);
        strcpy(this->color, color);
        strcpy(this->varieties, varieties);

        cout << "我是有参构造函数\n"<< endl;
    }
    void show()
    {
        cout << name << endl;
        cout << color << endl;
        cout << varieties << endl;
    }

private:
    char name[521];
    char color[521];
    char varieties[521];
};

int main(int argc, char const *argv[])
{
    // base b;
    // cout << "我是主函数" << endl;

    dog d1;
    d1.show();
    dog d2("小黑", "黑色", "哈士奇");
    d2.show();
    return 0;
}
