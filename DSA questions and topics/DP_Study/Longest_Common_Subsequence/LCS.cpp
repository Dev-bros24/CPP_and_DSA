#include<iostream>
#include<vector>
using namespace std;

// Recursion
int LCS(string s1, string s2, int m, int n){
    static int count = 1;
    cout<<"Count: "<<count<<endl;
    count++;

    if(m == 0 || n == 0) return 0;

    if(s1[m-1] == s2[n-1]){
        return 1 + LCS(s1, s2, m-1, n-1);
    }
    else return max(LCS(s1, s2, m-1, n), LCS(s1, s2, m, n-1));
}

// Memoization
int LCSDP(string s1, string s2, int m, int n, vector<vector<int>> &memo){
    static int count = 1;
    cout<<"Count: "<<count<<endl;
    count++;

    if(m == 0 || n == 0) return 0;

    if(memo[m][n] != -1) return memo[m][n];
    if(s1[m-1] == s2[n-1]){
        return memo[m][n] = 1 + LCSDP(s1, s2, m-1, n-1, memo);
    }
    else return memo[m][n] = max(LCSDP(s1, s2, m-1, n, memo), LCSDP(s1, s2, m, n-1, memo));
}

int main(){
    string s1 = "fcvafu";
    string s2 = "nohvgda";
    int m = s1.length(), n = s2.length();
    vector<vector<int>> memo(m+1, vector<int>(n+1, -1));

    // int ans = LCS(s1, s2, m, n);
    // int ans = LCSDP(s1, s2, m, n, memo);

    // Tabulation

    vector<vector<int>> arr(m+1, vector<int>(n+1, -1));

    for(int j=0; j<=n; j++) arr[0][j] = 0;
    for(int i=0; i<=m; i++) arr[i][0] = 0;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s1[i-1] == s2[j-1]){
                arr[i][j] = 1 + arr[i-1][j-1];
            }
            else arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
        }
    }

    int ans = arr[m][n];

    cout<<"Answer: "<<ans;

    return 0;
}