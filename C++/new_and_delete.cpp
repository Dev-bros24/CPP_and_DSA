#include<iostream>
using namespace std;


int main(){
    // Basic example
    int a = 4;
    int *ptr = &a;
    cout<<"The value at address ptr is: "<<*(ptr)<<endl;

    // new keyword/operator
    // int *ptr2 = new int(40);
    float *ptr2 = new float(40.87);
    cout<<"The value at address ptr2 is: "<<*(ptr2)<<endl;

    int *arr = new int[3];
    arr[0] = 13;
    *(arr+1) = 12;
    arr[2] = 15;
    // delete[] arr;      // syntax for deleting the entire array OR dynamically
    // freeing the entire array

    cout<<"The value arr[0] is: "<<arr[0]<<endl;
    cout<<"The value arr[1] is: "<<arr[1]<<endl;
    cout<<"The value arr[2] is: "<<arr[2]<<endl;

    // delete keyword/operator


    return 0;
}