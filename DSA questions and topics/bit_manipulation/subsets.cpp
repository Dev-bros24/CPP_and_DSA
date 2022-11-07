#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(int a[], int n)
{
    vector<vector<int>> ans;
    for(int i=0; i< ((1<<n)); i++)
    {
        vector<int> temp;
        for(int bit = 0; bit<n; bit++)
        {
            if(i & 1<<bit) 
            {
                temp.push_back(a[bit]);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}

int main(){
    
    int a[5] = {1, 2, 3, 4, 5};
    int n = 5;

    vector<vector<int>> answer = subsets(a, n);

    cout<<"All the subsets are below "<<endl;
    for(int i=0; i<answer.size(); i++)
    {
        for(int j=0; j<answer[i].size(); j++)
        {
            cout<<answer[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}