#include <iostream>
#include <string.h>
using namespace std;

struct people
{
    char *name;
    int age;
};

class base
{
public:
    // 构造函数
    base(int v, const char *name, int age)
    {
        this->value = new int(v);

        this->p = new struct people;

        this->p->name = new char[1024];

        this->p->age = age;

        strcpy(this->p->name, name);

        cout << "构造完毕" << endl;

        cout << *value << endl;
        cout << this->p << endl;
        cout << this->p->name << endl;
        cout << (void *)this->p->name << endl;
        cout << this->p->age << endl;
    }

    // 析构函数
    ~base()
    {
        delete value;
        delete [] p->name;
        delete p;
    }

    // 拷贝构造
    base(const base &other)
    {
        this->value = new int(*other.value);
        this->p = new struct people;
        this->p->name = new char[1024];
        this->p->age = other.p->age;
        strcpy(this->p->name, other.p->name);
        cout << "拷贝完毕" << endl;
        cout << *value << endl;
        cout << this->p << endl;
        cout << this->p->name << endl;
        cout << (void *)this->p->name << endl;
        cout << this->p->age << endl;
    }

private:
    int *value;
    struct people *p;
};

int main(int argc, char const *argv[])
{
    base b(10, "zhangsan", 10);
    base b2(b);
    return 0;
}
