#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans;
        
        for(int i=0; i<size; i++)
        {
            bool flag = false;
            int target = nums[i];
            int j = (i+1)%size;
            cout<<"i: "<<i<<" j: "<<j<<" target: "<<target<<endl;
            while(j!=i)
            {
                if(nums[j]>target) 
                {
                    ans.push_back(nums[j]);
                    flag = true;
                    break;
                }
                else{
                    flag = false;
                }
                j = (j+1)%size;
            }
            if(flag == false) ans.push_back(-1);
        }
        return ans;
    }


int main()
{
    vector<int> nums = {1,2,1};

    vector<int> answer = nextGreaterElements(nums);

    cout<<"Answer: "<<endl;
    for(int i=0; i<answer.size(); i++)
    {
        cout<<answer[i]<<" ";
    }

    return 0;
}