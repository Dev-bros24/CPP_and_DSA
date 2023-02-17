#include<iostream>
#include<vector>
#include"../../abhi.h"
using namespace std;

int M = 1e9 + 7;

int dfs(vector<vector<int>>& grid, int &i, int &j, int dx[], int dy[], const int &m, const int &n, vector<vector<int>> &memo){
        if(memo[i][j] != -1) {
            return memo[i][j];
        }

        int curr = 1;
        for(int z=0; z<4; z++){
            int newi = i + dx[z];
            int newj = j + dy[z];

            if(newi<m && newi>=0 && newj<n && newj>=0 && grid[newi][newj] > grid[i][j]){
                curr += dfs(grid, newi, newj, dx, dy, m, n, memo);
                curr %= M;
            }
        }

        return memo[i][j] = curr;
    }

    int countPaths(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, -1, 0, 1};
        vector<vector<int>> memo(m, vector<int>(n, -1));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans += dfs(grid, i, j, dx, dy, m, n, memo);
                ans %= M;
            }
        }

        // printArray2D(memo);
        return ans;
    }

int main(){
    // vector<vector<int>> grid{
    //     {1, 1},
    //     {3, 4}
    // };

    vector<vector<int>> grid{
        {1,1,3,4},{3,4,3,2}
    };

    int ans = countPaths(grid);
    cout<<"Answer: "<<ans<<endl;

    return 0;
}