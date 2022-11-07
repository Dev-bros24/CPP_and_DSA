#include<iostream>
#include<fstream>

/*
The useful classes for working with files in C++ are:
1. fstreambase
2. ifstream --> derived from fstreambase
3. ofstream --> derived from fstreambase
*/

/*
In order to work with files in C++, you will have to open it. Primarily, there 
are 2 ways to open a file:
1. Using the constructor. (of an object of ifstream and ofstream)
2. Using the member function open() of the class. (i.e. ifstream and ofstream)
*/

using namespace std;

int main(){
    string st = "Abhishek bhai";
    string st2;
    // // Opening files using constructor and writing it
    // ofstream out("Sample.txt");  // write operation, ofstream is a class whose object out we have created to write in the file sample.txt
    // out<<st;

    // Opening files using constructor and reading it
    ifstream in("Sampleb.txt"); // read operation
    // in>>st2;  // When we use objects of ifstream then spaces and newlines do not come that's why only the first word will come in st2
    getline(in, st2);
    // getline(in, st2);
    cout<<st2;

    return 0;
}