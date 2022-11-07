#include <bits/stdc++.h> 
using namespace std;

// Commented part was different approach

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    int repeat = 0;
    int missing = 0;
    pair<int, int> ans;
    // int sumnum = 0;
    vector<int> vec(n+1, 0);
	for(int i=0; i<n; i++)
    {
        // sumnum = sumnum + arr[i];
        vec[arr[i]]++;
        // if(vec[arr[i]] > 1)
        // {
        //     repeat = arr[i];
        // }
    }
    for(int i = 1; i<=n; i++)
    {
        if(vec[i]==0)
        {
            missing = i;
        }
        if(vec[i] == 2)
        {
            repeat = i;
        }
        if(missing && repeat) break;
    }
    // int sum = 0;
    // if(n%2 == 0)
    // {
    //     sum = (n/2) * (n+1);
    // }
    // else sum = n*((n+1)/2);
    
    // cout<<"Repeat: "<<repeat<<" Sumnum: "<<sumnum<<" Sum: "<<sum<<endl;
    // int diff = sumnum - sum;
    // int missing = repeat - diff;
    
    ans = make_pair(missing, repeat);
    return ans;
}

int main()
{
    // vector<int> vec = {4, 5, 2, 9, 8, 1, 1, 7, 10, 3};
    vector<int> vec = {1, 5, 8, 1, 2, 3, 4, 10, 7, 6};

    pair<int, int> answer = missingAndRepeating(vec, vec.size());
    cout<<"Pair: "<<answer.first<<" | "<<answer.second<<endl;

    return 0;
}