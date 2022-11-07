#include<iostream>
using namespace std;

class A{
    int a;
    public:
    void setData(int a)
    // A & setData(int a)  // this function will return the reference of this pointer
    // A setData(int a)
    {
        this->a = a;
        // return *this;
    }
    void getData(){
        cout<<"The value of a is: "<<a<<endl;
    }
};

int main(){

    // this is a keyword which is a pointer which points to the object which
    // invokes the member function.
    A obj1;
    obj1.setData(4);
    // obj1.setData(4).getData();  // when setData returns *this.
    obj1.getData();

    return 0;
}