#include <iostream>
#include <string.h>
using namespace std;
class animal
{
private:
    char color[20];
    int age;
    // 体重
    int weight;

    /* data */
public:
    animal(char *color, int age, int weight) : age(age), weight(weight)
    {
        strcpy(this->color, color);
    }
    void run()
    {
        cout << "run" << endl;
    }
    void eat()
    {
        cout << "eat" << endl;
    }
    void sleep()
    {
        cout << "sleep" << endl;
    }
    void set(char *color)
    {
        strcpy(this->color, color);
    }
    void set_age(int age)
    {
        this->age = age;
    }
    void set_weight(int weight)
    {
        this->weight = weight;
    }

    char *get_color()
    {
        return this->color;
    }
    int& get_age()
    {
        return this->age;
    }
    int& get_weight()
    {
        return this->weight;
    }
    void show()
    {
        cout << "color:" << color << endl;
        cout << "age:" << age << endl;
        cout << "weight:" << weight << endl;
    }   
};
