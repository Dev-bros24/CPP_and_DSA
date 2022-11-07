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

    return 0;
}