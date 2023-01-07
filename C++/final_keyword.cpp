#include<iostream>
using namespace std;

/*
    Final keyword can be used with:
    1. variables
    2. methods
    3. class
*/

// class Base final{ // this class with final keyword cannot be inherited in another derived class
class Base{ 
    int a;
    public:
    // virtual void disp() final{  // this function with final keyword cannot be overridden in derived class
    void disp(){
        cout<<"Base class function"<<endl;
    }
};

class Derived : public Base{
    int b;
    public:
    virtual void disp(){
        cout<<"Derived class function"<<endl;
    }
};

class Derived2 : public Derived{
    int c;
    public:
    void disp(){
        cout<<"Derived 2 class function"<<endl;
    }
};

int main(){
    // Derived *obj_derived = new Derived;
    // Base *obj_base = obj_derived;

    // or in one line
    // Base *obj_base = new Derived;

    Base *obj_base = new Derived2; // Derived 2's function will be called
    obj_base->disp();
    
    // Derived *obj_derived = new Derived2; 
    // obj_derived->disp();

    return 0;
}