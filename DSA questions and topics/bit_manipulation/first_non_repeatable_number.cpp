#include<iostream>
using namespace std;

int main(){
    int a[9] = {1, 1, 2, 2, 3, 4, 4, 5, 5};
    int n = 9;

    int index = 0;
    int number = 0;

    for(int i=0; i<n; i = i+2)
    {
        if(a[i] ^ a[i+1])
        {
            index = i;
            number = a[i];
            break;
        }
    }

    cout<<"Number is: "<<number<<" at position: "<<index+1;

    return 0;
}