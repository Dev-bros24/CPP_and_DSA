#include <bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, vector<string> &sol)
{
    for (int i = 0; i < sol.size(); i++)
    {
        if (sol[row][i] == 'Q')
        {
            return false;
        }
        if (sol[i][col] == 'Q')
        {
            return false;
        }
        int rowsub = row - i;
        int colsub = col - i;
        int rowadd = row + i;
        int coladd = col + i;

        if (rowsub >= 0 && colsub >= 0 && sol[rowsub][colsub] == 'Q')
        {
            return false;
        }
        if (rowadd < sol.size() && coladd < sol.size() && sol[rowadd][coladd] == 'Q')
        {
            return false;
        }
        if (rowsub >= 0 && coladd < sol.size() && sol[rowsub][coladd] == 'Q')
        {
            return false;
        }
        if (rowadd < sol.size() && colsub >= 0 && sol[rowadd][colsub] == 'Q')
        {
            return false;
        }
    }

    return true;
}

void solveboard(int col, vector<string> &board , vector<vector<string>> &ans)
{
    if(col == board.size())
    {
        ans.push_back(board);
        return;
    }

    for(int i=0; i<board.size(); i++)
    {
        if(isValid(i, col, board)){
            board[i][col] = 'Q';
            solveboard(col+1, board, ans);
            board[i][col] = '.';
        }
    }
   
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string str(n, '.');
    for(int i=0; i<n; i++)
    {
        board[i] = str;
    }

    solveboard(0, board, ans);

    return ans;
}

int main()
{
    int n;
    cout << "Enter the number: " << endl;
    cin >> n;

    vector<vector<string>> answer = solveNQueens(n);

    for (int i = 0; i < answer.size(); i++)
    {
        cout << "Solution " << i + 1 << endl;
        for (int j = 0; j < answer[i].size(); j++)
        {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}