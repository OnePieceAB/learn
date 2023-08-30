#include <iostream>
using namespace std;

class base_a
{
public:
    base_a(int a) : a(a)
    {
        cout << "a=" << a << endl;
    }

private:
    int a;
};

class base_b
{
public:
    base_b(int b) : b(b)
    {
        cout << "b=" << b << endl;
    }

private:
    int b;
};
class base_c : public base_a, public base_b
{
public:
    base_c(int a, int b, int c) : base_a(a), base_b(b), c(c)
    {
        cout << "c=" << c << endl;
    }

private:
    int c;
};

class base_a
{

private:
    char str[1024];
};

class base_b
{
private:
    float f;
};

class base_c : public base_a, public base_b
{

private:
    char *p; // 指向大小为size的堆空间
    int size;
};

int main()
{
    base_c tmp(10, 20, 30);
}