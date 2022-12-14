#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        
        if(size == 1)
        {
            return;
        }
        
        int i = size-1;
        while(i > 0 && nums[i] <= nums[i-1])
        {
            i--;
        }
        
        if(i == 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        else
        {    
            i--;
            int j = size-1;
            while(nums[j] <= nums[i]) j--;
            
            cout<<"Abhi: "<<i<<" j: "<<j<<endl;
            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
        }       
    }


int main()
{
    vector<int> vec{1,5,1};

    nextPermutation(vec);

    cout<<"Output array: "<<endl;
    for(int i=0; i<vec.size(); i++)
    {
        cout<<vec[i]<<" ";
    }

    return 0;
}