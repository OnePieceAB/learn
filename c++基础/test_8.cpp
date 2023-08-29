#include <iostream>
using namespace std;
int f(int i){ return ++i; }
int& g(int &i){ return ++i; }
int h(int i){ return ++i; }
int main()
{
int a = 0, b = 0, c = 0;
a += f(g(a));
b += g(g(b));
c += f(h(c));
cout << "a=" << a << ",b=" << b << ",c=" << c << endl;

}