#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
    int cP(int i, int j1, int j2, vector<vector<int>> &grid, int dj[], int m, int n){
        if(j1<0 || j1 >= n || j2<0 || j2>=n) return -1e9;
        if(i == m-1){
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        } 

        int maxi = -1e9;
        for(int y = 0; y<3; y++){
            for(int z=0; z<3; z++){
                if(j1 == j2) maxi = max(maxi, grid[i][j1] + cP(i+1, j1+dj[y], j2+dj[z], grid, dj, m, n));
                else maxi = max(maxi, grid[i][j1] + grid[i][j2] + cP(i+1, j1+dj[y], j2+dj[z], grid, dj, m, n));
            }
        }

        return maxi;
    }

    int cPDP(int i, int j1, int j2, vector<vector<int>> &grid, int dj[], int m, int n, vector<vector<vector<int>>> &memo){
        if(j1<0 || j1 >= n || j2<0 || j2>=n) return -1e9;
        if(i == m-1){
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        } 

        if(memo[i][j1][j2] != -1) return memo[i][j1][j2];
        int maxi = -1e9;
        for(int y = 0; y<3; y++){
            for(int z=0; z<3; z++){
                if(j1 == j2) maxi = max(maxi, grid[i][j1] + cPDP(i+1, j1+dj[y], j2+dj[z], grid, dj, m, n, memo));
                else maxi = max(maxi, grid[i][j1] + grid[i][j2] + cPDP(i+1, j1+dj[y], j2+dj[z], grid, dj, m, n, memo));
            }
        }

        return memo[i][j1][j2] = maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dj[] = {-1, 0, +1};
        // vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(n, -1)));

        // int ans = cP(0, 0, n-1, grid, dj, m , n);
        // int ans = cPDP(0, 0, n-1, grid, dj, m , n, memo);

        // Tabulation
        // vector<vector<vector<int>>> arr(m, vector<vector<int>>(n, vector<int>(n, -1)));
        // // for i = m-1 i.e. the base case fill up the array
        // for(int j1 = 0; j1<n; j1++){
        //     for(int j2=0; j2<n; j2++){
        //         int value = grid[m-1][j1];
        //         if(j1 != j2) value += grid[m-1][j2];

        //         arr[m-1][j1][j2] = value;
        //     }
        // }

        // for(int i=m-2; i>=0; i--){
        //     for(int j1=0; j1<n; j1++){
        //         for(int j2=0; j2<n; j2++){
        //             int value = grid[i][j1];
        //             if(j1 != j2) value += grid[i][j2];
        //             for(int y = 0; y<3; y++){
        //                 for(int z=0; z<3; z++){
        //                     int newj1 = j1+dj[y];
        //                     int newj2 = j2+dj[z];
        //                     if(newj1<n && newj1>=0 && newj2>=0 && newj2<n) arr[i][j1][j2] = max(arr[i][j1][j2], value + arr[i+1][newj1][newj2]);
        //                 }
        //             }
        //         }
        //     }
        // }

        // for(int j1 = 0; j1<n; j1++){
        //     for(int j2=0; j2<n; j2++){
        //         ans = max(ans, arr[0][j1][j2]);
        //     }
        // }
        
        // return arr[0][0][n-1];

        // spaceoptimisation
        vector<vector<int>> next(n, vector<int>(n));

        for(int j1 = 0; j1<n; j1++){
            for(int j2=0; j2<n; j2++){
                int value = grid[m-1][j1];
                if(j1 != j2) value += grid[m-1][j2];

                next[j1][j2] = value;
            }
        }

        for(int i=m-2; i>=0; i--){
            vector<vector<int>> curr(n, vector<int>(n));
            for(int j1=0; j1<n; j1++){
                for(int j2=0; j2<n; j2++){
                    int maxi = -1e9;
                    for(int y=0; y<3; y++){
                        for(int z=0; z<3; z++){
                            int value = grid[i][j1];
                            if(j1 != j2) value += grid[i][j2];
                            
                            if(j1+dj[y] < n && j1+dj[y] >= 0 && j2 + dj[z] < n && j2 + dj[z] >= 0)curr[j1][j2] = max(curr[j1][j2], value + next[j1 + dj[y]][j2 + dj[z]]);
                        }
                    }
                }
            }
            next = curr;
        }

        return next[0][n-1];
    }
};