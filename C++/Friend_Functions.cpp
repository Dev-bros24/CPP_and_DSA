#include<iostream>
using namespace std;

//Friend function has access to the private parts of the class of which it is friend.

class complex{
    int a, b;
    public:
        friend complex diffComplex(complex, complex);
        void inData(int a1, int b1)
        {
            a = a1;
            b = b1;
        }
        void printData(void)
        {
            cout<<"Your complex number is: "<<a<<" + "<<b<<" i"<<endl;
        }
        complex sumComplexnum(complex , complex);
        
};

// Forward declaration
class Y;

class X {
    int num;
    public:
        int setValue(int value)
        {
            num = value;
        }
        friend int add(X, Y); // We gave forward declaration above because otherwise compiler will not be able to find Y here and will be stuck.
        friend void exchange(X &, Y &);
        void dispValue()
        {
            cout<<"The value stored in object of class X is: "<<num<<endl;
        }
        
};

class Y {
    int num;
    public:
        int setValue(int value)
        {
            num = value;
        }
        friend int add(X, Y);
        friend void exchange(X &, Y &);
        void dispValue()
        {
            cout<<"The value stored in object of class Y is: "<<num<<endl;
        }
};

int add (X o1, Y o2)
{
    return o1.num + o2.num;
}

void exchange(X &p, Y &q)
{
    int temp = p.num;
    p.num = q.num;
    q.num = temp;
}

complex complex :: sumComplexnum(complex o1, complex o2)
{
    complex o3;
    o3.a = o1.a + o2.a;
    o3.b = o1.b + o2.b;
    return o3;
}

complex diffComplex (complex o1, complex o2)
{
    complex o3;
    o3.a = o1.a - o2.a;
    o3.b = o1.b - o2.b;
    return o3;
}



int main(){
    int l, m, p, q;
    complex z1, z2;
    // cout<<"Enter the real part of your first complex number "<<endl;
    // cin>>l;
    // cout<<"Enter the imaginary part of your first complex number "<<endl;
    // cin>>m;
    // cout<<"Enter the real part of your second complex number "<<endl;
    // cin>>p;
    // cout<<"Enter the imaginary part of your second complex number "<<endl;
    // cin>>q;

    // z1.inData(l, m);
    // z1.printData();
    // z2.inData(p, q);
    // z2.printData();
    // complex z3 = z2.sumComplexnum(z1, z2);
    // z3.printData();
    // complex z4 = diffComplex(z1, z2);
    // z4.printData();
    X x1;
    Y y1;
    x1.setValue(4);
    x1.dispValue();
    y1.setValue(8);
    y1.dispValue();

    exchange(x1, y1);
    cout<<"The values after interchange"<<endl;
    x1.dispValue();
    y1.dispValue();


    // int sum = add(x1, y1);
    // cout<< "The sum of the numbers is : "<<sum<<endl;


    return 0;
}