#include<bits/stdc++.h>
using namespace std;

// in case of sets and maps, we don't have to give iterator like
// s.begin(), s.end() in arguments as that will work in O(n) TC as the internal
// implementation in that case is by using trees. That's why we need to write it
// as --> s.lower_bound(value) and mp.lower_bound(value).

/*
lower_bound returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘val’. 
and if the value is not present in the vector then it returns the end iterator.

upper_bound returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘val’. 

*/

int main(){
    int a[6] = {1, 2, 4, 5, 6, 8};
    int n = 6;

    // bool res = binary_search(a, a+n, 5);

    int* ind = lower_bound(a, a+n, 7);   // lower bound returns iterator
    // cout<<*(ind)<<endl;

    // cout<<"ind:        "<<ind<<" a:      "<<a<<" val:    "<<ind-a;

    int ind2 = lower_bound(a, a+n, 6) - a;
    // cout<<ind2<<endl;

    // int ind3 = upper_bound(a, a+n, 6) - a;
    int ind3 = upper_bound(a, a+n, 0) - a;
    // cout<<ind3<<endl;


    // sets

    set<int> st;
    st.insert(4);
    st.insert(5);
    st.insert(9);
    st.insert(13);

    set<int> :: iterator index = st.lower_bound(9);
    cout<<*(index);

    return 0;
}