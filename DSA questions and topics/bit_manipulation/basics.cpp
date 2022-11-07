#include<iostream>
using namespace std;


int main(){
    int a = 5;
    int b = 7;
    // int c = a | b;
    // int c = a & b;

    int c = a ^ b;

    int z = ~a;

    int y = a>>1;

    cout<<"Answer is: "<<c<<endl;
    cout<<"Negation of 5 : "<<z<<endl;
    cout<<"Right shift 1 of 5: "<<y<<endl;


    return 0;
}