#include <iostream>
using namespace std;

class base_a
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

class base_b
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

class base_c : public base_a, public base_b
{
public:
    base_c()
    {
        cout << "base_c" << endl;
    }
    ~base_c()
    {
        cout << "~base_c" << endl;
    }
};

int main()
{
    base_c tmp;
}