#include <bits/stdc++.h>
using namespace std;

void paths(int row, int col, int n, vector<string> &ans, string &temp, vector<vector<int>> &nums)
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

    nums[row][col] = 0;
    temp.push_back('L');
    paths(row, col-1, n, ans, temp, nums);
    nums[row][col] = 1;
    temp.pop_back();

    nums[row][col] = 0;
    temp.push_back('R');
    paths(row, col+1, n, ans, temp, nums);
    nums[row][col] = 1;
    temp.pop_back();

    nums[row][col] = 0;
    temp.push_back('D');
    paths(row+1, col, n, ans, temp, nums);
    nums[row][col] = 1;
    temp.pop_back();

    nums[row][col] = 0;
    temp.push_back('U');
    paths(row-1, col, n, ans, temp, nums);
    nums[row][col] = 1;
    temp.pop_back();

}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    string temp = "";

    paths(0, 0, n, ans, temp, m);

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