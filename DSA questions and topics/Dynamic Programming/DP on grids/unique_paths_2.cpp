#include<iostream>
#include<vector>
using namespace std;

// Recursion
int solveGrid(vector<vector<int>> &grid, int i, int j, int m, int n){

        static int count = 1;
        cout<<"Count: "<<count<<endl;
        count++;

        if(grid[i][j] == 1) return 0;
        if(i == m && j == n) return 1;

        int right = 0, down = 0;
        // right
        if(j+1<=n) right = solveGrid(grid, i, j+1, m, n);

        // down
        if(i+1<=m) down = solveGrid(grid, i+1, j, m, n);

        return right+down;
    }

// Memoization
int solveGridDP(vector<vector<int>> &grid, int i, int j, int m, int n, vector<vector<int>> &memo){
        static int count = 1;
        cout<<"Count: "<<count<<endl;
        count++;

        if(grid[i][j] == 1) return 0;
        if(i == m && j == n) return 1;

        if(memo[i][j] != -1) return memo[i][j];
        int right = 0, down = 0;
        // right
        if(j+1<=n) right = solveGridDP(grid, i, j+1, m, n, memo);

        // down
        if(i+1<=m) down = solveGridDP(grid, i+1, j, m, n, memo);

        return memo[i][j] = right+down;
    }

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));

        // int ans = solveGrid(obstacleGrid, 0, 0, m-1, n-1);
        int ans = solveGridDP(obstacleGrid, 0, 0, m-1, n-1, memo);

        return ans;
    }


int main(){
    vector<vector<int>> grid{
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

    int ans = uniquePathsWithObstacles(grid);

    cout<<"Answer: "<<ans;

    return 0;
}