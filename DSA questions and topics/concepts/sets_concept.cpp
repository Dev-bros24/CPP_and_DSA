#include<bits/stdc++.h>
using namespace std;

void printSet(set<vector<int>> st)
{
    for(auto val : st)
    {
        for(int value : val)
        {
            cout<<value<<" ";
        }
        cout<<endl;
    }
}

int main(){
    set<vector<int>> st;
    st.insert({1, 2 , 2});
    st.insert({1, 3 , 2});
    st.insert({3, 1 , 2});
    st.insert({3, 1 , 1});
    st.insert({2, 2 , 1});
    // st.insert({4, 2, 2 , 1});
    st.insert({1, 2, 3 });
    st.insert({2, 2 , 1});


    printSet(st);

    return 0;
}