#include<iostream>
#include<functional>
#include<algorithm>
using namespace std;

/*
Function objects (Functor): Function wrapped in a class so 
that it is available like an object. 
*/

int main(){
    int arr[] = {74, 2, 54, 34, 49, 16};
    for(int i=0; i<6; i++){
        cout<<arr[i]<<" ";
    }
    // sort(arr, arr+5);
    sort(arr, arr+6, greater<int>());
    cout<<endl;
    for(int i=0; i<6; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}