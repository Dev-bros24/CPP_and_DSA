#include <iostream>
#include<vector>
using namespace std;

int minSum(int i, int j, int &m, int &n, vector<vector<int>> &grid){
    if(i == m-1 && j == n-1) return grid[i][j];
    if(i >= m || j>= n) return INT_MAX;

    int down = minSum(i+1, j, m, n, grid);
    int right = minSum(i, j+1, m, n, grid);

    return grid[i][j] + min(down, right);
}

int minSumDP(int i, int j, int &m, int &n, vector<vector<int>> &grid, vector<vector<int>> &memo){
    if(i == m-1 && j == n-1) return grid[i][j];
    if(i >= m || j>= n) return INT_MAX;

    if(memo[i][j] != -1) return memo[i][j];
    int down = minSumDP(i+1, j, m, n, grid, memo);
    int right = minSumDP(i, j+1, m, n, grid, memo);

    return memo[i][j] = grid[i][j] + min(down, right);
}

int minSumPath(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    // vector<vector<int>> memo(m, vector<int>(n, -1));
    // // return minSum(0, 0, m, n, grid);
    // return minSumDP(0, 0, m, n, grid, memo);

    // Tabulation
    // vector<vector<int>> tab(m, vector<int>(n));
    // tab[m-1][n-1] = grid[m-1][n-1];

    // for(int i=m-1; i>=0; i--){
    //     for(int j=n-1; j>=0; j--){
    //         if(i == m-1 && j == n-1) continue;
    //         else{
    //             int down = INT_MAX;
    //             int right = INT_MAX;
    //             if(i+1<m) down = tab[i+1][j];
    //             if(j+1<n) right = tab[i][j+1];
    //             tab[i][j] = grid[i][j] + min(right, down);
    //         }
    //     }
    // }

    // return tab[0][0];

    // Space optimisation
    vector<int> next(n);

    for(int i=m-1; i>=0; i--){
        vector<int> curr(n);
        for(int j=n-1; j>=0; j--){
            if(i == m-1 && j == n-1) curr[j] = grid[i][j];
            else{
                int down = INT_MAX, right = INT_MAX;
                if(j+1<n) right = curr[j+1];
                if(i+1<m) down = next[j];
                curr[j] = grid[i][j] + min(down, right);
            }
        }
        next = curr;
    }

    return next[0];
}