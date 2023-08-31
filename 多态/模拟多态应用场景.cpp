
// 在上述 框架基础上，新增一个角色，两个怪物 。  然后相互传递怪物，角色进行战斗。

// 1.利用多态设计回合制游戏的战斗场景
#include <iostream>
using namespace std;

// 基类角色
class role
{
public:
    role(int p, int l) : pow(p), life(l) {}
    virtual int attck(){}; // 角色的攻击函数
    virtual void show_name() {}
    // 设计一个扣血接口
    int hurt(int hurt)
    {
        life -= hurt;

        return life;
    }

protected:
    int pow;  // 力量
    int life; // 生命
};

// 基类怪物
class monster
{
public:
    monster(int p, int l) : pow(p), life(l) {}
    virtual int attck(){}; // 角色的攻击函数

    virtual void show_name(){}; // 显示名字函数

    // 设计一个扣血接口
    int hurt(int hurt)
    {
        life -= hurt;

        return life;
    }

protected:
    int pow;  // 力量
    int life; // 生命
};

// 设计一个战斗法师
class Wizard : public role
{
public:
    Wizard(int p, int l) : role(p, l) {}
    void show_name()
    {
        cout << "战斗法师" << endl;
    }
    // 设计战斗法师的战斗方式
    int attck()
    {
        cout << "1.普通攻击——————机枪扫射" << endl;
        cout << "2.法术攻击——————召唤擎天柱" << endl;
        cout << "3.法术大招——————灭霸响指" << endl;

        cout << "请输入你的选择：" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            cout << "角色进行普通攻击——————机枪扫射，造成伤害" << this->pow << endl;
            return this->pow;
        }
        else if (choice == 2)
        {
            cout << "角色进行法术攻击——————召唤擎天柱，造成伤害" << this->pow * 10 << endl;
            return this->pow * 10;
        }
        else if (choice == 3)
        {
            
            cout << "角色进行法术大招——————灭霸响指，造成伤害" << this->pow*99999999 << endl;
            return this->pow*99999999;
        }
        return 0;
    }
};

// 设计一个剑侠角色
class Swordm : public role
{
public:
    Swordm(int p, int l) : role(p, l) {}

    void show_name()
    {
        cout << "剑侠";
    }

    // 设计剑侠的战斗方法
    int attck()
    {
        cout << "1.普通攻击" << endl;
        cout << "2.重剑攻击" << endl;
        cout << "3.万剑归一" << endl;
        int n = 0;
        cin >> n;

        if (n == 1)
        {
            cout << "角色进行普通攻击，造成伤害" << this->pow << endl;
            return this->pow;
        }

        if (n == 2)
        {
            cout << "角色进行重剑攻击，造成伤害" << this->pow * 2 << endl;
            return this->pow * 2;
        }

        if (n == 3)
        {
            cout << "九山八海、为一世界，聚千界则成‘小千世界’，此界乘三，无我不断者，三刀流奥义，一大‧三千‧大千世界。" << endl;
            cout << "伤害:" << this->pow * 999999 << endl;

            this->life -= 100;
            cout << "扣除生命100剩余" << this->life << endl;
        }
    }
};

// 派生史莱姆
class Slime : public monster
{
public:
    Slime(int p, int l) : monster(p, l) {}

    void show_name()
    {
        cout << "史莱姆";
    }

    int attck()
    {
        cout << "史莱姆进行唾液攻击，造成伤害" << this->pow << endl;

        return this->pow / 2;
    }
};

// 派生哥布林
class Goblin : public monster
{
public:
    Goblin(int p, int l) : monster(p, l) {}
    void show_name()
    {
        cout << "哥布林";
    }

    int attck()
    {
        cout << "哥布林进行头槌攻击，造成伤害" << this->pow * 2 << endl;

        return this->pow * 2;
    }
};

// 为了让派生类覆盖他们的功能方法，产生多样性。
int role_pk_monster(role *p, monster *m)
{
    p->show_name();
    cout << " 大战 ";
    m->show_name();
    cout << endl;

    for (int i = 0; i < 5; i++) // 打 5 个回合
    {
        // 角色攻击
        int harm = p->attck();

        // 扣血
        if (m->hurt(harm) <= 0)
        {
            cout << "角色胜利！怪物死亡" << endl;
            return 0;
        }

        // 怪物攻击
        harm = m->attck();

        if (p->hurt(harm) <= 0)
        {
            cout << "怪物胜利！角色死亡" << endl;
            return 0;
        }
    }

    cout << "战斗结束，双方都未死亡" << endl;
}

int main()
{
    // 创建一个角色
    Swordm s(10, 200);
    Wizard w(1, 2000);

    role_pk_monster(&w, new Goblin(10, 1000));

    // 开始战斗
    // role_pk_monster(&s, new Slime(10, 10));

    // role_pk_monster(&s, new Goblin(10, 2000));
}