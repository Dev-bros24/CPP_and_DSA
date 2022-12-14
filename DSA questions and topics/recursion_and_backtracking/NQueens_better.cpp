#include <bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, vector<string> &board)
    {
        int duprow = row;
        int dupcol = col;
        
        while(col>=0)
        {
            if(board[row][col] == 'Q') return false;
            col--;
        }
        
        row = duprow;
        col = dupcol;
        while(row>=0 && col>=0)
        {
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        
        row = duprow;
        col = dupcol;
        while(row<board.size() && col>=0)
        {
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
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