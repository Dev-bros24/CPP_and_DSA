#include<iostream>
using namespace std;

int factorial(int n)
{
    int fact = 1;
    if(n > 1)
    {
    return n * factorial(n-1); 
    }
    return fact;
}

int main(){
    int n, fact = 1;
    cout << "Enter the number of which you want the factorial: "<<endl;
    cin>>n;
    fact = factorial(n);
    cout<<"The factorial is : "<<fact<<endl;
    
    return 0;
}