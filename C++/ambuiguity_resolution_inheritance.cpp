#include<iostream>
using namespace std;

class Base1{
    public:
        void greet()
        {
            cout<<"How are you?"<<endl;
        }
};

class Base2{
    public:
        void greet()
        {
            cout<<"Kaise ho?"<<endl;
        }
};

class Derived : public Base1, public Base2{
    int a;
    public:
        void greet()
        {
            Base2 :: greet();  // This denotes that use this class's greet function whenever a call is made from the object of Derived class for this greet function.
        }
};

class B{
    public:

        void say()
        {
            cout<<"Hello World"<<endl;
        }
};

class D : public B{
    public:

        void say() // This say() overwrites the Base class's say()(the overridden function) function automatically
        {
            cout<<"Hello my beautiful people"<<endl;
        }
};

int main(){
    // Ambuiguity 1
    // Base1 base1obj;
    // Base2 base2obj;
    // base1obj.greet();
    // base2obj.greet();

    // Derived d;
    // d.greet();

    // Ambiguity 2
    B b;
    b.say();
    D d;
    d.say();

    return 0;
}