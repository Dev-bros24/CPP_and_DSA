#include<iostream>
using namespace std;

int XOR_till_N(int n)
{
    if(n % 4 == 0)
    {
        return n;
    }
    else if(n % 4 == 1)
    {
        return 1;
    }
    else if(n % 4 == 2)
    {
        return n+1;
    }
    else if(n % 4 ==3)
    {
        return 0;
    }
}

int main()
{
    int l, r; 
    cout<<"Enter the range of numbers of which you want the XOR: "<<endl;
    cin>>l>>r;

    int value = XOR_till_N(r) - XOR_till_N(l-1);

    cout<<"Answer: "<<value<<endl;

    return 0;
}