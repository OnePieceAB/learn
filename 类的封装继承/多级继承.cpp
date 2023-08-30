#include <iostream>
using namespace std;

class base
{
public:
    base()
    {
        cout << "base" << endl;
    }
    ~base()
    {
        cout << "~base" << endl;
    }
};

class base_a : public base
{
public:
    base_a()
    {
        cout << "base_a" << endl;
    }
    ~base_a()
    {
        cout << "~base_a" << endl;
    }
};

class base_b : public base_a
{
public:
    base_b()
    {
        cout << "base_b" << endl;
    }
    ~base_b()
    {
        cout << "~base_b" << endl;
    }
};

int main()
{
    base_b tmp;
}