#include <iostream>
#include <string.h>
class base
{
public:
    base(const char *s, int size = 0):size(size) // 构造size 分配堆空间的大小 ,s 堆空间存储的字符串
    {
        p = new char[size];
        strcpy(p, s);
    }
    void show()
    {
        std::cout << p << std::endl;
        std::cout << (void*)p << std::endl;
        std::cout << size << std::endl;
    }

//析构函数特点
//1、没有返回值
//2、没有参数
//3、不可重载
//4、必须写在public中
    ~base(){
        delete []p;
        p = NULL;
        size = 0;
        std::cout << "我是析构函数" << std::endl;
    }
private:
    char *p;  // 指向一块大小为size 的堆空间
    int size; // 堆空间的大小
};            // 把上述类的构造函数，设计完毕，并输出堆空间的地址和内容

int main(int argc, char const *argv[])
{
    base b("hello",10);
    b.show();

    return 0;
}
