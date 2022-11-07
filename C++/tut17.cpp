#include<iostream>
using namespace std;

// inline int product(int a,int b){
//     return a*b;
// }

inline int product(int a, int b){
    // *** In Inline functions, static variables are not recommended.
    // static int c = 0; // static means that here in this function this value of c will be 
    // // initialised only once and from next time onwards it will retain it's value, like here 
    // // the first time the  value of c becomes 1 so next time it will continue from value 1 only.
    // // all other variables functions doesn't remember after the call but static variables it 
    // // remembers.
    // c = c + 1; 
    return a*b;
}

// for inline functions, compiler also checks at it's end whether the function should be made 
// inline or not. Then only it makes it inline.

float moneyReceived(int currentMoney, float factor = 1.04){  // This is default argument
    return currentMoney*factor;
}

// int strlen(const char *p){

// } 
// now this p string will be never changed inside the function. So, we use const keyword when
// we don't want the value of an argument to be changed inside a function anyhow. This is significant 
// mostly for reference variables and pointers.

int main(){
    int a, b, Money;
    // cout<<"Enter two numbers:"<<endl;
    // cin>>a>>b;
    // cout<<"The product of a and b is: "<<product(a, b)<<endl;
    cout<<"Enter the amount: "<<endl;
    cin>>Money;
    cout<<"if you have: "<<Money<<" in your bank account, you will receive "<<moneyReceived(Money)<<" after 1 year";
    cout<<"\n For VIP, if you have: "<<Money<<" in your bank account, you will receive "<<moneyReceived(Money, 1.1)<<" after 1 year";
    return 0;
}


// Now, when we call a small function multiple times we can use inline functions because in case 
// of inline functions actual arguments are not copied to formal and then after processing the value
// is returned, rather the entire definition of the function is replaced where the call is at runtime.
// But we should use it for small functions only as in case of large functions it will take
// a lot of memory.

// all default arguments should be at right hand side of a function's definition.



