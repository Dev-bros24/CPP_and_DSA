#include<iostream>
using namespace std;

/*
When an operator is overloaded with multiple jobs, it is known as operator overloading.
It is a way to implement Compile time polymorphism.

Any symbol can be used as a function name
--> If it is a valid operator in C language.
--> If it is preceded by operator keyword.
--> We can't overload "sizeof" and "?:" operator.
*/

class Complex{
    private:
    int a;
    int b;

    public:
        void setData(int x, int y){
            a = x;
            b = y;
        }
        void getData(){
            cout<<"The value of a: "<<a<<" and the value of b: "<<b<<endl;
        }

        // Complex add(Complex c){
        //     Complex temp;
        //     temp.a = this->a + c.a;
        //     temp.b = this->b + c.b;
        //     return temp;
        // }

        // Overloading of Binary operator
        Complex operator + (Complex c){ // this is an extension of the function mentionted above, we are using operator "+" as a function name
            Complex temp;
            temp.a = this->a + c.a;
            temp.b = this->b + c.b;
            return temp;
        }

        // Overloading of Unary operator
        Complex operator - (){
            Complex temp;
            temp.a = -a;
            temp.b = -b;
            return temp;
        }
};

// Class to overload increment operators, post and pre
class Integer{
    private:
    int x;
    public:
    void setData(int a){
        x = a;
    }
    void showData(){
        cout<<"x: "<<x<<endl;
    }
    Integer operator ++(){  // Preincrement
        Integer i;
        i.x = ++x;
        return i;
    }
    Integer operator ++(int){ // Postincrement --> this int argument is just to indicate that it's post increment overloading
        Integer i;
        i.x = x++;
        return i;
    }
};

int main(){
    Complex c1, c2, c3;
    c1.setData(3, 5);
    // c2.setData(7, 8);
    // // c3 = c1.add(c2); // we are calling add() with object c1 and passing c2 in it. 
    // c3 = c1 + c2; // c3 = c1.operator+(c2);   --> these both are same, i.e. we are calling function named "operator+" which is being called by c1, with c2 as argument and the output is getting stored in c3.

    // // We don't need to use the dot keyword if the called member function is an operator symbol
    // c3.getData();

    /*
    c2 = -c1;   // c2 = c1.operator-();  // the way we write this is the sign is put before the caller object, as that is the behaviour of this unary operator in C/C++ language.
    c2.getData();
    */

   Integer i1, i2;
   i1.setData(4);
//    i1.showData();
    i2 = i1++; 
    // i2 = ++i1; // this is same as i2 = i1.operator++();
    i1.showData();
    i2.showData();

    return 0;
}