#include<iostream>
#include<vector>
using namespace std;

int main(){
    string str1 = "heap", str2 = "pea";
    int m = str1.length(), n = str2.length();
    vector<vector<int>> arr(m+1, vector<int>(n+1, -1));

    for(int j=0; j<=n; j++) arr[0][j] = 0;
    for(int i=0; i<=m; i++) arr[i][0] = 0;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(str1[i-1] == str2[j-1]) arr[i][j] = 1 + arr[i-1][j-1];
            else arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
        }
    }

    int lcs = arr[m][n];

    int del = m-lcs, ins = n-lcs;

    cout<<"Deletions: "<<del<<"\nInsertions: "<<ins<<endl;

    return 0;
}