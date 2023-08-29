#include <iostream>
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap(float &a, float &b)
{
    float temp = a;
    a = b;
    b = temp;
}

void swap(char &a, char &b)
{
    float temp = a;
    a = b;
    b = temp;
}

int main(int argc, char const *argv[])
{
    int a = 10;
    int b = 20;
    float c = 3.14;
    float d = 2.14;
    char e = 'a';
    char f = 'b';

    swap(a,b);
    swap(c,d);
    swap(e,f);
    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;

    std::cout<<c<<std::endl;
    std::cout<<d<<std::endl;
    
    std::cout<<e<<std::endl;
    std::cout<<f<<std::endl;
   
    return 0;
}
