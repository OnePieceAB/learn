#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
using namespace std;
// 设计一个文件类
class file
{
public:
    // 构造函数
    file()
    {
        this->fd = open("my.txt", O_RDWR);
        if (this->fd < 0)
        {
            cout << "打开文件失败" << endl;
        }
        else
        {
            cout << "打开文件成功 fd=" << this->fd << endl;
        }
    }
    ~file()
    {
        close(this->fd); 
    }

private:
    int fd; // 文件描述符
};
int main(int argc, char const *argv[])
{

    while (1)
    {
        file f;
        
        sleep(1);
       
    }
   
    return 0;
}
