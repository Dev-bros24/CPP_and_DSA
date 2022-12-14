#include <bits/stdc++.h>
using namespace std;

void paths(int row, int col, int n, vector<string> &ans, string &temp, vector<vector<int>> &nums, int di[], int dj[])
{
    if(row<0 || col<0 || row>=n || col>=n)
    {
        return;
    }
    if(nums[row][col] == 0)
    {
        return;
    }
    if(row == n-1 && col == n-1)
    {
        ans.push_back(temp);
        return;
    }

    string str = "LRDU";
    
    for(int i=0; i<4; i++)
    {
        int nexti = row+di[i];
        int nextj = col+dj[i];
        
        nums[row][col] = 0;
        temp.push_back(str[i]);
        paths(nexti, nextj, n, ans, temp, nums, di, dj);
        temp.pop_back();
        nums[row][col] = 1;
    }
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    string temp = "";

    int di[] = {0, 0, +1, -1};
    int dj[] = {-1, +1, 0, 0};

    paths(0, 0, n, ans, temp, m, di, dj);

    return ans;
}

int main()
{
    vector<vector<int>> nums = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};

    int n = 4;

    vector<string> answer = findPath(nums, n);

    cout<<"Answer is below: "<<endl;

    for(int i=0; i<answer.size(); i++)
    {
        cout<<answer[i]<<" ";
    }                            

    return 0;
}