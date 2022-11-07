#include<iostream>
using namespace std;

// struct employee
// {
//     int eId;
//     char favchar;
//     float salary;
// };

typedef struct employee //In c++, we don't need typedef
{
    int eId; // 4
    char favchar; // 1
    float salary; // 4
}ep;

int main(){
    // struct employee harry;
    enum Meal{breakfast, lunch, dinner};
    Meal m1 = dinner;
    cout<<m1;
    // ep harry;
    // harry.eId = 1;
    // harry.favchar = 'c';
    // harry.salary = 1200000;
    // cout<<harry.salary;
    return 0;
}

// unions are like structures but provide better memory management

union money
{
    /*data*/
    int rice; // 4
    char car; // 1
    float pounds; // 4
};

// now money is like that we're going to use one at a time only. 
// Here structure would allocate 9 bytes but a union would allocate 4 bytes of memory
// (union finds the largest data type and allocates that much memory).

// if we allocate car = 'c' and try to print rice then it will print some garbage or ascii value of c i.e. 99

