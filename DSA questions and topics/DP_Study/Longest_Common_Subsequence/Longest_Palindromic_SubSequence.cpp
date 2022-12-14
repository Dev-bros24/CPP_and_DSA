#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
LCS = Longest Common Subsequence
LCSS = Longest Common Substring
LPS = Longest Palindromic Subsequence
LPSS = Longest Palindromic Substring

Important point to note:

LPS = LCS(a, reverse(a))
but
LPSS != LCSS(a, reverse(a))

*/

int main(){
    string s = "bbbab";
    string s1 = s, s2 = s;
    reverse(s2.begin(), s2.end());

    int m = s.length();

    vector<vector<int>> arr(m+1, vector<int>(m+1, -1));

    for(int j=0; j<=m; j++) arr[0][j] = 0;
    for(int i=0; i<=m; i++) arr[i][0] = 0;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1] == s2[j-1]) arr[i][j] = 1 + arr[i-1][j-1];
            else arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
        }
    }

    int lps = arr[m][m];

    cout<<"Answer: "<<lps;

    return 0;
}