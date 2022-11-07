#include<iostream>
using namespace std;

int main(){
    int a = 5, b = 6;

    cout<<"a: "<<a<<" b: "<<b<<endl;

    a = a^b;  // a = 5^6 , b = 6
    b = a^b;  // a = 5^6 , b = 5^6^6 = 5
    a = a^b;  // a = 5^6^5 = 6 , b = 5

    cout<<"After swapping: "<<endl;
    cout<<"a: "<<a<<" b: "<<b<<endl;
    
    return 0;
}