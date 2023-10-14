#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minSum(int i, int j, vector<vector<int>> &arr, int &n){
	if(i == n-1) return arr[i][j];

	int left = minSum(i+1, j, arr, n);
	int right = minSum(i+1, j+1, arr, n);
	return arr[i][j] + min(left, right);
}

int minSumDP(int i, int j, vector<vector<int>> &arr, int &n, vector<vector<int>> &memo){
	if(i == n-1) return arr[i][j];

	if(memo[i][j] != -1) return memo[i][j];
	int left = minSumDP(i+1, j, arr, n, memo);
	int right = minSumDP(i+1, j+1, arr, n, memo);
	return memo[i][j] = arr[i][j] + min(left, right);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// return minSum(0, 0, triangle, n);
	// vector<vector<int>> memo(n, vector<int>(n+1, -1));
	// return minSumDP(0, 0, triangle, n, memo);

	// Tabulation
	// vector<vector<int>> arr(n, vector<int>(n+1, -1));
	// for(int j=0; j<=n; j++) arr[n-1][j] = triangle[n-1][j];

	// for(int i=n-2; i>=0; i--){
	// 	for(int j=i; j>=0; j--){
	// 		arr[i][j] = triangle[i][j] + min(arr[i+1][j], arr[i+1][j+1]);
	// 	}
	// }

	// return arr[0][0];

	// Space Optimisation
	vector<int> next(n+1);
	for(int j=0; j<n; j++){
		next[j] = triangle[n-1][j];
	}

	for(int i=n-2; i>=0; i--){
		vector<int> curr(i+2);
		for(int j=i; j>=0; j--){
			curr[j] = triangle[i][j] + min(next[j], next[j+1]);
		}
		next = curr;
	}

	return next[0];
}