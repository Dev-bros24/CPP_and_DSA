#include<iostream>
#include"abhi.h"   /*This is how we include a user defined header file*/
using namespace std;


int sum(int a, int b)
{
    return a+b;
}

int main()
{
    int a = 0, b = 0;
    cout<<"Enter any value ";
    cin>>a;
    cout<<"Enter another number ";
    cin>>b;
    cout<<"The sum of these numbers is: "<< sum(a,b)<<endl;
    cout<<"The multiplication of these numbers is: "<<mul(a,b);
    
    return 0;
}
