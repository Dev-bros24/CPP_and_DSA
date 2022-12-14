#include <bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, vector<vector<char>> &board, char ch)
{
    for (int i = 0; i < 9; i++)
    {
        if (i!= col && board[row][i] == ch)
        {
            return false;
        }
        if (i != row && board[i][col] == ch)
        {
            return false;
        }
        if ((3 * (row / 3) + i / 3) != row && (3 * (col / 3) + i % 3) != col && board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch)
        {
            return false;
        }
    }
    return true;
}

bool isValidSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] != '.' && !isValid(i, j, board, board[i][j]))
            {
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


    if(isValidSudoku(board))
    cout<<"True"<<endl;
    else cout<<"False";

    return 0;
}


