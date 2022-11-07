/*
Standard Template Library is a Library of generic classes and functions
1. Containers
 -- Object which Stores data
 -- Uses template classes
2. Algorithms
 -- Procedure to process data
 -- Sorting 
 -- Searching
 -- Uses template functions
3. Iterators
 -- Objects that points to an element of a container
 -- Handled just like pointers
 -- Connects algo with containers
*/


/*
Containers are of 3 types:
1. Sequence containers  
 -- Stores data in Linear fashion
 -- Vector, List, Deque etc.
2. Associative containers
 -- Direct access / Quick access
 -- set, multiset, map, multimap etc.
3. Derived containers
 -- Read world modelling
 -- Queue, stack, priority_queue etc.
*/

#include<iostream>
#include<vector>
using namespace std;

template<class T>
void display(vector<T> &v){
    cout<<"Displaying your vector: "<<endl;
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){

    vector<int> vec1;       //zero length integer vector
    vector<char> vec2(4);   //4-element character vector
    vector<char> vec3(vec2); //4-element character vector from vec2
    vector<int> vec4(6,3);  //6-element vector of 3s

    display(vec4);

    return 0;
}