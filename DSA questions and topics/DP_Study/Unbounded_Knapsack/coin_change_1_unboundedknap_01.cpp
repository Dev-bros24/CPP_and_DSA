#include<iostream>
#include<vector>
using namespace std;

// Recursion
int maxWays(vector<int> &coins, int amount, int n){

    static int count = 1;
    cout<<"Count: "<<count<<endl;
    count++;

    if(amount == 0) return 1;
    if(n == 0) return 0;
    
    if(coins[n-1] <= amount){
        return maxWays(coins, amount-coins[n-1], n) + maxWays(coins, amount, n-1);
    }
    else return maxWays(coins, amount, n-1);
}

// Memoization
int maxWaysDP(vector<int> &coins, int amount, int n, vector<vector<int>> &memo){

    static int count = 1;
    cout<<"Count: "<<count<<endl;
    count++;

    if(amount == 0) return 1;
    if(n == 0) return 0;
    
    if(memo[n][amount] != -1) return memo[n][amount];

    if(coins[n-1] <= amount){
        return memo[n][amount] = maxWaysDP(coins, amount-coins[n-1], n, memo) + maxWaysDP(coins, amount, n-1, memo);
    }
    else return memo[n][amount] = maxWaysDP(coins, amount, n-1, memo);
}           

int main(){
    int amount = 5;
    vector<int> coins{1,2,5};
    int size = 3;
    vector<vector<int>> memo(size+1, vector<int>(amount+1, -1));

    // int ans = maxWays(coins, amount, size);
    // int ans = maxWaysDP(coins, amount, size, memo);

    // Tabulation

    vector<vector<int>> arr(size+1, vector<int>(amount+1, -1));

    for(int j=0; j<=amount; j++){
        arr[0][j] = 0;
    }

    for(int i=0; i<=size; i++){
        arr[i][0] = 1;
    }

    for(int i=1; i<=size; i++){
        for(int j=1; j<=amount; j++){
            if(coins[i-1] <= j){
                arr[i][j] = arr[i][j-coins[i-1]] + arr[i-1][j];
            }
            else arr[i][j] = arr[i-1][j];
        }
    }

    int ans = arr[size][amount];

    cout<<"Answer: "<<ans<<endl;

    return 0;
}