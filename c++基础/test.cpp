#include <iostream>

// #include <string.h>

using namespace std;
class obj
{
public:
    int i = 10;

    obj()
    {

        // i = j;
        cout << "i=" << i << endl
             << "j=" << j << endl;
        // j = k;
    }

    void trs(int &i);
    void print(void)
    {
        cout << "i=" << i << endl
             << "j=" << j << endl;
    }
protected:
private:
    int j = 10;
};




void obj ::trs(int &i)
{
    cout << "i=" << i << endl;
}




class mytime
{
private:
    int m_iHour;
    int m_iMin;
    int m_iSec;
    /* data */
public:
    void set(int hour, int min, int sec) 
    {   
        m_iHour = hour;
        m_iMin = min;
        m_iSec = sec;
    }
    void display(){
        cout<<"hour="<<m_iHour<<" min="<<m_iMin<<" sec="<<m_iSec<<endl;
    }
};

class coordinate
{
private:
   double mdX;
   double mdY;


    /* data */
public:

    void set(double x, double y){
        mdX = x;
        mdY = y;
    }
    void setX(double x){
        mdX = x;
    }
    void setY(double y){
        mdY = y;
    }
    double &getX(){
        return mdX;
    }
    double &getY(){

        return mdY;
    }
};








int main()
{
    obj a;
    ;
    obj *p;
    p = &a;
    p->i = 100;
    p->trs(p->i);
    p->print();

    return 0;
}