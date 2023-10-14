#include<iostream>
#include<vector>

using namespace std;

int uniquePaths(int i, int j, int m, int n){
    if(i == m-1 || j == n-1) return 1;
    if(i == m || j == n) return 0;

    return uniquePaths(i+1, j, m, n) + uniquePaths(i, j+1, m, n);
}

int uniquePathsDP(int i, int j, int m, int n, vector<vector<int>> &memo){
    if(i == m-1 || j == n-1) return memo[i][j] = 1;
    if(i == m || j == n) return 0;

    if(memo[i][j] != -1) return memo[i][j];
    return memo[i][j] = uniquePathsDP(i+1, j, m, n, memo) + uniquePathsDP(i, j+1, m, n, memo);
}

int totalPaths(int m, int n){
    // return uniquePaths(0, 0, m, n);
    // vector<vector<int>> memo(m, vector<int>(n, -1));
    // return uniquePathsDP(0, 0, m, n, memo);

    // tabulation
    // vector<vector<int>> dp(m, vector<int>(n, -1));

    // for(int i=0; i<m; i++) dp[i][n-1] = 1;
    // for(int j=0; j<n; j++) dp[m-1][j] = 1;

    // for(int i=m-2; i>=0; i--){
    //     for(int j=n-2; j>=0; j--){
    //         dp[i][j] = dp[i+1][j] + dp[i][j+1];
    //     }
    // }

    // return dp[0][0];

    // space optimisation using 1D Arrays
    vector<int> next(n, 1);

    for(int i=m-2; i>=0; i--){
        vector<int> cur(n);
        for(int j=n-1; j>=0; j--){
            if(j+1<n) cur[j] = next[j] + cur[j+1];
            else cur[j] = next[j];
        }
        next = cur;
    }

    return next[0];
}

void solve5(){
    int m, n;
    cin>>m>>n;
    int ans = totalPaths(m, n);
    cout<<ans;
}

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    // solve();
    // solve2();
    // solve3();
    // solve4();
    solve5();

    return 0;
}