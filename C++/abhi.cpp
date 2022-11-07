/* 
There are two types of header files:
System header files that come with the compiler.
*/
#include<iostream>
// User defined header files that are written by the programmer.
#include"abhi.h"   

/*
Syntax to include:

#include <filename.h>
or
#include "filename.h"

*/

using namespace std;

int main(){
    int a = 4, b = 5;

    cout<<mul(a, b);
    return 0;
}



