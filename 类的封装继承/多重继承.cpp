#include <iostream>
#include <string.h>
using namespace std;

class base_a
{
public:
    base_a(const char *str)
    {
        strcpy(this->str, str);
        // cout << "str=" << str << endl;
    }
    void show()
    {
        cout << "str=" << str << endl;
    }

private:
    char str[1024];
};

class base_b
{
public:
    base_b(float f)
    {
        this->f = f;
        // cout << "f=" << f << endl;
    }
    void show()
    {
        cout << "f=" << f << endl;
    }

private:
    float f;
};

class base_c : public base_a, public base_b
{
public:
    // base_c(const char *str, float f, const char *p, int size) : base_a(str), base_b(f), size(size)
    base_c(const char *str, float f, const char *p, int size) : base_b(f), base_a(str), size(size)
    {
        this->p = new char[size];
        memset(this->p, 0, size);
        strcpy(this->p, p);
    }
    void show()
    {
        base_a::show();
        base_b::show();
        cout << "p=" << p << endl;
        cout << "size=" << size << endl;
    }

    ~base_c()
    {
        delete []p;
    }

private:
    char *p; // 指向大小为size的堆空间
    int size;
};

int main(int argc, char const *argv[])
{
    base_c c("hello", 1.1, "world", 10);
    c.show();
    return 0;
}
