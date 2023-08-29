#include <iostream>
#include <string.h>
using namespace std;
class test
{
public:
    // 构造函数
    test(const char *s, int size) // s 堆空间存储的字符串 , size 堆空间大小
    {
        str = new char[size];

        strcpy(str, s);
        this->size = size;

        cout << (void *)str << endl;
    }

    // 重写拷贝构造函数
    test(test &t)
    {
        str = new char[t.size];
        strcpy(str, t.str);
        size = t.size;
        cout << (void *)str << endl;
    }
    // 析构函数
    ~test()
    {
        delete[] str;
    }
    char *&getstr()
    {
        return str;
    }
    int &getsize()
    {
        return size;
    }

private:
    char *str; // 指向一块堆空间
    int size;  // 堆空间大小
};

int main(int argc, char const *argv[])
{

    test t1("hello", 6);
    cout << "(void *)&t1.getstr()=" << (void *)t1.getstr() << endl;
    cout << t1.getstr() << endl;
    cout << t1.getsize() << endl;

    test t2(t1);
    cout << "(void *)&t2.getstr()=" << (void *)t2.getstr() << endl;
    cout << t2.getstr() << endl;
    cout << t2.getsize() << endl;

    return 0;
}
