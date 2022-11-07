#include<iostream>
using namespace std;

/*
CLASS TEMPLATES WITH MULTIPLE PARAMETERS (ONE, TWO OR MORE THAN TWO)
template<class T1, class T2 ....>
class nameOfclass{
    // class body
};
*/

template <class T1, class T2, class T3>   // T1, T2 and T3 can be class as well
class Simple{
    T1 a;
    T2 b;
    T3 c;

    public:
    Simple(T1 x, T2 y, T3 z)
    {
        a = x;
        b = y;
        c = z;
    }
    void Display(){
        cout<<"The value of a is: "<<this->a<<endl;
        cout<<"The value of b is: "<<this->b<<endl;
        cout<<"The value of c is: "<<this->c<<endl;
    }
};

int main(){
    Simple<char, float, int> s1('a', 6.57, 7);
    s1.Display();

    return 0;
}