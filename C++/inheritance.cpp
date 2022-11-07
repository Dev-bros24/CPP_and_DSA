#include<iostream>
using namespace std;

// Base class
class Employee{
    public:
    int id;
    float salary;
    Employee(int inpId){
        id = inpId;
        salary = 34.0;
    }
    Employee(){}
};

// Derived class syntax
/*
class {{Derived-class-name}} : {{visibility-mode}} {{base-class-name}}
{
    class members/methods/etc..
}
Notes:
1. Default visibility mode is private.
2. Public visibility mode: Public members of the base class will become public members of the derived class.
3. Private visibility mode: Public members of the base class will become private members of the derived class.
4. Private members are never inherited.
*/

// Creating a derived Programmer class from Employee base class 
class Programmer : Employee{
    public:
    int languageCode;
    Programmer(int inpId){ // Once we create a programmer object then during it's initialization it will try to call its constructor then default constructor of Employee as well, which is not present, so we have to create one.
        id = inpId;
       languageCode = 9;
    }
    void getData(void)
    {
        cout<<id<<endl;
    }
};

int main(){
    Employee harry(1), rohan(2);
    cout<<harry.salary<<endl;
    cout<<rohan.salary<<endl;
    Programmer skillF(10);
    cout<<skillF.languageCode<<endl;
    skillF.getData();
    return 0;
}

// Whenever we create an object of derived class, base class constructor gets called automatically.