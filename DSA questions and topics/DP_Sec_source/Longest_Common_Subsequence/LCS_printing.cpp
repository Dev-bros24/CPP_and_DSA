#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    string s1 = "fcvafu";
    string s2 = "nohvgda";
    int m = s1.length(), n = s2.length();

    vector<vector<int>> arr(m + 1, vector<int>(n + 1, -1));

    for (int j = 0; j <= n; j++)
    {
        arr[0][j] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        arr[i][0] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                arr[i][j] = 1 + arr[i - 1][j - 1];
            }
            else
            {
                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
            }
        }
    }

    int i = m, j = n;
    string str = "";

    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            str.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (arr[i - 1][j] > arr[i][j - 1])
                i--;
            else
                j--;
        }
    }

    reverse(str.begin(), str.end());

    cout << "Answer: " << str << endl;

    return 0;
}