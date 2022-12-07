#include<iostream>
#include<climits>
#include<vector>
using namespace std;

// Recursion
int superEggDrop(int e, int f) {

    static int count = 1;
    cout<<"Count: "<<count<<endl;
    count++;

    if(e == 1 || f == 0 || f == 1) return f;   

    int ans = INT_MAX;
    for(int k=1; k<=f; k++){
        int tempans = 1 + max(superEggDrop(e-1, k-1), superEggDrop(e, f-k));
        ans = min(ans, tempans);
    }
    return ans;
}

// Memoization
int superEggDropDP(int e, int f, vector<vector<int>> &memo) {

    static int count = 1;
    cout<<"Count: "<<count<<endl;
    count++;

    if(e == 1 || f == 0 || f == 1) return f;   

    if(memo[e][f] != -1) return memo[e][f];
    int ans = INT_MAX;
    for(int k=1; k<=f; k++){
        int tempans = 1 + max(superEggDropDP(e-1, k-1, memo), superEggDropDP(e, f-k, memo));
        ans = min(ans, tempans);
    }
    return memo[e][f] = ans;
}

// Memoization better
int superEggDropDPbetter(int e, int f, vector<vector<int>> &memo) {

    static int count = 1;
    cout<<"Count: "<<count<<endl;
    count++;

    // cout<<"e: "<<e<<" f: "<<f<<endl;

    if(e == 1 || f == 0 || f == 1) return f;   

    if(memo[e][f] != -1) return memo[e][f];
    int ans = INT_MAX;
    for(int k=1; k<=f; k++){
        int left = 0, right = 0;
        if(memo[e-1][k-1] != -1) left = memo[e-1][k-1];
        else{
            left = superEggDropDPbetter(e-1, k-1, memo);
            memo[e-1][k-1] = left;
        }
        if(memo[e][f-k] != -1) right = memo[e][f-k];
        else{
            right = superEggDropDPbetter(e, f-k, memo);
            memo[e][f-k] = right;
        }

        int tempans = 1 + max(left, right);
        ans = min(ans, tempans);
    }
    return memo[e][f] = ans;
}

int main(){
    // int eggs = 2, floors = 6;
    int eggs = 2, floors = 2;
    // int eggs = 3, floors = 14;
    vector<vector<int>> memo(eggs+1, vector<int>(floors+1, -1));

    // int ans = superEggDrop(eggs, floors);
    // int ans = superEggDropDP(eggs, floors, memo);
    int ans = superEggDropDPbetter(eggs, floors, memo);

    // // Tabulation  --> Not working
    // vector<vector<int>> arr(eggs+1, vector<int>(floors+1, -1));

    // int e = eggs, f = floors;

    // for(int j=0; j<=f; j++) arr[0][j] = INT_MAX;
    // for(int i=0; i<=e; i++) arr[i][0] = 0;

    // for(int i=1; i<=e; i++){
    //     for(int j=1; j<=f; j++){
    //         for(int k=1; k<=j; k++){
    //             arr[i][j] = min(arr[i][j], 1 + max(arr[i-1][k-1], arr[i][j-k]));
    //         }
    //     }
    // }

    // int ans = arr[e][f];

    cout<<"Answer: "<<ans;

    return 0;
}