#include<iostream>
#include<fstream>


using namespace std;

int main(){
    // connecting our file to aout stream
    // ofstream aout("Sample.txt"); // aout stream(ex - pipe) se connect kar rahe hain file ko hum
    
    // Creating a name string and filling it with the string entered by the user
    // string name;
    // cout<<"Enter your name: "<<endl;
    // cin>>name;

    // // Writing a string to the file
    // aout<<"My name is " + name;

    // aout.close(); // pipe connection broken and file closed 

    ifstream ain("Sample.txt");
    string content;
    // ain>>content;
    getline(ain, content, ';');   // third parameter in getline is the line delim
    cout<<"The content of this file is: "<<content<<endl;
    ain.close();

    return 0;
}