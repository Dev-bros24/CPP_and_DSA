#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    // string s = "bmaopagbfbtkalpapoib";
    string s = "abafaa";
    int m = s.length();

    vector<vector<int>> arr(m+1, vector<int>(m+1, -1));

    for(int j=0; j<=m; j++) arr[0][j] = 0;
    for(int i=0; i<=m; i++) arr[i][0] = 0;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1] == s[j-1] && i!=j) arr[i][j] = 1 + arr[i-1][j-1];
            else arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
        }
    }

    int lrs = arr[m][m];
    string ans = "";

    int i = m, j = m;
    
    while(i>0 && j>0){
        if(s[i-1] == s[j-1] && i!=j){
            ans.push_back(s[i-1]);
            i--;
            j--;
        }
        else{
            if(arr[i-1][j] > arr[i][j-1]){
                i--;
            }
            else j--;
        }
    }

    reverse(ans.begin(), ans.end());


    cout<<"Longest repeating subsequence is: "<<ans<<"\nLength: "<<lrs;

    return 0;
}