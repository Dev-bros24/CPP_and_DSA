#include<bits/stdc++.h>
// #include<iostream>
// #include<vector>
using namespace std;

int main(){
    vector<int> v = {2, 3, 5, 6, 7};

    //Addition based looping
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    //Iterator based looping
    vector<int> :: iterator itr;
    for(itr = v.begin(); itr != v.end(); itr++)
    {
        cout<<*itr<<" ";
    }
    cout<<endl;
    //Range based looping
    for(int &value : v)  // We are using reference because the value of the containers(here vector) which gets copied in this value variable are copies and not original values. Hence by using reference original values are getting printed.
    {
        cout<<value<<" ";
        // value++;
    }
    cout<<endl;
    // for(int &value : v)
    // {
    //     cout<<value<<" ";
    // }
    // cout<<endl;

    //Looping using auto keyword
    //Auto keyword dynamically determines the datatype of a variable

    auto a = 1.1;
    cout<<a<<endl; 
   
    for(auto itr = v.begin(); itr != v.end(); itr++)
    {
        cout<<*itr<<" ";
    }
    cout<<endl;

    //Auto and range based combined
    for (auto &value : v)
    {
        cout<<value<<" ";
    }

    return 0;
}