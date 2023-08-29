#include <iostream>
#include <string.h>

using namespace std;

char &insterstr(char &c, char &d)
{
    strcat(&c, &d);

    return c;
}


int main(int argc, char const *argv[])
{

    return 0;
}
