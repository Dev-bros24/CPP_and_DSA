#include<iostream>
#include<vector>
using namespace std;

/* 
Recursive and memoized solution for this problem will have a slightly diff approach
where we would need a third variable. This is not the best way to do this.
*/

int main(){
    string s1 = "ABCDGH", s2 = "ACDGHR";
    int m = s1.length(), n = s2.length();

    // vector<vector<int>> memo(m+1, vector<int>(n+1, -1));
    // int ans = subStr(s1, s2, m, n);
    // int ans = subStrDP(s1, s2, m, n, memo);

/*
// Tabulation --> Each cell of the table denotes that if we take that ith and jth elements of str1 and 2 respectively, then how much length of substring is there till that point from last breakpoint(point where the length again became zero because of non-contiguous behaviour)

    vector<vector<int>> arr(m+1, vector<int>(n+1, -1));

    for(int j=0; j<=n; j++) arr[0][j] = 0;
    for(int i=0; i<=m; i++) arr[i][0] = 0;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s1[i-1] == s2[j-1]){
                arr[i][j] = 1 + arr[i-1][j-1];
            }
            else arr[i][j] = 0;
        }
    }

    int max = 0;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(arr[i][j]>max) max = arr[i][j];
        }
    }

    int ans = max;
*/
    // cout<<"Answer: "<<ans;

    return 0;
}