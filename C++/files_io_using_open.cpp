#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream aout;
    aout.open("Sample.txt");
    aout<<"My name is Abhishek\n";
    aout<<"Her name is Akansha";
    aout.close();

    ifstream ain;
    string st, st2;
    ain.open("Sample.txt");
    // ain>>st>>st2;
    // cout<<st<<"-"<<st2;

    while(ain.eof() == 0)  // eof hasn't been encountered yet
    {
        getline(ain, st);
        cout<<st<<endl;
    }
    ain.close();

    return 0;
}