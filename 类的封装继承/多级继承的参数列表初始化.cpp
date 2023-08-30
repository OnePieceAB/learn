#include <iostream>
using namespace std;
class base
{
public:
    base(int a) : a(a)
    {
        cout << "base:" << a << endl;
    }

private:
    int a;
};
class base_a : public base
{
public:
    base_a(int a, int b) : base(a), b(b)
    {
        cout << "base_a:" << b << endl;
    }

private:
    int b;
};
class base_b : public base_a
{
public:
    base_b(int a, int b, int c) : base_a(a, b), c(c)
    {
        cout << "base_b:" << c << endl;
    }

private:
    int c;
};

int main()
{
    base_b tmp(10, 20, 30);
}


