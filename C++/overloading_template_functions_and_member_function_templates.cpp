#include<iostream>
using namespace std;

template<class T>
class Abhi{
    public:
    T data;
    Abhi(T a){
        data = a;
    }
    void Display();
};

template <class T>
void Abhi<T> :: Display(){
    cout<<data;
}


void func(int a){
    cout<<"I am first func() "<<a<<endl;
}

template<class T>
void func(T a){
    cout<<"I am templatized 1 func() "<<a<<endl;
}

template<class T>
void func1(T a){
    cout<<"I am templatized 2 func() "<<a<<endl;
}




int main(){
    // Abhi<float> a(4.76);
    // Abhi<char> a('z');
    // cout<<a.data<<endl;
    // a.Display();

    func(4.2);  // Exact match takes the highest priority
    func1(4);

    return 0;
}