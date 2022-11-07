#include<bits/stdc++.h>
using namespace std;

// 1 element can be used n number of times

void combo_sum(int index, int &sum, int &target, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans)
{
    if(index == nums.size())
    {
        if(sum == target)
        ans.push_back(temp);
    }
    else
    {
        temp.push_back(nums[index]);
        sum = sum + nums[index];
        if(sum<=target)
        {
            combo_sum(index, sum, target, nums, temp, ans);
        }
        else{
            combo_sum(index+1, sum, target, nums, temp, ans);
        }

        temp.pop_back();
        sum = sum - nums[index];

        while(index < nums.size()-1 && nums[index] == nums[index+1]) index++;
        combo_sum(index+1, sum, target, nums, temp, ans);
    }
}

int main()
{
    // vector<int> nums{2, 5, 2, 1, 2};
    // vector<int> nums{10,1,2,7,6,1,5};
    // vector<int> nums{2, 3 ,5};
    vector<int> nums{2,3,6,7};

    vector<int> temp;
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int sum = 0;
    int target = 7;

    combo_sum(0, sum, target, nums, temp, ans);

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