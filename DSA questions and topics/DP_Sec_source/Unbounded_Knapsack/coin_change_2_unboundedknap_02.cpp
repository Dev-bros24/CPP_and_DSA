#include<iostream>
#include<vector>
#include<climits>
using namespace std;

/*
In this question, in the tabulation method we need to fill the first row where
the array size is zero with infinite (INT_MAX-1). Rest of the first column with
0s. 
Note: In this question we need to fill the second row as well.
*/

// Recursion
int minCoins(int amount, vector<int> &coins, int n){

    if(amount == 0) return 0;
    if(n == 0) return INT_MAX-1; // Order of these two does not matter i.e. for the first row and first col we are having no issues with both 0 and INT_MAX-1
    
    // filling first row
    // if(n == 1){
    //     if(amount % coins[n-1]) return INT_MAX-1;
    //     else return amount/coins[n-1];
    // }

    if(coins[n-1]<=amount){
        return min(1 + minCoins(amount-coins[n-1], coins, n), minCoins(amount, coins, n-1));
    }
    else return minCoins(amount, coins, n-1);
}

// Memoization
int minCoinsDP(int amount, vector<int> &coins, int n, vector<vector<int>> &memo){

    if(amount == 0) return 0;
    if(n == 0) return INT_MAX-1;
    
    // filling first row
    // if(n == 1){
    //     if(amount % coins[n-1]) return INT_MAX-1;
    //     else return amount/coins[n-1];
    // }

    if(memo[n][amount] != -1) return memo[n][amount];

    if(coins[n-1]<=amount){
        return memo[n][amount] = min(1 + minCoinsDP(amount-coins[n-1], coins, n, memo), minCoinsDP(amount, coins, n-1, memo));
    }
    else return memo[n][amount] = minCoinsDP(amount, coins, n-1, memo);
}

int main(){
    int amount = 11;
    vector<int> coins{1, 2, 5};
    int size = 3;
    // int amount = 3;
    // vector<int> coins{2};
    // int size = 1;
    vector<vector<int>> memo(size+1, vector<int>(amount+1, -1));

    // int ans = minCoins(amount, coins, size);
    // int ans = minCoinsDP(amount, coins, size, memo);

    // Tabulation

    vector<vector<int>> arr(size+1, vector<int>(amount+1, -1));

    for(int j=0; j<=amount; j++){
        arr[0][j] = INT_MAX-1;
    }

    for(int i=0; i<=size; i++){
        arr[i][0] = 0;
    }

    for(int i=1; i<=size; i++){
        for(int j=1; j<=amount; j++){
            if(coins[i-1]<=j){
                arr[i][j] = min(1 + arr[i][j-coins[i-1]], arr[i-1][j]);
            }
            else arr[i][j] = arr[i-1][j];
        }
    }

    int ans = arr[size][amount];

    // if(ans > 10000) cout<<"Answer: "<<-1;
    if(ans == INT_MAX-1) cout<<"Answer: "<<-1;
    else cout<<"Answer: "<<ans<<endl;

    return 0;
}