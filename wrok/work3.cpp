// 面试题 15：用 C++设计一个不能被继承的类

// 题目:设计一个动物类，包含年龄，体重，种类
// 通过动物类派生出狗类包含颜色，爱好。
// 定义一个人类，包含姓名，年龄，性别。
// 一个人养了一条狗，并把所有信息初始化并输出。
#include <iostream>
#include <string.h>
using namespace std;
class Animal
{

public:
    Animal(int age, int weight, const char *kind)
    {
        this->age = age;
        this->weight = weight;
        strcpy(this->kind, kind);
    }
    void show()
    {
        cout << "age:" << age << endl;
        cout << "weight:" << weight << endl;
        cout << "kind:" << kind << endl;
    }

private:
    int age;
    int weight;
    char kind[10];
};
class Dog : public Animal
{
public:
    Dog(int age, int weight, const char *kind, const char *color, const char *hobby) : Animal(age, weight, kind)
    {
        strcpy(this->color, color);
        strcpy(this->hobby, hobby);
    }

    void show()
    {
        Animal::show();
        cout << "color:" << color << endl;
        cout << "hobby:" << hobby << endl;
    }

private:
    char color[10];
    char hobby[10];
};
class Person
{
private:
    char name[10];
    int age;
    char sex[10];
    Dog dog;

public:
    Person(const char *name, int age, const char *sex, int age2, int weight, const char *kind, const char *color, const char *hobby) : dog(age2, weight, kind, color, hobby)
    {
        strcpy(this->name, name);
        this->age = age;
        strcpy(this->sex, sex);
    }
    void show()
    {
        cout << "name:" << name << endl;
        cout << "age:" << age << endl;
        cout << "sex:" << sex << endl;
        dog.show();
    }
};

int main(int argc, char const *argv[])
{
    Person p("zhangsan", 18, "male", 2, 20, "dog", "white", "play");
    p.show();
    return 0;
}
