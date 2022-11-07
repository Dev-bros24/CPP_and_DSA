#include<iostream>
using namespace std;

/*
Syntax for initialization list in constructors:
constructor (argument-list) : initialization-section
{
    assignment + other code;
}
*/

class Test{
    int a;
    int b; // Because a is declared first, a will be initialized first

    public:
    // Test(int i, int j): a(i), b(j)
    Test(int i, int j): a(i), b(j + i)
    // Test(int i, int j): a(i), b(2 * j)
    // Test(int i, int j): a(i), b(a + j)
    // Test(int i, int j): b(j), a(i + b) This will give a random value for a as it
    // will be initialized first and it contains b(currently garbage) in it.
    {
        cout<<"Constructor executed"<<endl;
        cout<<"Value of a is: "<<a<<endl;
        cout<<"Value of b is: "<<b<<endl;
    }
};

int main(){
    Test(5, 7);

    return 0;
}