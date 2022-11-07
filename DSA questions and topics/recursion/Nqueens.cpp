#include <bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, vector<string> &sol)
{
    cout << "Size: " << sol.size() << endl;
    for (int i = 0; i < sol.size(); i++)
    {
        cout << "Abhishek row: " << row << " col: " << col << " i: " << i << endl;
        if (sol[row][i] == 'Q')
        {
            cout << "First" << endl;
            return false;
        }
        if (sol[i][col] == 'Q')
        {
            cout << "Second" << endl;
            return false;
        }
        int rowsub = row - i;
        int colsub = col - i;
        int rowadd = row + i;
        int coladd = col + i;

        if (rowsub >= 0 && colsub >= 0 && sol[rowsub][colsub] == 'Q')
        {
            cout << "Third" << endl;
            return false;
        }
        if (rowadd < sol.size() && coladd < sol.size() && sol[rowadd][coladd] == 'Q')
        {
            cout << "Fourth" << endl;
            return false;
        }
        if (rowsub >= 0 && coladd < sol.size() && sol[rowsub][coladd] == 'Q')
        {
            cout << "Fifth" << endl;
            return false;
        }
        if (rowadd < sol.size() && colsub >= 0 && sol[rowadd][colsub] == 'Q')
        {
            cout << "Sixth" << endl;
            return false;
        }
    }

    cout << "Before return:" << endl;
    return true;
}

void placer(int &count, vector<string> &sol)
{
    for (int i = 0; i < sol.size(); i++)
    {
        for (int j = 0; j < sol[i].length(); j++)
        {
            cout << "Checking Validity" << endl;
            if (sol[i][j] == '.' && isValid(i, j, sol))
            {
                cout << "Indside IF i: " << i << " j: " << j << endl
                     << endl;
                sol[i][j] = 'Q';
                count++;
                cout << "Count: " << count << endl;
            }
        }
    }

    // return true;
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;

    // for(int i=0; i<n; i++)
    // {
    //     vector<string> temp;
    //     for(int j=0; j<n; j++)
    //     {
    //         string str;
    //         for(int z = 0; z<n; z++)
    //         {
    //             str.push_back('.');
    //         }
    //         temp.push_back(str);
    //     }
    //     ans.push_back(temp);
    // }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vector<string> temp;
            for (int i = 0; i < n; i++)
            {
                string str;
                for (int j = 0; j < n; j++)
                {
                    str.push_back('.');
                }
                temp.push_back(str);
            }
            cout << "Main i: " << i << " j: " << j << endl;
            temp[i][j] = 'Q';
            int count = 1;
            placer(count, temp);

            if (count == n)
                ans.push_back(temp);
        }
    }

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

    // cout<<"Abhishek "<<answer[0][0][0]<<endl;
    // cout<<"Abhishek 2: "<<answer[0][1][2];
    return 0;
}