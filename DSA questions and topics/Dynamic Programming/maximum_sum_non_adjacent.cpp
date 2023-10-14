#include<iostream>
#include<vector>
using namespace std;

/*
    Similar problems:
    1. House robber
*/

int maxSum(int ind, int arr[], int &n){
    static int count = 1;
    cout<<"count: "<<count<<endl;
    count++;

    if(ind >= n) return 0;

    int tempAns = 0;

    int pick = maxSum(ind+2, arr, n) + arr[ind];
    int notpick = maxSum(ind+1, arr, n);

    return max(pick, notpick);
}

int maxSumDP(int ind, int arr[], int &n, vector<int> &memo){
    static int count = 1;
    cout<<"count: "<<count<<endl;
    count++;

    if(ind >= n) return 0;

    if(memo[ind] != -1) return memo[ind];

    int pick = maxSumDP(ind+2, arr, n, memo) + arr[ind];
    int notpick = maxSumDP(ind+1, arr, n, memo);  

    return memo[ind] = max(pick, notpick);
}

void solve3(){
    int n;
    cin>>n;
    int arr[n];
    vector<int> memo(n+1, -1);
    int tab[n+1];

    for(int i=0; i<n; i++) cin>>arr[i];

    // int ans = maxSum(0, arr, n);
    // int ans = maxSumDP(0, arr, n, memo);

        /*
    Tabulation
    tab[n] = 0;
    for(int i=n-1; i>=0; i--){
        int pick = 0, notpick = 0;
        int nextind = (i+2>=n) ? n : i+2;
        pick = tab[nextind] + arr[i];
        nextind = (i+1>=n) ? n : i+1;
        notpick = tab[i+1];
        tab[i] = max(pick, notpick);
    }

    cout<<ans;
    cout<<tab[0];

        */

        // Space optimisation
    int next1 = arr[n-1], next2 = 0;
    int cur = arr[n-1];
    for(int i=n-2; i>=0; i--){
        int pick = arr[i] + next2;
        int notpick = next1;
        cur = max(pick, notpick);
        next2 = next1;
        next1 = cur;
    }

    cout<<cur;

}

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    solve3();
    return 0;
}