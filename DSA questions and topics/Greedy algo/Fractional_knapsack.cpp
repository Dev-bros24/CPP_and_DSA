#include <bits/stdc++.h> 
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    double v1 = (double)a.second/(double)a.first;
    double v2 = (double)b.second/(double)b.first;
    return v1 > v2;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{   
    sort(items.begin(), items.end(), cmp);
    
    int rem_wei = w;
    double total = 0.00;
    
    cout<<"Sorted: "<<endl;
    for(auto val : items)
    {
        cout<<val.first<<" "<<val.second<<endl;
    }

    for(int i=0; i<n; i++)
    {
        if(rem_wei!=0 && items[i].first <= rem_wei)
        {
            total = total + items[i].second;
            rem_wei = rem_wei - items[i].first;
        }
        else if(rem_wei!=0 && items[i].first > rem_wei)
        {
            double val = (double)rem_wei/(double)items[i].first;
            total = total + val * (double)items[i].second;
            rem_wei = 0;
        }
        else{
            break;
        }
        cout<<"i: "<<i<<" rem wei: "<<rem_wei<<" total: "<<total<<endl;
    }
    return total;
}

int main()
{
    // vector<pair<int, int>> vec = {{120,100}, {40,50}, {200, 45}, {50,40}, {10,30}, {90,25}};
    vector<pair<int, int>> vec = {{20,12}, {24,35}, {36, 41}, {40,25}, {42,32}};
    int n = 5, w = 100;
    double ans = maximumValue(vec, n , w);
    cout<<"\nAnswer is: "<<ans<<endl;
    return 0;

}