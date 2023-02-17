#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 1 --> Fresh Orange, 0 --> Empty Cell, 2 --> Rotten Orange

int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int countOnes = 0;
        int ans = -1;
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push(make_pair(i, j));
                }
                else if(grid[i][j] == 1) countOnes++;
            }
        }

        if(countOnes == 0) return 0;
        
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, -1, 0, 1};

        while(!q.empty()){
            int size = q.size();
            ans++;
            for(int i=0; i<size; i++){
                auto frontNode = q.front();
                q.pop();

                int ival = frontNode.first;
                int jval = frontNode.second;

                for(int z=0; z<4; z++){
                    int newi = ival + dx[z];
                    int newj = jval + dy[z];
                if(newi<m && newi>=0 && newj<n && newj>=0 && grid[newi][newj] == 1) {
                        grid[newi][newj] = 2;
                        countOnes--;
                        q.push(make_pair(newi, newj));
                    }
                }
            }
        }
        if(!countOnes) return ans;
        else return -1;
    }

int main(){

    // vector<vector<int>> grid{
    //     {2,1,1},{1,1,0},{0,1,1}
    // };

    vector<vector<int>> grid{
        {2,1,1},{0,1,1},{1,0,1}
    };

    int ans = orangesRotting(grid);
    cout<<ans<<endl;

    return 0;
}