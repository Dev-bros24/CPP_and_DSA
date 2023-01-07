#include<iostream>
using namespace std;

/*
Constructor can never be static
*/

class Complex{
    int a, b;
    public:
    // Creating a constructor
    // Constructor is a special member function with the same name as of the class. 
    // It is automatically invoked whenever an object is created.
    // It is used to initialize the objects of its class.
    Complex(void); // Constructor declaration
    void printData(void)
    {
        cout << "Your complex number is: " << a << " + " << b << " i" << endl;
    }
};

Complex :: Complex(void){ // This is a default constructor as it does not accept any parameters.
    a = 0;
    b = 0;
    // cout<<"Hello world"<<endl;
}

int main(){
    Complex c1, c2, c3;
    c1.printData();
    c2.printData();
    c3.printData();
    return 0;
}

// Characteristics of constructors:

// 1. It should be declared in the public section of the class.
// 2. They are automatically invoked whenever the object is created.
// 3. They cannot return values and do not have return types. (not even void)
// 4. It can have default arguments.
// 5. We cannot refer to their address.
