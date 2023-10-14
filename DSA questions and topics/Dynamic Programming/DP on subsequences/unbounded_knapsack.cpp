// User function Template for C++

class Solution{
    private:
    // Recursion
    int f(int N, int W, int val[], int wt[]){
        if(N == 0 || W == 0) return 0;
        
        if(wt[N-1] <= W) return max(f(N, W-wt[N-1], val, wt) + val[N-1], f(N-1, W, val, wt));
        else return f(N-1, W, val, wt);
    }
    
    // Memoization
    int fMemo(int N, int W, int val[], int wt[], vector<vector<int>> &memo){
        if(N == 0 || W == 0) return 0;
        
        if(memo[N][W] != -1) return memo[N][W];
        if(wt[N-1] <= W) return memo[N][W] = max(fMemo(N, W-wt[N-1], val, wt, memo) + val[N-1], fMemo(N-1, W, val, wt, memo));
        else return memo[N][W] = fMemo(N-1, W, val, wt, memo);
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // vector<vector<int>> memo(N+1, vector<int>(W+1, -1));
        // return f(N, W, val, wt);
        // return fMemo(N, W, val, wt, memo);
        
        // Tabulation
        // vector<vector<int>> tab(N+1, vector<int>(W+1));
        // for(int i=0; i<=N; i++) tab[i][0] = 0;
        // for(int j=0; j<=W; j++) tab[0][j] = 0;
        
        // for(int i=1; i<=N; i++){
        //     for(int j=1; j<=W; j++){
        //         if(wt[i-1] <= j) tab[i][j] = max(tab[i][j-wt[i-1]] + val[i-1], tab[i-1][j]);
        //         else tab[i][j] = tab[i-1][j];
        //     }
        // }
        
        // return tab[N][W];
        
        // Space Optimisation
        // vector<int> prev(W+1, 0);
        
        // for(int i=1; i<=N; i++){
        //     vector<int> curr(W+1);
        //     for(int j=0; j<=W; j++){
        //         if(wt[i-1] <= j) curr[j] = max(curr[j-wt[i-1]] + val[i-1], prev[j]);
        //         else curr[j] = prev[j];
        //     }
        //     prev = curr;
        // }
        
        // return prev[W];
        
        // Space optimised approach using only single array
        
        /* We can go for this approach in case of these type of unbounded knapsack
         problems as in case of pick we need some previous value on the same array
         and in case of notpick we need the same value of the previous array which we 
         can just use and replace in place, without the need of previous array. */
         
         vector<int> res(W+1, 0);
         
         for(int i=1; i<=N; i++){
             for(int j=0; j<=W; j++){
                 if(wt[i-1] <= j) res[j] = max(val[i-1] + res[j-wt[i-1]], res[j]);
             }
         }
         
         return res[W];
    }
};