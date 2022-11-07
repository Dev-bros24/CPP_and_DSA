#include<iostream>
using namespace std;

void non_repeating(int a[],int n,  int &number)
{
    for(int i=0; i<n; i++)
    {
        number = number ^ a[i];
    }
}

int main(){
    int a[9] = {14, 15, 87, 11, 5, 11, 87, 15, 14};
    int number = 0;

    non_repeating(a, 9, number);
    
    cout<<"Answer: "<<number;

    return 0;
}