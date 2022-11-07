#include<iostream>
using namespace std;

class Base{
    protected:
    int a = 7;  // Protected are like private data members, it's just they can be inherited.
    private:
    int b;
    
};

class Derived : protected Base{
    // public:
    // void print();
};

// void Derived :: print()
// {
//     cout<<a;
// }

/*
                            Public derivation       Private derivation      Protected derivation
    1. Private members      Not Inherited           Not Inherited           Not Inherited
    2. Protected members    Protected               Private                 Protected
    3. Public members       Public                  Private                 Protected
*/


int main(){
    Base b;
    Derived d;
    // d.print(); 
    // cout<<d.a;// This will not work since a is protected in both Base as well as Derived class.
    return 0;
}