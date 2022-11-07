#include<iostream>
using namespace std;

/*

A pointer of base class can point an object of derived class but the function
will be called of base class only because the pointer is of base class.
This is called late binding as the decision is made at runtime that which function will be called
for which particular object. 

If a base class pointer is pointing to a derived class object then only the properties
or methods which are inherited from base class into derived can be accessed directly 
using that pointer.

*/

class BaseClass{
    public:
    int var_base;
    void Display(){
        cout<<"Displaying base class variable var_base: "<<var_base<<endl;
    }
};

class DerivedClass : public BaseClass{
    public:
    int var_derived;
    void Display(){
        cout<<"Displaying base class variable var_base: "<<var_base<<endl;
        cout<<"Displaying base class variable var_derived: "<<var_derived<<endl;
    }
};

int main(){
    BaseClass *base_class_pointer;
    BaseClass obj_base;
    DerivedClass obj_derived;
    base_class_pointer = &obj_derived; // Pointing base class pointer to derived class

    base_class_pointer->var_base = 34;
    // base_class_pointer->var_derived = 134; --> Invalid, will throw an error
    base_class_pointer->Display();

    base_class_pointer->var_base = 3400;
    base_class_pointer->Display();

    DerivedClass *derived_class_Pointer;
    derived_class_Pointer = &obj_derived;
    derived_class_Pointer->var_base = 9448;
    derived_class_Pointer->var_derived = 98;
    derived_class_Pointer->Display();

    return 0;
}