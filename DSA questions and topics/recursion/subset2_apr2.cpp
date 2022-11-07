#include<bits/stdc++.h>
using namespace std;

void powerset(int index, vector<int> arr,  vector<int> &ds, vector<vector<int>> &ans)
{
    ans.push_back(ds);
    for(int i=index; i<arr.size(); i++)
    {
        if(i != index && arr[i] == arr[i-1]) continue;

        ds.push_back(arr[i]);
        powerset(i+1, arr, ds, ans);
        ds.pop_back();
    }
}

int main(){
    vector<int> arr =  {2, 4, 4, 5};
    // int n = 5;
    vector<int> ds;
    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());

    powerset(0, arr, ds, ans);

    cout<<"All non-duplicate subsets are below: "<<endl;

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}