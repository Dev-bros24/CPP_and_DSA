#include<iostream>
using namespace std;

void swap(int a, int b) // this will not swap the variables
{
    int temp = b;
    b = a;
    a = temp;
}

void swapPointer(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

// int &
void swapReferenceVar(int &a, int &b)
{
    
    int temp = b;
    b = a;
    a = temp;
    // return a;
}

int main(){
    int x = 4, y = 5; 
    cout<<"The value of x is "<<x<<" and the value of y is "<<y<<endl;
    //swap(x,y); // this will not swap the variables
    //swapPointer(&x, &y); // This will swap a and b using pointer reference
    swapReferenceVar(x, y); // This will swap a and b using reference variables
    // swapReferenceVar(x, y) = 766; 
    cout<<"The value of x is "<<x<<" and the value of y is "<<y;

    return 0;
}

// x and y are actual arguments and a and b are formal arguments