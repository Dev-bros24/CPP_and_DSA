#include<iostream>
#include<map>
#include<string>
using namespace std;
// Map is an associative array

// In unordered maps, we can't have complex data types like pairs because it doesn't have
// a hash function defined for these. We have to write a hash function by ourself in this
// case. but in normal maps we can insert.

// Below mentioned key strings will be stored in maps in lexicographically increasing order i.e. as they'll get stored in a dictionary.
// Map is an associative array
int main(){
    map<string, int> marksMap;
    marksMap["Harry"] = 98;
    marksMap["Jack"] = 59;
    marksMap["Rohan"] = 2;

    marksMap.insert({{"Abhishek", 100}, {"Akansha", 97}}); //These two values that we are inserting are pairs which we can give by make_pair as well or curly brackets which we have given here.
    map<string, int> :: iterator itr;
    for(itr = marksMap.begin(); itr != marksMap.end(); itr++) // we can't do it+1 in case of maps as they are randomly stored in memory and not in order.
    {
            // cout<<(*itr).first<<" "<<(*itr).second<<"\n";
            cout<<itr->first<<" "<<itr->second<<"\n";
    }
    cout<<"the size is: "<<marksMap.size()<<endl;
    cout<<"the max size is: "<<marksMap.max_size()<<endl;
    cout<<"the empty's return value is: "<<marksMap.empty()<<endl;

    cout<<marksMap["Rohan"];

    return 0;
}