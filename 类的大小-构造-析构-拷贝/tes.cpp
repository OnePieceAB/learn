#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <stdio.h>


using namespace std;
int main(int argc, char const *argv[])
{
    int fp;
    fp = open("/bmp/EG.bmp", O_RDWR);
    cout << "fp=" << fp << endl;
    if (fp < 0)
    {
        perror("read open error");
        // cout << "read open error" << endl;
        return 
        -1;
    }else{
        cout << "read open success" << endl;
    }
    return 0;
}
 