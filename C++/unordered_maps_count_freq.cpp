#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// we can declare multimap<int, string> which can store same keys more than once i.e. we can insert DUPLICATES.
// but we can do like we can take a vector in case of value in normal maps and then we'll
// be able to store multiple values for same key.



int main(){
    unordered_map<string, int> m;
    // multimap<int, int> m2 ;
    int n;
    cout<<"Enter the number of strings: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        m[s]++;   // when we write m[s], it just creates a key s and a value corresponding to it gets updated. 
    }

    int q;
    cout<<"Enter the number of strings that you want frequency of: ";
    cin>>q;
    while(q--)
    {   
        string a;
        cin>>a;
        cout<<"The value is: "<<m[a]<<endl;
    }

    return 0;
}