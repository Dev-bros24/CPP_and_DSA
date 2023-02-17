#include<iostream>
#include<vector>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
        // we need to find longest substring with k zeros 

        int i = 0, j = 0;
        int n = nums.size();
        if(k >= n) return n;
        int count = 0;
        int ans = 0;

        // cout<<j<<" -- "<<n<<endl;
        while(j < n){
            if(nums[j] == 0) count++;

            // cout<<"j: "<<j<<" count: "<<count<<" k: "<<k<<endl;
            if(count < k) j++;
            else if(count == k){
                ans = max(ans, j-i+1);
                j++;
                // cout<<ans<<endl;
            }
            else{
                while(count > k){
                    if(nums[i] == 0) count--;
                    i++;
                }
                j++;
            }
        }

        if(count < k) return n; 
        return ans;
    }


int main(){
    vector<int> nums = {0, 1, 0, 1, 1, 1, 0};
    int k = 2;

    int ans = longestOnes(nums, k);
    cout<<"Answer: "<<ans<<endl;

    return 0;
}