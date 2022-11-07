/*

If base class constructor does not have any arguments, there is no need
of any constructor in derived class.
If both base and derived classes have constructors, base class constructor is 
executed first.

In multiple inheritance, base classes are constructed in the order in which
they appear in the Derived class declaration.
In multilevel inheritance, the constructors are executed in the order
of inheritance.

The Constructors for Virtual base class are invoked before a Non-Virtual 
base class.
If there are multiple Virtual base classes, they are invoked in the 
order declared.
Any non-virtual base class are then constructed before the derived class
is executed.

*/


/*
Case1:
class B: public A{
   Order of execution of constructor -> first A() then B()
};

Case2:
class A: public B, public C{
   Order of execution of constructor -> B() then C() and A()
};

Case3:
class A: public B, virtual public C{
   Order of execution of constructor -> C() then B() and A()
};
*/

#include<iostream>
using namespace std;

class Base1{
    int data1;
    public:
    Base1(int a){
        data1 = a;
        cout<<"Base1 constructor called"<<endl;
    }
    void printdataBase1()
    {
        cout<<"The value of data1 is: "<<data1<<endl;
    }
};

class Base2{
    int data2;
    public:
    Base2(int a){
        data2 = a;
        cout<<"Base2 constructor called"<<endl;
    }
    void printdataBase2()
    {
        cout<<"The value of data2 is: "<<data2<<endl;
    }
};

class Derived : public Base1, public Base2{ // This decides order of execution of constructors
    int derived1, derived2;
    public:
    Derived(int a, int b, int c, int d):Base1(a), Base2(b){  // This does not decide order of execution of constructors
        derived1 = c;
        derived2 = d;
        cout<<"Derived class constructor called"<<endl;
    }

    void printdataDerived(){
        cout<<"The value of derived1 is: "<<derived1<<endl;
        cout<<"The value of derived2 is: "<<derived2<<endl;
    }
};

int main(){
    Derived Abhi(1, 2, 3, 4);
    Abhi.printdataBase1();
    Abhi.printdataBase2();
    Abhi.printdataDerived();
    return 0;
}