#include<iostream>
using namespace std;

/*
If function calling is getting known at compile time --> Static binding
If function calling is getting known ar runtime --> Dynamic Binding

If we call the function from a Base class pointer that is pointing to derived class object
then at runtime this decision takes place and this is known as Dynamic binding.
*/

class BaseClass{
    public:
    int var_base = 1;
    virtual void Display(){   // virtual is saying if base class pointer points at a derived class object, then run it's function only while accessing it through this base class pointer
        cout<<"1 Displaying base class variable var_base: "<<var_base<<endl;
    }
};

class DerivedClass : public BaseClass{
    public:
    int var_derived = 2;
    void Display(){  
        cout<<"2 Displaying base class variable var_base: "<<var_base<<endl;
        cout<<"2 Displaying base class variable var_derived: "<<var_derived<<endl;
    }
};

int main(){
    BaseClass *base_class_pointer;
    BaseClass obj_base;
    DerivedClass obj_derived;

    base_class_pointer = &obj_derived;
    base_class_pointer->Display();

    return 0;
}