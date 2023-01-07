#include<iostream>
using namespace std;

/*
class --> object
template --> class 

Above means that for an object template is class and for a class template is
template.

1. Class is a blueprint for an object
2. Template is a blueprint for a class

Templates are also known as parameterized classes

Why use templates:
1. Follow DRY principle. (Do not Repeat Yourself)
2. Generic Programming. (Class becomes general for any data type)

Syntax for templates:

template<class T>   // T can be int, float, char etc.
class vector{
    T* arr; 
    public:
    vector(T* ar){
        // code
    }
    // & many other methods
}

This above represents many classes

*/
template <class T>
class vector{
    public:
    T *arr;
    int size;
    vector(int m){
        size = m;
        arr = new T[size];
    }
    T dotproduct(vector v){
        T ans = 0;
            for(int i=0; i<size; i++){
                ans += this->arr[i] * (v.arr[i]);
            }
            return ans;
    }
};

int main(){
    // vector v1(3);
    // v1.arr[0] = 2;
    // v1.arr[1] = 8;
    // v1.arr[2] = 4;
    // vector v2(3);
    // v2.arr[0] = 1;
    // v2.arr[1] = 0;
    // v2.arr[2] = 6;
    
    // int ans = v1.dotproduct(v2);
    // cout<<ans;

    vector <float> v1(3);
    v1.arr[0] = 2.4;
    v1.arr[1] = 8.3;
    v1.arr[2] = 49;
    vector <float> v2(3);
    v2.arr[0] = 1.2;
    v2.arr[1] = 0.7;
    v2.arr[2] = 6.7;
    
    float ans = v1.dotproduct(v2);
    cout<<ans;

    return 0;
}

/*

Difference between template<class T> and template<typename T>

typename and class are interchangeable in the basic case of specifying a template:

template<class T>
class Foo
{
};
and

template<typename T>
class Foo
{
};
are equivalent.

Having said that, there are specific cases where there is a difference between typename and class.

The first one is in the case of dependent types. typename is used to declare when you are referencing a nested type that depends on another template parameter, such as the typedef in this example:

template<typename param_t>
class Foo
{
    typedef typename param_t::baz sub_t;
};
The second one you actually show in your question, though you might not realize it:

template < template < typename, typename > class Container, typename Type >
When specifying a template template, the class keyword MUST be used as above -- it is not interchangeable with typename in this case (note: since C++17 both keywords are allowed in this case).

You also must use class when explicitly instantiating a template:

template class Foo<int>;
*/