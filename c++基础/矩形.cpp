#include <iostream>

using namespace std;
class rectangle
{
private:
    /* data */
    // 长
    int length;
    // 宽
    int width;
    // 面积
    int area;

public:
    // 设置矩形的长
    int &set_length()
    {
        cout << "请输入矩形的长度" << endl;
        cin >> length;
        if (length < 0 || length > 100)
        {
            cout << "输入的长度不合法，请重新输入" << endl;
            length = set_length();
        }

        return length;
    }
    // 设置矩形的宽
    int &set_width()
    {
        cout << "请输入矩形的宽度" << endl;
        cin >> width;
        if (width < 0 || width > 50)
        {
            cout << "输入的宽度不合法，请重新输入" << endl;
            width = set_width();
        }

        return width;
    }
    int &set_area()
    {
        area = length * width;
        return area;
    }
};
int main(int argc, char const *argv[])
{
    // 矩形
    rectangle r;
    int &length = r.set_length();
    int &width = r.set_width();
    int &area = r.set_area();
    cout << "矩形的面积是：" << area << endl;
    cout << "矩形的周长是：" << 2 * (length + width) << endl;
    cout << "矩形的长是：" << length << endl;
    cout << "矩形的宽是：" << width << endl;
    return 0;
}
