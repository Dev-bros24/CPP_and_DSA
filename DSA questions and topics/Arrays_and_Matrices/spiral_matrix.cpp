#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i = 0, j = 0;
        int m = matrix.size(), n = matrix[0].size();

        vector<int> ans;

        int l = 0, r = n-1, t = 0, b = m-1;
        while(l<=r && t<=b){
            for(int i=l; i<=r; i++) ans.push_back(matrix[t][i]);
            t++;
            for(int i=t; i<=b; i++) ans.push_back(matrix[i][r]);
            r--;
            if(t<=b) for(int i=r; i>=l; i--) ans.push_back(matrix[b][i]);
            b--;
            if(l<=r) for(int i=b; i>=t; i--) ans.push_back(matrix[i][l]);
            l++;
        }

        return ans;
    }

int main(){
    vector<vector<int>> matrix{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
        // {13, 14, 15, 16}
    };

    vector<int> ans = spiralOrder(matrix);

    cout<<"Answer: ";
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}