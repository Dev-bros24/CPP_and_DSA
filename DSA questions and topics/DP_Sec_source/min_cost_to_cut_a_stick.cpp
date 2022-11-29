#include<iostream>
#include<vector>
using namespace std;

// Recursive
int minCost(int ind, int n, vector<int> &cuts, int size){

    if(ind == size){

    }

    int cc = 0, ncc = 0;

    cc = min(n + minCost(ind+1, n-cuts[ind], cuts, size), minCost(ind+1, n, cuts, size));
}

int main(){
    int n = 7;
    vector<int> cuts = {1, 3, 4, 5};
    int index = 0;
    int size = 4;

    int answer = minCost(index, n, cuts, size);

    return 0;
}