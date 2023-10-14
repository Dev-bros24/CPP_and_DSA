//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    int f(int price[], int n, int w){
        if(n == 0) return 0;
        
        if(n <= w) return max(f(price, n, w-n) + price[n-1], f(price, n-1, w));
        else return f(price, n-1, w);
    }
    
    int fMemo(int price[], int n, int w, vector<vector<int>> &memo){
        if(n == 0) return 0;
        
        if(memo[n][w] != -1) return memo[n][w];
        if(n <= w) return memo[n][w] = max(fMemo(price, n, w-n, memo) + price[n-1], fMemo(price, n-1, w, memo));
        else return memo[n][w] = fMemo(price, n-1, w, memo);
    }
    
  public:
    int cutRod(int price[], int n) {
        //code here
        // n length rod, so basically we have the option of cutting it into pieces of max length
        // n and min we can take as 1, for these pieces we'll be getting the prices mentioned
        // in the prices array where prices[i] denotes the price of the wood of the length i+1.
        // JUST THINK OF THESE TYPE OF PROBLEMS AS UNBOUNDED KNAPSACK PROBLEM'S TYPE 
        // Think in that way only.
        
        // vector<vector<int>> memo(n+1, vector<int>(n+1, -1));
        // return f(price, n, n);
        // return fMemo(price, n, n, memo);
        
        // Tabulation --> Bottom up DP
        // vector<vector<int>> tab(n+1, vector<int>(n+1));
        // for(int i=0; i<=n; i++) tab[i][0] = 0;
        // for(int j=0; j<=n; j++) tab[0][j] = 0;
        
        // for(int i=1; i<=n; i++){
        //     for(int j=1; j<=n; j++){
        //         if(i <= j) tab[i][j] = max(tab[i][j-i] + price[i-1], tab[i-1][j]);
        //         else tab[i][j] = tab[i-1][j];
        //     }
        // }
        
        // return tab[n][n];
        
        // Space optimisation
        // vector<int> prev(n+1, 0);
        
        // for(int i=1; i<=n; i++){
        //     vector<int> curr(n+1);
        //     for(int j=0; j<=n; j++){
        //         if(i <= j) curr[j] = max(curr[j-i] + price[i-1], prev[j]);
        //         else curr[j] = prev[j];
        //     }
        //     prev = curr;
        // }
        
        // return prev[n];
        
        // Space optimised using a single array of size n+1
        vector<int> res(n+1, 0);
        
        for(int i=1; i<=n; i++){
            for(int j=0; j<=n; j++){
                if(i <= j) res[j] = max(res[j], price[i-1] + res[j - i]);
            }
        }
        
        return res[n];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends