#include<iostream>
#include<vector>
#include"../../abhi.h"
using namespace std;

// int count = 1;

void dfs(vector<vector<int>>& matrix, int &i, int &j, int temp, int &m, int &n, int dx[], int dy[], int &ans){
        static int count = 1;
        cout<<"Count: "<<count<<endl;
        count++;

        ans = max(ans, temp);
        for(int z=0; z<4; z++){
            int newi = i + dx[z];
            int newj = j + dy[z];
            if(newi<m && newj<n && newi>=0 && newj>=0 && matrix[newi][newj]>matrix[i][j]){
                dfs(matrix, newi, newj, temp+1, m, n, dx, dy, ans);
            }
        }
    }

// Issue in the below function is that we are running through the loop the same number of times
void dfsDP(vector<vector<int>>& matrix, int &i, int &j, int temp, int &m, int &n, int dx[], int dy[], int &ans, vector<vector<int>> &memo){
        static int count = 1;
        cout<<"Count: "<<count<<endl;
        count++;

        ans = max(ans, temp);
        for(int z=0; z<4; z++){
            int newi = i + dx[z];
            int newj = j + dy[z];
            if(newi<m && newj<n && newi>=0 && newj>=0 && matrix[newi][newj]>matrix[i][j]){
                if(memo[newi][newj] != -1){
                    int sum = temp + memo[newi][newj];
                    ans = max(ans, sum);
                    continue;
                }
                else dfsDP(matrix, newi, newj, temp+1, m, n, dx, dy, ans, memo);
            }
        }
    }

    // Accepted function
    int dfsret(vector<vector<int>>& matrix, int &i, int &j, int &m, int &n, int dx[], int dy[], vector<vector<int>> &memo){ // Best Solution
        static int count = 1;
        cout<<"Count: "<<count<<endl;
        count++;

        if(memo[i][j] != -1) return memo[i][j];
        int curr = 1;

        for(int z=0; z<4; z++){
            int newi = i + dx[z];
            int newj = j + dy[z];

            if(newi<m && newj<n && newi>=0 && newj>=0 && matrix[newi][newj]>matrix[i][j]){
                curr = max(curr, 1 + dfsret(matrix, newi, newj, m, n, dx, dy, memo));
            }
        }

        return memo[i][j] = curr;
    }


    // Wrong answer function
    // int dfsret(vector<vector<int>>& matrix, int &i, int &j, int &m, int &n, int dx[], int dy[], vector<vector<int>> &memo){ // Best Solution
    //     // static int count = 1;
    //     // cout<<"Count: "<<count<<endl;
    //     // count++;

    //     cout<<"Abhishek: "<<memo[i][j]<<endl;
    //     if(memo[i][j] != -1) return memo[i][j];
    //     // int curr = 1;

    //     for(int z=0; z<4; z++){
    //         int newi = i + dx[z];
    //         int newj = j + dy[z];

    //         // Jo bhi clockwise move karne pe starting from east jo bhi first bada mil raha hai hum usi ka answer +1 return maar de rahe hain, that's why wrong
    //         if(newi<m && newj<n && newi>=0 && newj>=0 && matrix[newi][newj]>matrix[i][j]){
    //             return memo[i][j] = 1 + dfsret(matrix, newi, newj, m, n, dx, dy, memo);
    //         }
    //     }

    //     return memo[i][j] = 1;
    // }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, -1, 0, 1};
        vector<vector<int>> memo(m, vector<int>(n, -1));

        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         int tempans = 0;
        //         int temp = 1;
        //         dfs(matrix, i, j, temp, m, n, dx, dy, tempans);
        //         ans = max(tempans, ans);
        //     }
        // }

        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         int tempans = 0;
        //         int temp = 1;
        //         dfsDP(matrix, i, j, temp, m, n, dx, dy, tempans, memo);
        //         memo[i][j] = tempans;
        //         ans = max(tempans, ans);
        //     }
        // }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int currentans = dfsret(matrix, i, j, m, n, dx, dy, memo);
                ans = max(currentans, ans);
            }
        }

        printArray2D(memo);
        return ans;
    }

int main(){
    // vector<vector<int>> matrix{{9,9,4},
    // {6,6,8},
    // {2,1,1}
    // };

    // vector<vector<int>> matrix{{3,4,5},  
    // {3,2,6},
    // {2,2,1}
    // };

    vector<vector<int>> matrix{{9,9,4,8,5,12},
    {6,6,8,5,3,2},
    {2,1,1,4,87,6},
    {2,5,1,4,7,6},
    {1,1,1,2,2,3}};

    int ans = longestIncreasingPath(matrix);
    cout<<"Answer: "<<ans<<endl;
    
    return 0;
}