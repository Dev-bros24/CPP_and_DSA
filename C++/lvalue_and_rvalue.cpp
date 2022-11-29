#include<iostream>
using namespace std;

// lvalues are variables that have some kind of storage backing them
// rvalues are temporary values

// lvalue references can only take an lvalue unless they're const
// rvalue references can only take in temporary rvalues

int GetValue(){
    return 10;
}

int& Getlvalue(){ // returning an lvalue reference
    static int value = 10;
    return value;
}

void SetValue(int value){

}

void SetrefValue(int& value){ // takes an lvalue reference

}

void SetconrefValue(const int& value){ // takes a const lvalue reference

}

void PrintName(string& name){
    // cout<<name<<endl;
}

void PrintconName(const string& name){
    // cout<<name<<endl;
}

void PrintrvaluerefName(string&& name){ // this takes an rvalue reference(&&)
    // cout<<name<<endl;
}

// Below are two overloaded functions, one which takes an const lvalue ref
// and the other takes an rvalue ref. But if a call will be made using an rvalue
// the second one will be preferred.

void Compatibility(const string& name){ // we made this compatible with both an lvalue and an rvalue
    cout<<"lvalue: "<<name<<endl;
}

void Compatibility(string&& name){
    cout<<"rvalue: "<<name<<endl;
}

int main(){

    int i = 10; // lvalue here is i that is having a location
    // in memory and r value is 10 which is just a numeric literal
    // it has no storage or location unless it is assigned to an 
    // l value.
    
    // 10 = i; // ofcourse doesn't work because we can't assign something to an rvalue.
    
    int a = i; // lvalue equal to an lvalue

    int p = GetValue(); // Getvalue is returning an rvalue here, as its
    // temporary, i.e. it has no location/storage. It's just the value 10
    // but here we are taking that temporary rvalue and storing it into an
    // lvalue.

    // GetValue() = 6; // we can't assign something to an rvalue.

    Getlvalue() = 6; // this works as it's returning an lvalue reference.

    // now we can call the set value function above with an rvalue or 
    // an lvalue.

    // int a = 9;
    SetValue(a);  // calling setvalue with an lvalue
    SetValue(9);  // calling setvalue with an rvalue

    // we can't take an lvalue reference from an rvalue. We can only
    // have an lvalue reference of an lvalue.

    SetrefValue(a);  // calling setvalue with an lvalue
    // SetrefValue(9);  // calling setvalue with an rvalue, but this gives
    // an error because we can't have an lvalue reference of an rvalue.

    // int& b = 10; // trying to set an lvalue ref to an rvalue.

    // but if it's a const lvalue ref, we can do this
    const int& b = 10; // this is totally fine, as internally compiler
    // will create a temporary storage like temp with a value 10 
    // and then assign it to the lvalue ref b. So, it assigns an rvalue
    // to a const lvalue ref.

    SetconrefValue(a);
    SetconrefValue(90); // works as we can assign rvalue to a const lvalue ref.

    // Everything on the left side in the below example is an lvalue and
    // Everything on the right side is an rvalue.
    string firstName = "Abhishek";
    string lastName = "Yadav";

    string fullName = firstName + lastName; // we are doing addition(appending) so on the right we have an rvalue, as a temporary string gets converted from these two and then it gets assigned into an lvalue.
    
    PrintName(fullName);
    // PrintName(firstName + lastName); // will not work as it's an rvalue

    PrintconName(fullName);
    PrintconName(firstName + lastName); // this works as const ref are
    // compatible with both temporarys(rvalues) and an actual real existing
    // variable(lvalues).

    // PrintrvaluerefName(fullname); // now this throws an error as it's an lvalue
    // and this function takes an rvalue reference of an rvalue only.

    PrintrvaluerefName(firstName + lastName);

    Compatibility(fullName);
    Compatibility(firstName + lastName); // will call rvalue ref function

    return 0;
}

/* 
Importance: 
use of && i.e. rvalue references
If we know that we are taking a temporary object, then we don't have
to worry about making sure that we keep it alive, making sure we keep 
it intact, making sure we copy it. We can simply steal the resources
that might be attached to that specific object and use them somewhere
else because we know that it's temporary and it's not going to exist
for very long.

whereas if we use const instead, we can't steal anything from the object
because it might be used in a number of functions whereas an rvalue is
clearly something temporary that is only going to be used with that 
particular function call.
*/

