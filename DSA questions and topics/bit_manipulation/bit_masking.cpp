/*
We need to create a set DS which gives us following properties:

1. Addition of elements
2. Removal of elements
3. Printing all elements

Contraints:
Numbers will not be more than 60 i.e. 0<=n<=60,    x<=63 at max.

*/

#include <bits/stdc++.h>
using namespace std;

class Sets
{
private:
    long long store;

public:
    Sets()
    {
        store = 0;
    }
    void add(int value)
    {
        store = store | ((long long)1 << value);
    }
    void remove(int value)
    {
        store = store & ~((long long)1 << value);
    }
    void print()
    {
        for (int bit = 0; bit < 64; bit++)
        {
            if (store & ((long long)1 << bit))
            {
                cout << bit << " ";
            }
        }
        cout<<endl;
        return;
    }
};

int main()
{
    Sets s;
    s.add(1);
    s.add(5);
    s.add(56);
    s.add(3);
    s.add(2);
    s.add(26);
    s.add(46);
    s.add(23);
    s.print();

    s.remove(23);
    s.remove(5);
    s.remove(46);
    s.print();

    // long long a = 5;
    // cout<<(a | 2);

    return 0;
}