#include<bits/stdc++.h>
using namespace std;


int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        
        for(int val : nums)
        {
            st.insert(val);
        }
        
        int maxi = 0;
        
        for(int val : nums)
        { 
            cout<<"Abhi: "<<val<<endl;
            if(!st.count(val-1))
            {         
                int curr = 1;
                while(st.count(val+1))
                {
                    val++;
                    curr++;
                }
            maxi = max(curr, maxi);
            }
        }
        return maxi;
}

int main(){
    
    vector<int> vec{100,4,200,1,3,2};
    int ans = longestConsecutive(vec);

    cout<<"Answer: "<<ans<<endl;

    return 0;
}