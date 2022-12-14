#include<bits/stdc++.h>
using namespace std;

void combo_sum2(int index, vector<int> arr, int &sum, int target,  vector<int> &ds, vector<vector<int>> &ans)
{
    if(sum == target)
    {
        ans.push_back(ds);
    }
    for(int i=index; i<arr.size(); i++)
    {
        if(i != index && arr[i] == arr[i-1]) continue;

        ds.push_back(arr[i]);
        sum = sum + arr[i];
        combo_sum2(i+1, arr, sum, target, ds, ans);
        ds.pop_back();
        sum = sum - arr[i];
    }
}

// void remove_duplicates(vector<int> &arr)
// {
//     int size = arr.size();
//     int ind = 0;
//     for(int i=0; i<size; i++)
//     {
//         if(arr[i] == arr[i+1]) continue;
//         else{
//             arr[ind] = arr[i];
//             ind++;
//         }
//     }
// }

int main(){
    vector<int> arr =  {10, 1, 2, 7, 6, 1 , 5};
    // vector<int> arr =  {2, 5, 2, 1, 2};
    // vector<int> arr =  {2, 4, 4, 5};
    // int n = 5;
    vector<int> ds;
    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());
    
    // remove_duplicates(arr);
    int sum = 0;
    int target = 8;

    combo_sum2(0, arr, sum, target, ds, ans);

    cout<<"All non-duplicate subsets are below for combination sum 2: "<<endl;

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