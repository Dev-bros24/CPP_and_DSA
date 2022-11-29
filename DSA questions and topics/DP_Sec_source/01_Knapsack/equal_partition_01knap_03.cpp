#include<iostream>
#include<vector>
using namespace std;

bool canPartition(vector<int> &nums){
    int n = nums.size();
    int sum = 0;
    for(int i=0; i<nums.size(); i++){
        sum = sum + nums[i];
    }

    if(sum % 2 != 0) return false;
    else{
        int reqsum = sum/2;
        vector<vector<bool>> arr(n+1, vector<bool>(reqsum+1, false));

        for(int j=0; j<=reqsum; j++) arr[0][j] = false;
        for(int i=0; i<=n; i++) arr[i][0] = true;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=reqsum; j++){
                if(nums[i-1]<=j){
                    arr[i][j] = arr[i-1][j-nums[i-1]] || arr[i-1][j];
                }
                else arr[i][j] = arr[i-1][j];
            }
        }
        return arr[n][reqsum];
    }
}

int main(){
    
    vector<int> nums{1,5,11,5};

    bool ans = canPartition(nums);

    cout<<"Ans: "<<ans;

    return 0;
}