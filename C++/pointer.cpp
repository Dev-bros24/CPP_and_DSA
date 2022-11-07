#include<iostream>
using namespace std;
int main(){
    int a =3;
    int *b = &a;

    int **c = &b;
    cout << "The value :"<< b;

    return 0;
}