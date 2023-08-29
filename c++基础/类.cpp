#include <iostream>

using namespace std;
class dog
{
public:
    // 名字
    char name[20] = {"土豆"};
    // 颜色
    char color[20] = {"白色"};
    // 品种
    char breed[20] = {"哈士奇"};

protected:
private:
};

main(int argc, char const *argv[])
{
    dog dog;
    cout << "name: " << dog.name << endl;
    cout << "color: " << dog.color << endl;
    cout << "breed: " << dog.breed << endl;

    return 0;
}
