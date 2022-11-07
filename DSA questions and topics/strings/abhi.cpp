#include<iostream>
#include<string.h>
using namespace std;


int main(){
    int val = 'C' - 'A';

    string s = "Abhishek";
    string st = s.substr(0,4);
    cout<<"Entire string is: "<<s<<"\nIt's substring is: "<<st<<endl;
    // cout<<val;

    return 0;
}