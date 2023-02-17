#include<iostream>
#include<vector>
using namespace std;

template <typename T>
void printArray(vector<T> &vec){
    long long n = vec.size();
    for(long long i=0; i<n; i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

template <typename T>
void printArray2D(vector<vector<T>> &vec){
    long long m = vec.size();
    for(long long i=0; i<m; i++){
        cout<<i<<" -> ";
        for(long long j=0; j<vec[i].size(); j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

template <typename T>
void printRange2D(vector<vector<T>> &vec){
    long long m = vec.size();
    for(long long i=0; i<m; i++){
        if(vec[i].size()){
            for(long long val : vec[i]){
                cout<<val<<" ";
            }
            cout<<endl;
        }
    }
    cout<<endl;
}

