#include<bits/stdc++.h>
#include<vector>
using namespace std;

// Recursion
int fJ(int ind, vector<int> heights){
    static int count = 1;
    cout<<"Count: "<<count<<endl;
    count++;

    if(ind == 0){
        return 0;
    }
    
    int leftE = INT_MAX, rightE = INT_MAX;
    leftE = fJ(ind-1, heights) + abs(heights[ind] - heights[ind - 1]);
    if(ind>1)
    rightE = fJ(ind-2, heights) + abs(heights[ind] - heights[ind - 2]);

    return min(leftE, rightE);
}

// Memoization
int fJDP(int ind, vector<int> heights, vector<int> &arr){
    static int count = 1;
    cout<<"Count: "<<count<<endl;
    count++;

    if(ind == 0){
        return 0;
    }
    
    if(arr[ind] != -1) return arr[ind];
    int leftE = INT_MAX, rightE = INT_MAX;
    leftE = fJDP(ind-1, heights, arr) + abs(heights[ind] - heights[ind - 1]);
    if(ind>1)
    rightE = fJDP(ind-2, heights, arr) + abs(heights[ind] - heights[ind - 2]);

    return arr[ind] = min(leftE, rightE);
}

int frogJump(int n, vector<int> &heights){
    int ind = n-1;
    vector<int> arr(n, -1);
    // return fJ(ind, heights);
    // return fJDP(ind, heights, arr);

    // Tabulation
    // arr[0] = 0;
    // arr[1] = abs(heights[1] - heights[0]);

    // for(int i=2; i<n; i++){
    //     int leftE = abs(heights[i] - heights[i-1]) + arr[i-1];
    //     int rightE = abs(heights[i] - heights[i-2]) + arr[i-2];
    //     arr[i] = min(leftE, rightE);
    // }
    // return arr[n-1];

    // Space optimization
    int prev2E = 0;
    int prev1E = abs(heights[1] - heights[0]);
    int curE = INT_MAX;

    for(int i=2; i<n; i++){
        int leftE = abs(heights[i] - heights[i-1]) + prev1E;
        int rightE = abs(heights[i] - heights[i-2]) + prev2E;
        curE = min(leftE, rightE);
        prev2E = prev1E;
        prev1E = curE;
    }
    return curE; 
}

int main(){
    
    // vector<int> heights{10, 20, 30, 10};
    vector<int> heights{7, 4, 4, 2, 6, 6, 3, 4};
    // int n = 4;
    int n = 8;

    int ans = frogJump(n, heights);
    cout<<"Answer: "<<ans<<endl;

    return 0;
}