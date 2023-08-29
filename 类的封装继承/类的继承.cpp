#include <iostream>
#include <string.h>
using namespace std;
class people
{

public:
    people(const char *name, const int age, const char *sex)
    {
        strcpy(this->name, name);
        this->age = age;
        strcpy(this->sex, sex);
    }
    void show()
    {
        cout << "name:" << name << "\n age:" << age << "\n sex:" << sex << endl;
    }
    char *getname()
    {
        return (char *)name;
    }
    int &getage()
    {
        return age;
    }
    char *getsex()
    {
        return (char *)sex;
    }

private:
    char name[20];
    int age;
    char sex[5];
};

class doctor : public people
{
public:
    doctor(const char *name, const int age, const char *sex, const char *department, const char *position) : people(name, age, sex)
    {
        strcpy(this->department, department);
        strcpy(this->position, position);
    }
    void showx() //: people::show()
    {
        this->show();
        cout << "department:" << department << "\n position:" << position << endl;
    }

private:
    char department[100];
    char position[100];
};

int main(int argc, char const *argv[])
{
    /* code */
    doctor d("zhangsan", 20, "man", "department", "position");
    d.showx();
   
    return 0;
}
