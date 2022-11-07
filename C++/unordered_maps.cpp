/* 
Differences in maps and unordered maps
1. Inbuilt implementation  (Unordered maps uses inbuilt hash tables, instead of red black trees)
2. Time complexity (for insertion as well as accessing the elements it is O(1)). For all operations where maps took logn time unordered maps will take O(1) in most cases.
3. Valid keys datatype ( in maps we can use complex data types keys as well, but not in case of unordered maps)
Explanation of 3rd point --> In unordered maps the implementation is using hash table,
 so every key's hash value gets calculated and like if we use pair in keys then it will try to
  calculate the hash value for pair, but pairs doesn't have any in built hash function 
  defined that's why unordered maps doesn't work on this key type. But in case of maps, 
  the insertion takes place on basis of comparision but the comparision of two pairs can
   be done directly p1<p2 or p2<p1. That's why they can be inserted directly to maps.
   All basic data types have their hash function defined internally so they can be used
   in both maps. 

   If we want to store complex data types in case of unordered maps then we need to 
   define our own hash function.
*/
#include<bits/stdc++.h>
using namespace std;


void print(unordered_map<int, string> &m )
{
    cout<<"The size of this map: "<<m.size()<<endl;
    for(auto &value : m)  
    {
        // cout<<value.first<<" "<<m[value.first]<<endl;
        cout<<value.first<<" "<<value.second<<endl;
    }
}

int main(){
    unordered_map<int, string> m;

    m[1] = "Abhishek"; 
    m[2] = "Akansha";
    m[3] = "Sachin";
    m[6] = "Anandita";
    m[7] = "Deepak";

    print(m);

return 0;
}
