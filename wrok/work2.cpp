// 2.根据下面的要求，完成程序编写，要求包含main函数并在main中使用所定义类的对象。
// (12分)
// 1)定义一个日期类Date,包含年、月、日；
// 2)定义一个人事管理的Person类，要求包含身份证号pid、出生日期birthday、性别sex
// 姓名name、通讯地址address等属性。其中出生出生日期是日期类的对象；
// 3)要求Date有构造函数（带默认参数）、显示属性函数showDate0;Person有构造函数
// (带默认参数，同时传递给基类构造函数)、显示属性函数showPerson0.
#include <iostream>
#include <string.h>
using namespace std;

class Date
{
public:
    Date() {}
    Date(int y = 2020, int m = 1, int d = 1) : year(y), month(m), day(d)
    {
    }

    void showDate0()
    {
        cout << "data:" << year << "-" << month << "-" << day << endl;
    }
  
private:
    int year;
    int month;
    int day;
};

class Person
{
public:
    Person(const char *name, const char *addr,Date bd, const char *pid = "11111111",  const char *s = "男") : birthday(bd)
    {
        strcpy(this->pid, pid);
        strcpy(this->name, name);
        strcpy(this->address, addr);
        strcpy(this->sex, s);
    }
    void showPerson0()
    {
        cout << "person:" << pid << endl;
        cout << "birthday:";
        birthday.showDate0();
        cout << "sex:" << sex << endl;
        cout << "name:" << name << endl;
        cout << "address:" << address << endl;
    }


private:
    char pid[18];
    Date birthday;
    char sex[10];
    char name[20];
    char address[100];
};

int main(int argc, char const *argv[])
{
    Person p("张三", "北京", Date(2020, 1, 1), "123456789012345678", "男");
    p.showPerson0();
    return 0;
}
