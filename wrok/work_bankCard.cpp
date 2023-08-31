// 【4】设计三个类：card,cashCard和creditCard,实现以下功能
// card(卡)是抽象基类，有如下成员：
// 数据：发卡行名称、户名、卡号

// 方法：查询(enquiry)、存款(deposit)、取款(withdraw)

// cashCard(储蓄卡)是卡的派生类，新增成员：
// 数据：余额(balance)
// creditCard(信用卡)也是卡的派生类，新增成员：
// 数据：额度(limit)、手续费率(interestRate)、债务(debt)
// 方法：设置手续费率(setRate)

// 储蓄卡和信用卡都可以无限存入(deposit)款项，但储蓄卡只能取出(withdraw)小于等于余额(balance)的款项，
// 而信用卡可以透支从而形成债务(debt),同时债务不能超过当前额度((imit),透支金额按每笔interestRate的手
#include <iostream>
#include <string.h>
using namespace std;
class card
{
public:
    card(const char *bank = "银行", const char *name = "张三", const char *number = "1234567890123456789")
    {
        strcpy(this->bank, bank);
        strcpy(this->name, name);
        strcpy(this->number, number);
    }
    virtual void enquiry() = 0;
    virtual void deposit(int) = 0;
    virtual void withdraw(int) = 0;

protected:
    char bank[100];
    char name[100];
    char number[100];
};

class cashCard : public card
{
public:
    cashCard(const char *bank = "银行", const char *name = "张三", const char *number = "1234567890123456789", int balance = 0) : card(bank, name, number)
    {
        this->balance = balance;
    }
    void enquiry()
    {
        cout << "卡号：" << this->number << endl;
        cout << "发卡行：" << this->bank << endl;
        cout << "卡主：" << this->name << endl;
        cout << "余额：" << this->balance << endl;
    }
    void deposit(int amount)
    {
        this->balance += amount;
    }
    void withdraw(int amount)
    {
        if (this->balance >= amount)
        {
            this->balance -= amount;
        }
        else
        {
            cout << "余额不足！" << endl;
        }
    }

private:
    int balance;
};

class creditCard : public card
{
private:
    int limit;
    float interestRate;
    int debt;

public:
    creditCard(const char *bank = "银行", const char *name = "张三", const char *number = "1234567890123456789", int limit = 1000, float interestRate = 0.1, int debt = 0) : card(bank, name, number)
    {
        this->limit = limit;
        this->interestRate = interestRate;
        this->debt = debt;
    }
    void enquiry()
    {
        cout << "卡号：" << this->number << endl;
        cout << "发卡行：" << this->bank << endl;
        cout << "卡主：" << this->name << endl;
        cout << "额度：" << this->limit << endl;
        cout << "利率：" << this->interestRate << endl;
        cout << "欠款：" << this->debt << endl;
    }
    void withdraw(int amount)
    {
        if (this->debt + amount + amount * interestRate <= this->limit)
        {

            this->debt += (amount + amount * interestRate);
        }
        else
        {
            cout << "额度不足！" << endl;
        }
    }
    void deposit(int amount)
    {
        this->debt -= amount;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    cashCard c1("邮政银行", "张三", "1234567890123456789", 1000);
    c1.enquiry();
    cout << "*************" << endl;
    c1.withdraw(1000);
    c1.enquiry();
    cout << "*************" << endl;
    c1.deposit(1000);
    c1.enquiry();
    cout << "*************" << endl;
    creditCard c2("中国银行", "张三", "1234567890123456789", 1000, 0.1, 0);
    c2.enquiry();
    cout << "*************" << endl;
    c2.withdraw(1000);
    c2.enquiry();
    cout << "*************" << endl;
    c2.deposit(1000);
    c2.enquiry();
    cout << "*************" << endl;
    c2.withdraw(50);
    c2.enquiry();

    return 0;
}
