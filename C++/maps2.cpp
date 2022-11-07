#include<bits/stdc++.h>

using namespace std;

void print(map<int, string> &m )
{
    cout<<"The size of this map: "<<m.size()<<endl;
    for(auto &value : m)  // O(log(n)) time complexity of accessing one element
    {
        cout<<value.first<<" "<<value.second<<endl;
    }
}

// Here if we are inserting n elements then time complexity to insert as well as accessing them will be O(nlog(n))

int main(){
    map<int, string> m;
    m[1] = "Abhishek"; //O(log(n))
    m[2] = "Akansha";
    m[3] = "Sachin";
    m[6] = "Anandita";
    m[7] = "Deepak";  // just writing m[some key value] makes a pair in map with the default value of "value's" data type
    auto it = m.find(7); // find returns an iterator, if there is no value returns m.end(). O(log(n))
    cout<<"Abhishek: "<<(*it).first<<" -> "<<(*it).second;
    if(it != m.end())
    {
        m.erase(it); // O(log(n)). Can take iterator as well as key value directly.
    }

    /*
    if there is a string of size n and we insert values with string keys in a map
    then the time complexity of inserting the key string would be s.size() * logn
    */


    // m.clear();
    // if(it == m.end())
    // {
    //     cout<<"No value";
    // }
    // else
    // {
    //     cout<<(*it).first<<" "<<(*it).second<<endl; 
    // }
    // print(m);
    return 0;
}

//Normal maps are sorted on keys.
//Maps of any type can't contain duplicate keys. If we insert a value at a key again, old value gets replaced.
//Inserting an element as well as accessing it has a time complexity of log(n )