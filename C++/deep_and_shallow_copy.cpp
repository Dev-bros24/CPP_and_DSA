#include<iostream>
using namespace std;

/*
How can we create a copy of object?
1. Copy constructor
2. Implicit copy assignment operator

Note: We can perform Deep Copy using both of the above

By default, the compiler creates a copy constructor as well as overloads a copy 
assignment operator inside the class definition.

--> If we initialize during the creation of the object, 
copy constructor is called.
--> If we initialize after the creation of the object, 
copy assignment operator is called.

Shallow copy --> Creating copy of object by copying data of all member variables
as it is.
Deep copy --> Creating an object by copying data of another object along with 
the values of memory resources resides outside the object but handled by that 
object. 

*/

class Dummy{
    private:
    int a, b;
    public:
    int *p;
    Dummy(){
        p = new int; // an int block of memory allocated to p
    }
    void set_Data(int x, int y, int z){
        a = x; 
        b = y;
        *p = z;
    }

    void get_Data(){
        cout<<"The values inside a is: "<<a<<" and b is: "<<b<<endl;
        cout<<"The value at address p: "<<p<<" is: "<<*p<<endl;
    }

    // Dummy(Dummy &d){ // This is Shallow Copy. If we don't write this constructor, then also compiler will create a similar constructor and perform shallow copy only.
    //     a = d.a;
    //     b = d.b;
    //     p = d.p;
    // }

    Dummy(Dummy &d){ // Deep Copy
        // int *x = new int;
        // *x = *(d.p);
        a = d.a;
        b = d.b;
        // p = x;
        p = new int;
        *p = *(d.p);
    }

    ~Dummy(){ // we want to delete the pointer p before the object gets deleted, because p contains a value that is outside the object.
        delete p;
    }
};

int main(){
    Dummy d1;
    d1.set_Data(3, 4 ,5);
    d1.get_Data();
    Dummy d2 = d1; 
    d2.get_Data();

    return 0;
}