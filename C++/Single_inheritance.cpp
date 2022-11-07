#include <iostream>
using namespace std;

class Base
{
    int data1; // private by default and is not inheritable
public:
    int data2;
    void setData();
    int getData1();
    int getData2();
};

void Base ::setData(void)
{
    data1 = 10;
    // cout<<"Abhishek data 1: "<<data1<<endl;
    data2 = 20;
}

int Base ::getData1(void)
{
    return data1;
}

int Base ::getData2(void)
{
    return data2;
}

class Derived : public Base
{ // Class is being derived publically
    int data3;

public:
    void Process();
    void Display();
};

void Derived ::Process()
{
    data3 = data2 * getData1();
}

void Derived ::Display()
{
    cout << "The value of data1 is: " << getData1() << endl;
    cout << "The value of data2 is: " << data2 << endl;
    cout << "The value of data3 is: " << data3 << endl;
}

int main()
{
    Derived der;
    der.setData();
    der.Process();
    der.Display();
    cout << "Print " << der.getData1() << endl;

    return 0;
}