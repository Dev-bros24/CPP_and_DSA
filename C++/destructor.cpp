#include<iostream>
using namespace std;

// Destructor never takes an argument nor does it return any value
// Whenever a block of code gets exited, to clear up storage compiler automatically executes this.

int count = 0;

class num {
    public:
        num(){
            count++;
            cout<<"This is the time when constructor is called for object number "<<count<<endl;
        }
        ~num(){
            cout<<"This is the time when my destructor is called for object number "<<count<<endl;
            count--;
        }
};


int main(){

    cout<<"We are inside our main function"<<endl;
    cout<<"Creating first object:"<<endl;
    num n1;
    { // Block means the elements inside it have scope inside it only.
        cout<<"Entering this block"<<endl;
        cout<<"Creating two more objects:"<<endl;
        num n2, n3;
        cout<<"Exiting this block."<<endl;
    }
    cout<<"Back to main"<<endl;

    return 0;
}