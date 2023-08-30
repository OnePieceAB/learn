#include <iostream>
#include <string.h>
using namespace std;
class base
{
public:
    base(const char *str, char a) : a(a)
    {
        strcpy(this->str, str);
    }

    void show()
    {
        cout << "str=" << str << endl;
        cout << "a=" << a << endl;
    }

private:
    char str[1024];
    char a;
};

class base_a : base
{
public:
    base_a(const char *str, char a, float b) : base(str, a), b(b)
    {
    }
    void show()
    {
        base::show();
        cout << "b=" << b << endl;
    }

private:
    float b;
};

class base_b : public base_a
{
public:
    base_b(const char *str, char a, float b, int c, short d) : base_a(str, a, b), c(c), d(d)
    {
    }
    void show()
    {
        base_a::show();
        cout << "c=" << c << endl;
        cout << "d=" << d << endl;
    }

private:
    int c;
    short d;
};
int main(int argc, char const *argv[])
{
    base_b b("hello", 'a', 1.1, 2, 3);
    b.show();

    return 0;
}
