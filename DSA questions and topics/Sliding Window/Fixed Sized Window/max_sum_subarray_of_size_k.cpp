#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

/*
General Format of Fixed sized sliding window:
    n --> array, string size
    int i=0, j=0;
    while(j<n){
        calculations for j
        
        if(j-i+1 < k) j++;
        else{
            find ans from above calc

            remove the calculations of ith element from the calculations
            slide the window i.e. i++ and j++;
        }
    }

    return ans;
*/

// Brute force 
long maxSum(int k, vector<int> &arr, int n){
    long maxSum = INT_MIN;
    for(int i=0; i<=n-k; i++){
        long sum = 0;
        for(int j=i; j<i+k; j++){
            sum += arr[j];
        }
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

// Optimised approach using Sliding Window
long maxSumOpt(int k, vector<int> &arr, int n){
    // int i=0, j=k-1;
    int i=0, j=0;

    long sum = 0, maxSum = INT_MIN;
    // for(int z=i; z<=j; z++) sum += arr[z];
    
    // while(j<n){
    //     maxSum = max(sum, maxSum);
    //     sum = sum - arr[i++] + arr[++j];
    // }
    while(j<n){
        sum += arr[j];
        if(j-i+1 < k){
            j++;
        }
        else{
            maxSum = max(sum, maxSum);
            sum = sum - arr[i++];
            j++;
        } 
    }

    return maxSum;
}

long maximumSumSubarray(int K, vector<int> &Arr , int N){
    // long ans = maxSum(K, Arr, N);
    long ans = maxSumOpt(K, Arr, N);

    return ans;  
}

int main(){
    vector<int> arr = {5, 6, 3, 4, 2, 3, 9};
    int size = 7;
    int k = 3;

    long ans = maximumSumSubarray(k, arr, size);
    cout<<"Answer: "<<ans<<endl;

    return 0;
}