#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

// Unordered maps are implemented using hash tables and ordered maps are implemented
// using BST(red black trees). TC for insertion, deletion and searching in both are
// O(1) for unordered maps and O(logn) for ordered maps.


// Worst case time complexity of unordered_maps is O(n). 

int main(){
    
    unordered_map<string, int> mp;

    mp.insert(make_pair("Abhi", 2));
    mp.insert(make_pair("Satya", 4));
    mp.insert(make_pair("Akan", 4));
    mp.insert(make_pair("Sam", 6));
    // cout<<mp["Abhi"]<<endl;

    // cout<<mp.at("Unknown")<<endl; // If entry of this key is not present this will throw error
    // cout<<mp["Unknown"]<<endl;    // This creates an entry with this key if not present and with default value
    // cout<<mp.at("Unknown")<<endl;

    unordered_map<string, int> :: iterator it = mp.begin();

    while(it != mp.end())
    {
        cout<<it->first << " "<< it->second<<endl;
        it++; 
    }

    return 0;
}