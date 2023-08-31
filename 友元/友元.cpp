// 练习：定义个学生类，包含姓名，学号。年龄。定义一个类外函数初始化这些值，一个类外函数显示这些值。
#include <iostream>

#include <string.h>
using namespace std;

class Student
{

public:
    Student() {}

    Student(char *name, int id, int age)
    {
        strcpy(this->name, name);
        this->id = id;
        this->age = age;
    }
    friend void init(Student &s);
    void show()
    {
        cout << "name:" << name << endl;
        cout << "id:" << id << endl;
        cout << "age:" << age << endl;
    }

private:
    char name[20];
    int id;
    int age;
};

void init(Student &s)
{
    s.age = 20;
    s.id = 100;
    cout << "请输入姓名" << endl;
    cin >> s.name;
    s.show();
}

int main(int argc, char const *argv[])
{

    Student s;
    init(s);

    return 0;
}
