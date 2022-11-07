#include<iostream>
#include<iomanip>  // for setw manipulator 
// other manipulator is endl
using namespace std;

int main()
{
    int a=45, b=123, c=7809;

    cout<<"The value of a without setw is: "<<a<<endl;
    cout<<"The value of b without setw is: "<<b<<endl;
    cout<<"The value of c without setw is: "<<c<<endl;

    cout<<"The value of a is: "<<setw(4)<<a<<endl;
    cout<<"The value of b is: "<<setw(4)<<b<<endl;
    cout<<"The value of c is: "<<setw(4)<<c;
//setw(4) will make sure that the variable to be printed takes at least 4 spaces width
}
