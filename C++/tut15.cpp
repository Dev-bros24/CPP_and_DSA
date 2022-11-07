#include<iostream>
using namespace std;

// function prototype
// int sum(int f, int g); // acceptable
// int sum(int a, int b); // acceptable
// int sum(int a, b); // Not acceptable
int sum(int , int ); // acceptable
void g(void); //Acceptable
void g(); //Acceptable

int main(){
    int num1, num2;
    cout<<"Enter first number:"<<endl;
    cin>>num1;
    cout<<"Enter second number:"<<endl;
    cin>>num2;
    cout<<"the sum is: "<<sum(num1, num2);
    return 0;
}

int sum(int a, int b)
{
    int c = a+b;
    return c;
}