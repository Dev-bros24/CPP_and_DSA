#include<bits/stdc++.h>
using namespace std;

/* Max subset product

int maxprod(int index, int &prod, vector<int> &nums){
        if(index == nums.size()){
            return prod;
        }
        prod = prod*nums[index];
        int left = maxprod(index+1, prod, nums);  // we can't just pass prod*nums[index] here if we are passing prod as a reference in the function as it's not an lvalue.
        prod = prod/nums[index];
        int right = maxprod(index+1, prod, nums);
        
        return max(left, right);
    }

int maxProduct(vector<int>& nums) {
        int prod = 1, index = 0;
        int answer = maxprod(index , prod, nums);
        return answer;
    }
*/

int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int maxi = ans, mini = ans;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]<0){
                swap(maxi, mini);
            }
            maxi = max(nums[i], nums[i]*maxi);
            mini = max(nums[i], nums[i]*mini);
            ans = max(maxi, ans);
        }
        return ans;
    }

int main(){

    vector<int> nums = {2,3,-2,4};

    int answer = maxProduct(nums);
    cout<<"Answer: "<<answer<<endl;

    return 0;
}