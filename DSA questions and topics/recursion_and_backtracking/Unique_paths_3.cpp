#include<iostream>
#include<vector>
using namespace std;

bool everyBlock(vector<vector<int>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        bool flag = true;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    flag = false;
                    break;
                }
            }
        }

        return flag;
    }

    // Recursion
    int solveGrid(vector<vector<int>> &grid, int i, int j, pair<int, int> end){
        // if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return 0;
        if(make_pair(i, j) == end && !everyBlock(grid)) return 0;
        if(make_pair(i, j) == end && everyBlock(grid)) return 1;

        // Moving left if possible
        int left = 0, right = 0, up = 0, down = 0;
        if(j-1>=0 && grid[i][j-1] != -1 && grid[i][j-1] != 1){
            int val = grid[i][j];
            grid[i][j] = -1;
            left = solveGrid(grid, i, j-1, end);
            grid[i][j] = val;
        }

        // Right
        if(j+1<grid[0].size() && grid[i][j+1] != -1 && grid[i][j+1] != 1){
            int val = grid[i][j];
            grid[i][j] = -1;
            right = solveGrid(grid, i, j+1, end);
            grid[i][j] = val;
        }

        // Up
        if(i-1>=0 && grid[i-1][j] != -1 && grid[i-1][j] != 1){
            int val = grid[i][j];
            grid[i][j] = -1;
            up = solveGrid(grid, i-1, j, end);
            grid[i][j] = val;
        }

        // Down
        if(i+1<grid.size() && grid[i+1][j] != -1 && grid[i+1][j] != 1){
            int val = grid[i][j];
            grid[i][j] = -1;
            down = solveGrid(grid, i+1, j, end);
            grid[i][j] = val;
        }

        return left+right+up+down;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        pair<int, int> start;
        pair<int, int> end;

        for(int i = 0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == 1){
                    start.first = i;
                    start.second = j;
                }
                else if(grid[i][j] == 2){
                    end.first = i;
                    end.second = j;
                }
            }
        }

        int ans = solveGrid(grid, start.first, start.second, end);

        return ans;
    }


int main(){
    // vector<vector<int>> grid{{1,0,0,0},
    //                         {0,0,0,0},
    //                         {0,0,2,-1}};

    vector<vector<int>> grid{{1,0,0,0},
                            {0,0,0,0},
                            {0,0,0,2}};

    int ans = uniquePathsIII(grid);

    cout<<"Answer: "<<ans<<endl;

    return 0;
}