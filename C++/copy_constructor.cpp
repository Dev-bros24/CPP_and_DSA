#include<iostream>
using namespace std;

class Number{
    int a;
    public:
    Number(){
        a = 0;
    }
    Number(int value){
        a = value;
    }

// When no copy constructor is found, compiler supplies its own copy constructor.
    Number(Number& obj){
        cout<<"Copy constructor called!!!"<<endl;
        a =  obj.a;
    }

    void display(void);

    // Number& operator = (Number& num){
    //     cout<<"Assignment operator called!!"<<endl;
    //     this->a = num.a;
    //     return *this;
    // }
};

void Number :: display(void){
    cout<<"The number associated with this object is: "<<a<<endl;
}

int main(){
    Number x, y(34), z(55), xcp;
    x.display();
    y.display();
    z.display();

    Number cp(z); // Copy constructor invoked, since the object is getting declared here itself
    cp.display();

    Number ycp = y; // Copy constructor invoked
    ycp.display();

    xcp = z; // Copy constructor not called as we have already made this object and just did assignment here.
    xcp.display();

    return 0;
}