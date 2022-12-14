#include <bits/stdc++.h>
using namespace std;

void solveboard(int col, vector<string> &board ,vector<int> &leftrow, vector<int> &lowerDiag, vector<int> &upperDiag, vector<vector<string>> &ans)
{
    if(col == board.size())
    {
        ans.push_back(board);
        return;
    }

    for(int i=0; i<board.size(); i++)
    {
        if(leftrow[i] == 0 && lowerDiag[i+col] == 0 && upperDiag[board.size()-1 + col-i] == 0)
        {
            board[i][col] = 'Q';
            leftrow[i] = 1;
            lowerDiag[i+col] = 1;
            upperDiag[board.size()-1 + col-i] = 1;
            solveboard(col+1, board, leftrow, lowerDiag, upperDiag, ans);
            board[i][col] = '.';
            leftrow[i] = 0;
            lowerDiag[i+col] = 0;
            upperDiag[board.size()-1 + col-i] = 0;
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

    vector<int> leftrow(n , 0), lowerDiag(2*n -1, 0), upperDiag(2*n -1 ,0);

    solveboard(0, board, leftrow, lowerDiag, upperDiag, ans);

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