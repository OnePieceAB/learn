#include <iostream>

using namespace std;


// 抽象一个电脑类
class computer
{
public:
    virtual void buy_jixiang() = 0;
    virtual void buy_zhuban() = 0;
    virtual void buy_cpu() = 0;
    virtual void buy_neicun() = 0;
    virtual void buy_yinpan() = 0;
    virtual void buy_dianyuan() = 0;

    // 设计一个装电脑的接口
    void make_computer()
    {
        this->buy_jixiang();
        this->buy_zhuban();
        this->buy_cpu();
        this->buy_neicun();
        this->buy_yinpan();
        this->buy_dianyuan();
    }
};

// 抽象一个笔记本电脑类
class notebook : public computer{

public:
    void buy_jixiang() override{
        cout << "笔记本电脑买机箱" << endl;
    }
    void buy_zhuban() override{ 
        cout << "笔记本电脑买主板" << endl;
    }
    void buy_cpu() override{
        cout << "笔记本电脑买CPU" << endl;
    }
    void buy_neicun() override{
        cout << "笔记本电脑买内存" << endl;
    }
    void buy_yinpan() override{
        cout << "笔记本电脑买硬盘" << endl;
    }
    void buy_dianyuan() override{
        cout << "笔记本电脑买电源" << endl;
    }
};

// 实例化电脑的配置

int main(){

    notebook n;
    n.make_computer();

    return 0;

}; 