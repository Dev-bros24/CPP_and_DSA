#include <iostream>
using namespace std;

// Forward declaration
class complex;

class Calculator
{
public:
    int add(int n1, int n2)
    {
        return n1 + n2;
    }
    // int sumRealComplex(complex o1, complex o2){  // if we define the function here then also the compiler will give error as it does know about the class complex that it is there but it doesn't know about the contents inside it i.e. a and b etc.
    //         return (o1.a + o2.a);                // so we need to just give the declaration here and define it after we have the definition of complex class.
    // }
    int sumRealComplex(complex, complex);
    int sumCompComplex(complex, complex);
};

class complex
{
    int a, b;

public:
    // Individually declaring functions as friends
    // friend int Calculator ::sumRealComplex(complex, complex);
    // friend int Calculator ::sumCompComplex(complex, complex);

    // Aliter: Declaring the entire Calculator class as friend 
    friend class Calculator;
    
    void inData(int a1, int b1)
    {
        a = a1;
        b = b1;
    }
    void printData(void)
    {
        cout << "Your complex number is: " << a << " + " << b << " i" << endl;
    }
};

int Calculator ::sumRealComplex(complex o1, complex o2)
{
    return (o1.a + o2.a);
}

int Calculator ::sumCompComplex(complex o1, complex o2)
{
    return (o1.b + o2.b);
}

int main()
{
    complex o1, o2;
    o1.inData(1, 4);
    o2.inData(5, 7);
    Calculator calc;
    int res = calc.sumRealComplex(o1, o2);
    cout << "The sum of real part of o1 and o2 is: " << res << endl;
    int resc = calc.sumCompComplex(o1, o2);
    cout << "The sum of imaginary part of o1 and o2 is: " << resc << endl;
    return 0;
}