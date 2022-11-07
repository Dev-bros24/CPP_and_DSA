#include<bits/stdc++.h>
using namespace std;


// bool should_i_swap(int a, int b)
// {
// 	if(a < b) return true;
// 	else return false;
// }


// Because swap is a function, here in this case comparator is a function (functor as it is passed as an argument).

bool cmp(pair<int, int> a, pair<int, int> b) 
{
	if(a.first != b.first)
	{
		return a.first < b.first;
	}
	else
	{
		return a.second > b.second;
	}
}


int main(){
    // cout<<"A";
    int n;
    cin>>n;

    vector<pair<int, int>> a(n);

    for(int i=0; i<n; i++)
    {
    	cin>>a[i].first>>a[i].second;
    }

    sort(a.begin(), a.end(), cmp);   // Inbuilt swap function swaps the values when cmp function return false otherwise keeps them as it is.

    for(int i=0; i<n; i++)
    {
    	cout<<a[i].first<<" "<<a[i].second<<endl;
    }
    cout<<endl;
    return 0;
}