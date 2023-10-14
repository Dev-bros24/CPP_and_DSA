// function to find longest common subsequence

class Solution
{
    // Recursion --> Passing for 10 cases out of 1120
    int f(int n, int m, string &s1, string &s2){
        if(n == 0 || m == 0) return 0;
        
        if(s1[n-1] == s2[m-1]) return 1 + f(n-1, m-1, s1, s2);
        else return max(f(n-1, m, s1, s2), f(n, m-1, s1, s2));
    }
    
    // Memoization --> Passing sometimes
    int fMemo(int n, int m, string &s1, string &s2, vector<vector<int>> &memo){
        if(n == 0 || m == 0) return 0;
        
        if(memo[n][m] != -1) return memo[n][m];
        if(s1[n-1] == s2[m-1]) return memo[n][m] = 1 + fMemo(n-1, m-1, s1, s2, memo);
        else return memo[n][m] = max(fMemo(n-1, m, s1, s2, memo), fMemo(n, m-1, s1, s2, memo));
    }
    
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        // vector<vector<int>> memo(n+1, vector<int>(m+1, -1));
        // return f(n, m, s1, s2);
        // return fMemo(n, m, s1, s2, memo); 
        
        // Tabulation
        // vector<vector<int>> tab(n+1, vector<int>(m+1));
        // for(int i=0; i<=n; i++) tab[i][0] = 0;
        // for(int j=0; j<=m; j++) tab[0][j] = 0;
        
        // for(int i=1; i<=n; i++){
        //     for(int j=1; j<=m; j++){
        //         if(s1[i-1] == s2[j-1]) tab[i][j] = 1 + tab[i-1][j-1];
        //         else tab[i][j] = max(tab[i-1][j], tab[i][j-1]);
        //     }
        // }
        
        // return tab[n][m];
        
        // Space Optimisation
        // vector<int> prev(m+1, 0);
        
        // for(int i=1; i<=n; i++){
        //     vector<int> curr(m+1);
        //     curr[0] = 0;
        //     for(int j=1; j<=m; j++){
        //         if(s1[i-1] == s2[j-1]) curr[j] = 1 + prev[j-1];
        //         else curr[j] = max(curr[j-1], prev[j]);
        //     }
        //     prev = curr;
        // }
        
        // return prev[m];
        
        // Space optimised approach using single array and 2 variables
        vector<int> res(m+1, 0);
        int prev2, prev;
        
        for(int i=1; i<=n; i++){
            prev = res[0];
            for(int j=1; j<=m; j++){
                prev2 = res[j];
                if(s1[i-1] == s2[j-1]) res[j] = 1 + prev;
                else res[j] = max(res[j-1], res[j]);
                prev = prev2;
            }
        }
        
        return res[m];
    }
};
