//{ Driver Code Starts
#include <iostream>
#include <vector>
using namespace std;

// } Driver Code Ends
class Solution{
    int f(int arr[], int n, int sum){
        if(n == 0){ // just let it travel to the end to count all possible subsets, in case of subset sum problem we just need to return true or false so it works there to just return 1 in case of sum == 0 as another base case before this one. 
            if(sum == 0) return 1;
            return 0;
        }
        int M = 1e9 + 7;
        if(arr[n-1] <= sum) return (f(arr, n-1, sum-arr[n-1]) + f(arr, n-1, sum)) %M;
        return f(arr, n-1, sum) %M;
    }
    
    int fDP(int arr[], int n, int sum, vector<vector<int>> &memo){
        if(n == 0){
            if(sum == 0) return 1;
            return 0;
        }
        
        int M = 1e9 + 7;
        
        if(memo[n][sum] != -1) return memo[n][sum];
        
        if(arr[n-1] <= sum) return memo[n][sum] = (fDP(arr, n-1, sum-arr[n-1], memo) %M + fDP(arr, n-1, sum, memo) %M) %M;
        return memo[n][sum] = fDP(arr, n-1, sum, memo) %M;
    }

	public:
	int perfectSum(int arr[], int n, int sum)
	{
	   // vector<vector<int>> memo(n+1, vector<int>(sum+1, -1));   
        // return f(arr, n, sum);
        // return fDP(arr, n, sum, memo);
        
        //Tabulation
        // vector<vector<int>> tab(n+1, vector<int>(sum+1, -1)); 
        // for(int j=0; j<=sum; j++) tab[0][j] = 0;
        // // for(int i=0; i<=n; i++) tab[i][0] = 1;
        // tab[0][0] = 1;
        int M = 1e9 + 7;
        
        // for(int i=1; i<=n; i++){
        //     for(int j=0; j<=sum; j++){
        //         if(arr[i-1] <= j) tab[i][j] = (tab[i-1][j] + tab[i-1][j-arr[i-1]]) %M;
        //         else tab[i][j] = tab[i-1][j]%M; 
        //     }
        // }
        
        // return tab[n][sum];
        
        //Space optimisation
        vector<int> prev(sum+1, -1);
        for(int i=0; i<=sum; i++) prev[i] = 0;
        prev[0] = 1;
        
        for(int i=1; i<=n; i++){
            vector<int> curr(sum+1);
            for(int j=0; j<=sum; j++){
                if(arr[i-1] <= j) curr[j] = (prev[j] + prev[j-arr[i-1]]) %M;
                else curr[j] = (prev[j]) %M;
            }
            prev = curr;
        }
        
        return prev[sum];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
    return 0;
}

// } Driver Code Ends