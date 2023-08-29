#include <iostream>

const int & fun(int &value)
{
    value ++;


    return  value;
}
const int & fun(const int &value)
{

    return  value;
}

int main(int argc, char const *argv[])
{
    int value = 10;
    value= fun(value);
    std::cout << ++value << std::endl;

    value= fun(10);
    std::cout << ++value << std::endl;

    return 0;
}

