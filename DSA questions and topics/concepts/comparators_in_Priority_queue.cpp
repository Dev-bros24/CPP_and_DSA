#include<bits/stdc++.h>
using namespace std;

class comp{ // this implementation of minheap is already there in a class named greater in STL
    public:
    bool operator()(int a, int b){
        return a > b;   // isko hum jo heapsort ke baad output milta hai min and max heap se usse relate kar sakte hain kyunki wo ulte sorted arrays milte hain.
    }
};

// Less and greater are two classes in STL which uses these two operators only.
// similarly for sorting there are comparator functions with these names i.e. less and greater.

int main()
{
    priority_queue<int, vector<int>, comp> pq;
    pq.push(1);
    pq.push(5);
    pq.push(2);
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }

    return 0;
}