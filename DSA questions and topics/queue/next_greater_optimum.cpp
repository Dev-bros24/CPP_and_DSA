#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        int size = nums.size();
        stack<int> st;
        int end = (2*size)-1;
        
        for(int i=end; i>=0; i--)
        {
            while(!st.empty() && st.top() <= nums[i%size]) st.pop();
            
            if(st.empty() && i<size) 
            {
                ans.push_back(-1);
                st.push(nums[i%size]);
            }
            else if(st.empty()) 
            {
                st.push(nums[i%size]);
                continue;
            }
            else{
                if(i<size)
                ans.push_back(st.top());
                
                st.push(nums[i%size]);
            }
        }
        reverse(ans.begin(), ans.end());
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