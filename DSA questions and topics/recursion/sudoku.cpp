#include <bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, char ch, vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == ch)
        {
            return false;
        }
        if (board[i][col] == ch)
        {
            return false;
        }
        if (board[3*(row / 3) + i / 3][3*(col / 3) + i % 3] == ch)
        {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == '.')
            {
                for (int z = 1; z <= 9; z++)
                {
                    if (isValid(i, j, (char)(z + '0'), board))
                    {
                        board[i][j] = (char)(z + '0');
                        if (solve(board) == true)
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    cout << "The board looks like below" << endl;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            cout << board[i][j];
            if (j != board[i].size() - 1)
                cout << " | ";
        }
        if (i != board.size() - 1)
            cout << "\n----------------------------------\n";
        else
            cout << "\n\n";
    }

    solve(board);

    cout << "The board looks like below after solving" << endl;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            cout << board[i][j];
            if (j != board[i].size() - 1)
                cout << " | ";
        }
        if (i != board.size() - 1)
            cout << "\n----------------------------------\n";
        else
            cout << "\n\n";
    }

    return 0;
}