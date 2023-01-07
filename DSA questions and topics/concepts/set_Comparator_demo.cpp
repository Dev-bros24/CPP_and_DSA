#include<bits/stdc++.h>
using namespace std;

class Compare{ // This is default behaviour of comparators in case of pairs
    public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b){
        if(a.first == b.first){ // we need to include this equal condition otherwise the set will not include any entries of pairs that contain the first values as equal
            return a.second < b.second;
        }
        else{
            return a.first < b.first;
        }
    }
};

int main(){
    set<pair<int, int>, Compare> st;

    st.insert(make_pair(4, 8));
    st.insert(make_pair(4, 5));
    st.insert(make_pair(2, 6));
    st.insert(make_pair(2, 7));
    st.insert(make_pair(1, 7));

    auto it = st.begin();

    while(it!= st.end()){
        cout<<it->first<<" - "<<it->second<<endl;
        it++;
    }

    return 0;
}