#include<iostream>
#include<set>
using namespace std;

void print(set<string> &m)
{
    cout<<"the size of the set "<<m.size()<<endl;
    for(string value : m)   // string &value is not allowed
    {
        cout<<value<<endl;
    }
    // for(auto &value : m)   
    // {
    //     cout<<value<<endl;
    // }
    // for(auto it=m.begin(); it != m.end(); it++)
    // {
    //     cout<<(*it)<<endl;
    // }
}

int main(){
    set<string> st;
    st.insert("Abhishek");
    st.insert("Amit");
    st.insert("Akansha");
    // st.insert("Akansha");
    auto it = st.find("Akansha"); // It will return the iterator to the next of the last value 
    // if(it!= st.end())
    // {
    //     cout<<(*it);
    // }
    if(it!= st.end())
    {
        st.erase(it); // In case of multiset it will delete only first value if there are repeated values.
    }
    st.erase("Akansha");  // In case of multiset it will delete all values with this string.

    print(st);

    return 0;
}