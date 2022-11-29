/*
Knapsack problems are of 3 types:

1. Fractional knapsack --> In this we can put an item by dividing it into a fraction as well.
One item can be used only once to fill up the knapsack.
Greedy approach

2. 0 - 1 knapsack --> In this we can put either a whole item (1) or not put the entire item (0).
One item can be used only once to fill up the knapsack.
DP

3. Unbounded knapsack --> In this we can put either a whole item (1) or not put the entire item (0).
One item can be used as many times as we want to fill up the knapsack.
*/

#include<iostream>
#include<vector>
using namespace std;

// Normal Recursion
int maxProfit(int ind, vector<int> &weights, vector<int> &values, int capacity){

    static int count = 1;
    cout<<"Count: "<<count<<endl;
    count++;

    if(ind == weights.size() || capacity == 0) return 0;

    // cout<<"Inside function"<<endl;
    int pp = 0, np = 0, maxi = 0;
    for(int i=ind; i<weights.size(); i++){
        if(capacity >= weights[i]){
            // cout<<"Inside if: "<<capacity<<endl;
            pp = maxProfit(i+1, weights, values, capacity-weights[i]) + values[i];
        }
        np = maxProfit(i+1, weights, values, capacity);
        // cout<<"pp: "<<pp<<" np: "<<np<<" maxi: "<<maxi<<endl;
        maxi = max(maxi, max(pp, np));
    }
    return maxi;
}

// Memoization
int maxProfitDP(int ind, vector<int> &weights, vector<int> &values, int capacity, vector<vector<int>> &memo){

    static int count = 1;
    cout<<"Count memo: "<<count<<endl;
    count++;

    if(ind == weights.size() || capacity == 0) return 0;

    if(memo[capacity][ind]  != -1) return memo[capacity][ind];
    
    int pp = 0, np = 0, maxi = 0;
    for(int i=ind; i<weights.size(); i++){
        if(capacity >= weights[i]){
            pp = maxProfitDP(i+1, weights, values, capacity-weights[i], memo) + values[i];
        }
        np = maxProfitDP(i+1, weights, values, capacity, memo);
        maxi = max(maxi, max(pp, np));
    }
    return memo[capacity][ind] = maxi;
}

// Recursion 2
int maxProfit2(int ind, vector<int> &weights, vector<int> &values, int capacity){

    static int count = 1;
    cout<<"Count 2: "<<count<<endl;
    count++;

    if(capacity == 0 || ind == weights.size()) return 0;

    if(capacity >= weights[ind]){
        return max((values[ind] + maxProfit2(ind+1, weights, values, capacity-weights[ind])), maxProfit2(ind+1, weights,values, capacity));
    }
    else return maxProfit2(ind+1, weights, values, capacity);
}

// Memoization 2
int maxProfit2DP(int ind, vector<int> &weights, vector<int> &values, int capacity, vector<vector<int>> &memo){

    static int count = 1;
    cout<<"Count memo 2: "<<count<<endl;
    count++;

    if(capacity == 0 || ind == weights.size()) return 0;
    if(memo[capacity][ind] != -1) return memo[capacity][ind];

    if(capacity >= weights[ind]){
        return memo[capacity][ind] = max((values[ind] + maxProfit2DP(ind+1, weights, values, capacity-weights[ind], memo)), maxProfit2DP(ind+1, weights,values, capacity, memo));
    }
    else return memo[capacity][ind] = maxProfit2DP(ind+1, weights, values, capacity, memo);
}


int main(){
    
    vector<int> weights = {40, 30, 10, 60, 50};
    vector<int> values = {30, 40, 40, 60, 100};
    int capacity = 100;
    // vector<int> weights = {40, 30, 10};
    // vector<int> values = {30, 40, 40};
    // int capacity = 50;
    // vector<int> weights = {40, 30};
    // vector<int> values = {30, 40};
    // int capacity = 50;

    // int startpos = 0;
    int size = values.size();
    // vector<vector<int>> memo(capacity+1, vector<int>(size, -1));

    // int answer = maxProfit(startpos, weights, values, capacity);
    // int answer = maxProfitDP(startpos, weights, values, capacity, memo);
    // int answer = maxProfit2(startpos, weights, values, capacity);
    // int answer = maxProfit2DP(startpos, weights, values, capacity, memo);

    // Tabulation
    vector<vector<int>> arr(capacity+1, vector<int>(size+1, -1));

    for(int j=0; j<=size; j++){
        arr[0][j] = 0;
    }
    for(int i=0; i<=capacity; i++){
        arr[i][size] = 0;
    }

    for(int cap=1; cap<=capacity; cap++){
        int pp = 0, np = 0, maxi = 0;
        for(int j=size-1; j>=0; j--){
            if(cap >= weights[j]){
                pp = values[j] + arr[cap-weights[j]][j+1];
            }
            np = arr[cap][j+1];
            arr[cap][j] = max(pp, np); 
        }
    }

    int answer = arr[capacity][0];

    cout<<"Answer: "<<answer<<endl;

    return 0;
}