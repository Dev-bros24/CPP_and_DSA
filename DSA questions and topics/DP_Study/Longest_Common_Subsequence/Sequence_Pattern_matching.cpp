#include<iostream>
#include<vector>
using namespace std;

/*
This problem has different variations, so doing it recursively might help
to do those problems which we might not be able to solve using LCS
*/

bool isoneSubsequenceofAnother(string s1, string s2){
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

    int lcs = arr[m][n];

    return lcs == min(m, n);
}

int main(){
    
    string s1 = "abc", s2 = "jsdlfajlpwutirewbuterptuiopcwee";

    if(isoneSubsequenceofAnother(s1, s2)) cout<<"Yes, one string is subsequence in another.";
    else cout<<"No, none of the strings is subsequence of the other one.";

    return 0;
}