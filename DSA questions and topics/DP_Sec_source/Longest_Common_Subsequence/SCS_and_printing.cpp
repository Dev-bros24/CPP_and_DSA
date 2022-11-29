#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string shortestCommonSupersequence(string str1, string str2) {
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

        int i=m, j=n;
        string str = "";

        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                str.push_back(str1[i-1]);
                i--;
                j--;
            }
            else{
                if(arr[i-1][j] > arr[i][j-1]){
                    str.push_back(str1[i-1]);
                    i--;
                }
                else{
                    str.push_back(str2[j-1]);
                    j--;
                }
            }
        }
        // cout<<" i: "<<i<<" j: "<<j<<endl;
        while(i>0){
            str.push_back(str1[i-1]);
            i--;
        }
        while(j>0){
            str.push_back(str2[j-1]);
            j--;
        }

        reverse(str.begin(), str.end());
        return str;
    }

// Length of SCS
int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        // int m = X.length(), n = Y.length();
        vector<vector<int>> arr(m+1, vector<int>(n+1, -1));

        for(int j=0; j<=n; j++) arr[0][j] = 0;
        for(int i=0; i<=m; i++) arr[i][0] = 0;

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(X[i-1] == Y[j-1]) arr[i][j] = 1 + arr[i-1][j-1];
                else arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
            }
        }
        
        return m+n-arr[m][n];
    }

int main(){

    string str1 = "abac", str2 = "cab";
    int size1 = str1.length(), size2 = str2.length();

    string ans = shortestCommonSupersequence(str1, str2);
    int len = shortestCommonSupersequence(str1, str2, size1, size2);

    cout<<"Answer: "<<ans<<" \nLength: "<<len<<endl;

    return 0;
}