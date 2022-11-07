#include<bits/stdc++.h>
using namespace std;

class cmp{
    public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

class MedianFinder {
public:
        priority_queue<int> small;
        priority_queue<int, vector<int>, cmp> large;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        
        cout<<"Pushing: "<<num<<endl;
        cout<<"Small size: "<<small.size()<<" Large size: "<<large.size()<<endl;
        if(small.size() && large.size() && small.top() > large.top())
        {
            int val = small.top();
            small.pop();
            large.push(val);
        }
        
        if((small.size() || large.size()) && small.size() > large.size() + 1)
        {
            int val = small.top();
            small.pop();
            large.push(val);
        }
        else if((small.size() || large.size()) && small.size()+1 < large.size())
        {
            int val = large.top();
            large.pop();
            small.push(val);
        }
    }
    
    double findMedian() {
        cout<<"F Small size: "<<small.size()<<" F Large size: "<<large.size()<<endl;
        if(small.size() > large.size())
        {
            return small.top();
        }
        else if(small.size() < large.size())
        {
            return large.top();
        }
        else{
            return ((double)small.top() + (double)large.top())/2;
        }
        
    }
};

int main()
{
    // MedianFinder *obj = new MedianFinder();
    MedianFinder *obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    cout<<"Median: "<<obj->findMedian()<<endl;
    obj->addNum(3);
    cout<<"Median: "<<obj->findMedian()<<endl;
    return 0;
}


