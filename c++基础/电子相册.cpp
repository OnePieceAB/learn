#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <linux/input.h> //添加输入结构体
using namespace std;

/*
cat  /usr/include/linux/input.h

//Linux 事件输入结构体
struct input_event {
        struct timeval time; //事件输入的时间
        __u16 type; //输入的事件 ： 例如： 键盘，鼠标，触摸屏
        __u16 code; //输入的子事件 ： 例如: 触摸屏的 X 或 Y 轴
        __s32 value; //输入事件的值 ：例如：触摸屏的坐标
};
 */

/*
 cat  /usr/include/linux/input-event-codes.h  #查看输入的事件号


#define EV_SYN                  0x00  //
#define EV_KEY                  0x01  //键盘
#define EV_REL                  0x02 //鼠标
#define EV_ABS                  0x03 //触摸屏


#define ABS_X                   0x00
#define ABS_Y                   0x01
*/

// 设计一个触摸屏类
class touch
{
public:
    // 构造函数
    touch()
    {

        // 1.打开触摸屏设备文件
        this->fd = open("/dev/input/event0", O_RDWR);
        if (this->fd < 0)
        {
            cout << "初始化触摸屏失败" << endl;
            exit(0); // 退出进程
        }
        else
        {
            cout << "初始化触摸屏成功" << endl;
        }
    }

    // 析构函数
    ~touch()
    {
        close(this->fd);
    }

    // 获取滑动方向  1 上 2 下 3 左  4 右
    int get_slide()
    {
        // 定义按下坐标
        int t_x = 0, t_y = 0;

        // 定义松开坐标
        int r_x = 0, r_y = 0;

        while (1)
        {
            // 1.读取触摸屏的坐标点
            struct input_event ts = {0};

            read(this->fd, &ts, sizeof(ts));

            // 判断是否为 X 轴的坐标
            if (ts.type == EV_ABS && ts.code == ABS_X)
            {
                r_x = ts.value; // 保存当前的坐标
            }

            // 判断是否为 Y 轴的坐标
            if (ts.type == EV_ABS && ts.code == ABS_Y)
            {
                r_y = ts.value; // 保存当前的坐标
            }

            // 判断手指是否松开
            if (ts.type == EV_KEY && ts.code == BTN_TOUCH)
            {
                if (ts.value == 0) // 松开
                {
                    break;
                }

                if (ts.value == 1) // 按下
                {
                    // 保存按下的坐标
                    t_x = r_x;
                    t_y = r_y;
                }
            }
        }

        // cout << "r_x = " << r_x << endl;
        // cout << "r_y = " << r_y << endl;
        // cout << "t_x = " << t_x << endl;
        // cout << "t_y = " << t_y << endl;

        // 判断滑动方向
        if (t_x - r_x < -100) // 设置滑动的范围必须大于100
        {
            cout << "右滑动" << endl;
            return 4;
        }

        // 判断滑动方向
        if (t_x - r_x > 100)
        {
            cout << "左滑动" << endl;
            return 3;
        }

        if (t_y - r_y > 100)
        {
            cout << "上滑动" << endl;
            return 1;
        }

        if (t_y - r_y < -100)
        {
            cout << "下滑动" << endl;
            return 2;
        }
    }

private:
    int fd;
};

int main()
{

    // 定义触摸对象
    touch t;

    while (1)
    {
        // 获取滑动方向
        int ret = t.get_slide();
        cout << "ret=" << ret << endl;
    }
}