#include<iostream>
using namespace std;


int main(){
    int num, i=0;
    cout<<"Enter the decimal number: "<<endl;
    cin>>num;
    int arr[250];
    do
    {
        arr[i++] = num % 2;
        num = num / 2;
        // num = quo;
    }while(num != 0);
    cout<<"Your binary number is"<<endl;
    for(int j = i-1 ; j>=0; j--)
    {
        cout<<arr[j]<<" ";
    }
    return 0;
}