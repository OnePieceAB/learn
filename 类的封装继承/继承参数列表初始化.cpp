#include <iostream>
using namespace std;

class base
{
public:
    base(int v) : value(v)
    {
        cout << "base构造成功" << this->value << endl;
    }

private:
    int value;
};

class derived : public base
{
public:
    derived(int v, int d) : base(v), data(d)
    {
        cout << "derived构造成功" << this->data << endl;
    }

private:
    int data;
};


int main()
{
    derived d(1, 2);
}