#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
    int minSum(int i, int j, vector<vector<int>> &mat, int &m, int &n){
        // cout<<"i: "<<i<<" j: "<<j<<endl;
        if(j<0 || i>=m || j>=n) return INT_MAX;
        if(i == m-1) return mat[i][j];

        return mat[i][j] + min(minSum(i+1, j-1, mat, m, n), min(minSum(i+1, j, mat, m, n), minSum(i+1, j+1, mat, m, n)));
    }

    int minSumDP(int i, int j, vector<vector<int>> &mat, int &m, int &n, vector<vector<int>> &memo){
        // cout<<"i: "<<i<<" j: "<<j<<endl;
        if(j<0 || i>=m || j>=n) return INT_MAX;
        if(i == m-1) return mat[i][j];
        if(memo[i][j] != -1) return memo[i][j];

        return memo[i][j] = mat[i][j] + min(minSumDP(i+1, j-1, mat, m, n, memo), min(minSumDP(i+1, j, mat, m, n, memo), minSumDP(i+1, j+1, mat, m, n, memo)));
    }

void tabMinsum(vector<vector<int>> &mat, vector<vector<int>> &tab){ // this is just to prepare the tab matrix
    int m = mat.size(), n = mat[0].size();

    for(int j=0; j<n; j++) tab[m-1][j] = mat[m-1][j];

    for(int i=m-2; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            int left = INT_MAX, right = INT_MAX, down = INT_MAX;
            if(j-1>=0) left = tab[i+1][j-1];
            if(j+1<n) right = tab[i+1][j+1];
            down = tab[i+1][j];
            tab[i][j] = mat[i][j] + min(down, min(right, left));
        }
    }
}
void spaceOptimised(vector<vector<int>> &mat, vector<int> &next){
    int m = mat.size(), n = mat[0].size();

    for(int j=0; j<n; j++) next[j] = mat[m-1][j];

    for(int i=m-2; i>=0; i--){
        vector<int> curr(n);
        for(int j=0; j<n; j++){
            int left = INT_MAX, right = INT_MAX, down = INT_MAX;
            if(j-1>=0) left = next[j-1];
            if(j+1<n) right = next[j+1];
            down = next[j];
            curr[j] = mat[i][j] + min(down, min(right, left));
        }
        next = curr;
    }
}
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini = INT_MAX;
        int m = matrix.size(), n = matrix[0].size();
        // vector<vector<int>> memo(m, vector<int>(n, -1));

        // for(int i=0; i<n; i++) mini = min(mini, minSum(0, i, matrix, m, n));
        // for(int i=0; i<n; i++) mini = min(mini, minSumDP(0, i, matrix, m, n, memo));

        // return mini;

        // Tabulation
        // vector<vector<int>> tab(m, vector<int>(n, -1));
        // tabMinsum(matrix, tab);
        // for(int j=0; j<n; j++) mini = min(mini, tab[0][j]);
        // return mini;

        // Space Optimisation
        vector<int> next(n, -1);
        spaceOptimised(matrix, next);
        for(int j=0; j<n; j++) mini = min(mini, next[j]);
        return mini;
    }
};