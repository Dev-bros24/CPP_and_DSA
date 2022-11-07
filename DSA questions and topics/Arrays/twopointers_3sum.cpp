#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<vector<int>> ans;
               
        for(int i=0; i<size - 1; i++)
        {
            cout<<"Abhishek i start: "<<i<<endl;
            int val = -1 * nums[i];
            int low = i+1, high = size - 1;
                        
            if(i != 0 && nums[i] == nums[i-1])
            {
                continue;
            }
            while(low < high)
            {
                vector<int> vec;
                if(nums[low] + nums[high] == val)
                {
                    cout<<"Abhishek IF"<<endl;
                    vec.push_back(nums[i]);
                    vec.push_back(nums[low]);
                    vec.push_back(nums[high]);
                    low++;
                    high--;
                }
                else if(nums[low] + nums[high] < val)
                {
                    cout<<"Abhishek else IF 1"<<endl;
                    low++;
                }
                else if(nums[low] + nums[high] > val)
                {
                    cout<<"Abhishek else IF 2"<<endl;
                    high--;
                }
                if(vec.size())
                {
                    ans.push_back(vec);
                }
                while(low < high && nums[low] == nums[low-1] && low != i+1)
                {
                    low++;
                }
                while (low < high && high != size - 1 && nums[high] == nums[high+1])
                {
                    high--;
                }
                cout<<"Abhishek i: "<<i<<endl;
            }
        }
        cout<<"before return: "<<endl;
        return ans;
    }

int main()
{
    vector<int> vec{1,2,-2,-1};
    // vector<int> vec{-1,0,1,2,-1,-4};
    vector<vector<int>> answer = threeSum(vec);

    cout<<"Output:"<<endl;
    for(int i=0; i<answer.size(); i++)
    {
        for(int j=0; j<answer[i].size(); j++)
        {
            cout<<answer[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}