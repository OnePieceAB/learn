// 1.编写一个输出学生和教师数据的程序，学生数据有编号、姓名、年龄、班号和成绩；教
//  师数据有编号、姓名、年龄、职称和部门。要求声明一个person类，并作为学生数据操作
//  类student和教师数据操作类teacher的基类
#include <iostream>
#include <string.h>
using namespace std;
class person
{

public:
    int num;
    char name[20];
    int age;
    person(int num, const char *name, int age) : num(num), age(age)
    {
        strcpy(this->name, name);
    }
    void show()
    {
        cout << "num:" << num << endl;
        cout << "name:" << name << endl;
        cout << "age:" << age << endl;
    }
};

class student : public person
{
public:
    int class_num;
    int score;
    student(int num, const char *name, int age, int class_num, int score) : person(num, name, age)
    {
        this->class_num = class_num;
        this->score = score;
    }
    void show()
    {
        person::show();
        cout << "class_num:" << class_num << endl;
        cout << "score:" << score << endl;
    }
};
class teacher : public person
{

public:
    char title[20];
    char department[20];
    teacher(int num, const char *name, int age, const char *title, const char *department) : person(num, name, age)
    {
        strcpy(this->title, title);
        strcpy(this->department, department);
    }
    void show()
    {
        person::show();
        cout << "title:" << title << endl;
        cout << "department:" << department << endl;
    }
};

int main(int argc, char const *argv[])
{
    student s1(1, "zhangsan", 18, 1, 90);
    s1.show();
    teacher t1(2, "lisi", 20, "professor", "computer");
    t1.show();

    return 0;
}
