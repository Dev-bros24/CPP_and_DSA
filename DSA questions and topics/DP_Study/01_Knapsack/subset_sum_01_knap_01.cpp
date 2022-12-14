#include<iostream>
#include<vector>
using namespace std;

// Normal recursion
bool subsetSum(vector<int> &nums, int sum, int n){

    static int count = 1;
    cout<<"Count: "<<count<<endl;
    count++;

    if(sum == 0) return true;
    if(n == 0) return false;

    if(nums[n-1] <= sum){
        return subsetSum(nums, sum-nums[n-1], n-1) || subsetSum(nums, sum, n-1);
    }
    else return subsetSum(nums, sum, n-1);
}

// Memoization
bool subsetSumDP(vector<int> &nums, int sum, int n, vector<vector<int>> &memo){

    static int count = 1;
    cout<<"Count: "<<count<<endl;
    count++;

    if(sum == 0) return true;
    if(n == 0) return false;

    if(memo[n][sum] != -1) return memo[n][sum];

    if(nums[n-1] <= sum){
        return memo[n][sum] = subsetSumDP(nums, sum-nums[n-1], n-1, memo) || subsetSumDP(nums, sum, n-1, memo);
    }
    else return memo[n][sum] = subsetSumDP(nums, sum, n-1, memo);
}

int main(){
    vector<int> nums{1, 3, 5, 7, 98, 7, 87, 67};
    int targetsum = 68;
    int size = nums.size();

    vector<vector<int>> memo(size+1, vector<int>(targetsum+1, -1));
    bool ans = subsetSum(nums, targetsum, size);
    // bool ans = subsetSumDP(nums, targetsum, size, memo);

/*
    // Tabulation
    
    vector<vector<bool>> arr(size+1, vector<bool>(targetsum+1, false));

    for(int j=0; j<=targetsum; j++){
        arr[0][j] = false;
    }
    for(int i=0; i<=size; i++){
        arr[i][0] = true;
    }

    for(int i=1; i<=size; i++){
        for(int j=1; j<=targetsum; j++){
            if(nums[i-1]<=j){
                arr[i][j] = arr[i-1][j-nums[i-1]] || arr[i-1][j];
            }
            else arr[i][j] = arr[i-1][j];
        }
    }

    bool ans = arr[size][targetsum];

*/

    if(ans) cout<<"Yes it is present"<<endl;
    else cout<<"No it's not"<<endl;

    return 0;
}