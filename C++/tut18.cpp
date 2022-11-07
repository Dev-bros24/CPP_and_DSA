#include<iostream>
using namespace std;

int fib(int a){
    if(a<=0){
        cout<<"Invalid number";
        exit(0);
    }
    else if(a<=2){
        return 1;
    }
    else{
        return (fib(a-1) + fib(a-2));
    }
}

int main(){
    int a;
    cout<<"Enter the term of the fibonacci series that you want:"<<endl;
    cin>>a;
    cout<<"The term at "<<a<<"th position in fibonacci series is "<<fib(a);    
    return 0;
}