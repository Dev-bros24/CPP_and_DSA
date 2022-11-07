#include<iostream>
using namespace std;

class Complex{
    int a, b;
    public:
    Complex(int, int); // Constructor declaration
    void printData(void)
    {
        cout << "Your complex number is: " << a << " + " << b << " i" << endl;
    }
};

Complex :: Complex(int x, int y){ // This is a parameterized constructor as it takes 2 parameters.
    a = x;
    b = y;
}

int main(){
    //Implicit call
    Complex a(9, 6);
    a.printData();

    // Explicit call
    Complex b = Complex(7, 4);
    
    // Another way to write
    // Complex b;  // For now this declaration will give error as there should be a default constructor for an object declaration.
    // b = Complex(7, 4);

    b.printData();
    return 0;
}