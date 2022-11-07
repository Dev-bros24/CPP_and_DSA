#include<iostream>
using namespace std;

template<class T1=int, class T2=float, class T3=char>  // Default template parameters
class Simple{
    public:
    T1 a;
    T2 b;
    T3 c;
    Simple(T1 a, T2 b, T3 c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
    void Display(){
        cout<<"The value of a is: "<<a<<endl;
        cout<<"The value of b is: "<<b<<endl;
        cout<<"The value of c is: "<<c<<endl;
    }
};

int main(){
    Simple<> s1(4, 6.78, 'a');
    s1.Display();
    cout<<endl;

    Simple<char, char, int> s2('a', 'v', 8);
    s2.Display();

    return 0;
}