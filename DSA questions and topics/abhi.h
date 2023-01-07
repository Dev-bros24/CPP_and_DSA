#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> &vec){
    int n = vec.size();
    for(int i=0; i<n; i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

void printArray2D(vector<vector<int>> &vec){
    int m = vec.size();
    for(int i=0; i<m; i++){
        for(int j=0; j<vec[i].size(); j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}   