#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

/*
    Syntax:
    int solve(int arr[], int i, int j){
    if(i>j)    // for base condition, we should think of the first invalid input in these type of questions
        {
			return 0;
        }
		for(int k=i; k<j; k++){
			// calculate temp answers
			tempans = solve(int arr[], i, k) <some operation> solve(int arr[], k+1, j);
			ans = func(tempans);
		}
		return ans; 
}
*/

// Recursion
int minMultiplications(vector<int> &arr, int i, int j){
	
	static int count = 1;
	cout<<"Count: "<<count<<endl;
	count++;

	if(i>=j) return 0;

	int tempcost = 0, mincost = INT_MAX;
	for(int k = i; k<j; k++){
		int cost = arr[i-1]*arr[k]*arr[j];
		tempcost = minMultiplications(arr, i, k) + minMultiplications(arr, k+1, j) + cost;
		mincost = min(mincost, tempcost);
	}

	// int tempcost = 0, mincost = INT_MAX;
	// for(int k = i+1; k<=j; k++){
	// 	int cost = arr[i-1]*arr[k-1]*arr[j];
	// 	tempcost = minMultiplications(arr, i, k-1) + minMultiplications(arr, k, j) + cost;
	// 	mincost = min(mincost, tempcost);
	// }

	return mincost;
}

// Memoization
int minMultiplicationsDP(vector<int> &arr, int i, int j, vector<vector<int>> &memo){
	
	static int count = 1;
	cout<<"Count: "<<count<<endl;
	count++;

	if(i>=j) return 0;

	int tempcost = 0, mincost = INT_MAX;

	if(memo[i][j]!=-1) return memo[i][j];
	for(int k = i; k<j; k++){
		int cost = arr[i-1]*arr[k]*arr[j];
		tempcost = minMultiplicationsDP(arr, i, k, memo) + minMultiplicationsDP(arr, k+1, j, memo) + cost;
		mincost = min(mincost, tempcost);
	}

	return memo[i][j] = mincost;
}

int main(){
    // vector<int> nums{40, 20, 30, 10, 30};
	// int n = 5;
	// int i = 1, j = n-1;
    vector<int> nums{40, 20, 30, 10, 30, 60, 70, 65};
	int n = 8;
	int i = 1, j = n-1;
    // vector<int> nums{10, 30, 5, 60};
	// int n = 4;
	// int i = 1, j = n-1;

	vector<vector<int>> memo(n, vector<int>(n, -1));

	int ans = minMultiplications(nums, i, j);
	// int ans = minMultiplicationsDP(nums, i, j, memo);

	cout<<"Answer: "<<ans;

    return 0;
}