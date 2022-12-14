#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

vector<int> subsetSums(vector<int> &nums, int n, int range){

    vector<vector<bool>> arr(n+1, vector<bool>(range+1, false));
    vector<int> ans;

    for(int j=0; j<=range; j++){
        arr[0][j] = false;
    }
    for(int i=0; i<=n; i++){
        arr[i][0] = true;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=range; j++){
            if(nums[i-1]<=j){
                arr[i][j] = arr[i-1][j-nums[i-1]] || arr[i-1][j];
            }
            else arr[i][j] = arr[i-1][j];
        }
    }

    for(int j=0; j<=range/2; j++){
        if(arr[n][j]) ans.push_back(j);
    }

    return ans;
}

int main(){
    // vector<int> nums{3, 9, 7, 3};
    vector<int> nums{8, 6, 5};
    
    int size = nums.size();

    int range = 0;
    for(int i=0; i<size; i++){
        range = range + nums[i];
    }

    vector<int> sums = subsetSums(nums, size, range);

    
    int mn = INT_MAX;
    for(int i=0; i<sums.size(); i++){
        // cout<<sums[i]<<" ";
        mn = min(mn, range-(2*sums[i]));
    }
    // cout<<"\nRange: "<<range<<endl;

    cout<<"Ans: "<<mn;

    return 0;
}