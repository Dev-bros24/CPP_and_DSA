#include<bits/stdc++.h>
using namespace std;

// Sets and maps are associative containers. these contain values already in sorted order.
// We can use comparators in these as well.

// Here these are not functions so here the comparator is a classname or structure name 
// that we create.

// here in these it uses an operator which is the call '()' operator.
// here even if we make a new function, then also what set is going to use
// for comparision will remain same. So, because its using this operator for comparision,
// we have to change this operator(function call operator) itself i.e. do operator overloading.

class compare{
    public:
    bool operator()(int a, int b)  // we can also write const int &a, const int &b
    {
        return a > b;
    }
};

class compare2{ // this comparator is not working in my case for maps
    public:
    bool operator()(pair<char, int> a, pair<char, int> b)
    {
        return a.second > b.second;
    }
};

// To sort maps we can:
// 1. Copy content to vector of pairs and do the sorting on that.
// 2. by copying all the elements to a set of pairs and apply comparator on that set.
// set<pair<string, int>, comp> S(M.begin(), M.end()); ---> this will copy from map M to set S
// 3. Using a multimap.

int main()
{
    /*  set<int, className/structureName> st; 
       Syntax of this comparator
    */
    set<int, compare> st;
    st.insert(2);
    st.insert(1);
    st.insert(3);

    for(auto it : st)
    {
        cout<<it<<" ";
    }
    cout<<endl;

    map<char, int, greater<char>> mp;

    mp.insert({'a', 4});
    mp.insert({'f', 5});
    mp.insert({'k', 9});
    mp.insert({'h', 7});
    mp.insert({'t', 3});

    for(auto it : mp)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }

    return 0;
}