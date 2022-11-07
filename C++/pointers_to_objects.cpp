#include<iostream>
using namespace std;

class Complex{
    int real, imaginary;
    public:
    void setData(int a, int b)
    {
        real = a;
        imaginary = b;
    }
    void getData()
    {
        cout<<"The real part is: "<<real<<endl;
        cout<<"The imaginary part is: "<<imaginary<<endl;
    }
};

int main(){
    // Complex c1;
    // Complex *ptr = &c1;

    Complex *ptr = new Complex;

    // c1.setData(24, 3);
    // c1.getData();

    // (*ptr).setData(24, 3);
    // (*ptr).getData();

    // Below is exactly same as above
    // ptr->setData(29, 3);
    // ptr->getData();

    Complex * ptr1 = new Complex[4];

    ptr1->setData(2, 4);
    ptr1->getData();

    return 0;
}