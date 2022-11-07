#include<bits/stdc++.h>
using namespace std;

// nums array contains elements which might be repeating, and we have to get the powerset with unique subsets

void powerset(int index, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans)
{
    if(index == nums.size())
    {
        ans.push_back(temp);
    }
    else
    {
        temp.push_back(nums[index]);
        powerset(index+1, nums, temp, ans);

        temp.pop_back();
        while(index < nums.size()-1 && nums[index] == nums[index+1]) index++;

        powerset(index+1, nums, temp, ans);
    }
}

int main()
{
    // vector<int> nums{1, 2, 2};
    vector<int> nums{2, 5, 2, 1, 2};

    vector<int> temp;
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    powerset(0, nums, temp, ans);

    cout<<"All unique subsets are below: "<<endl;

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}