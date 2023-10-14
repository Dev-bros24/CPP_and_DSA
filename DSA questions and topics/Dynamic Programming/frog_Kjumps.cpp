#include<iostream>
#include<vector>
using namespace std;

int frogJump(int ind, int heights[], int &n, int &k){
    static int count = 1;
    cout<<"Count: "<<count<<endl;
    count++;
    if(ind == n-1) return 0;

    int tempAns = 1e9;
    for(int z=1; z<=k; z++){
        if(ind+z<n) tempAns = min(frogJump(ind+z, heights, n, k) + abs(heights[ind] - heights[ind+z]), tempAns);
    }

    return tempAns;
}

int frogJumpDP(int ind, int heights[], int &n, int &k, vector<int> &memo){
    static int count = 1;
    cout<<"Count: "<<count<<endl;
    count++;
    if(ind == n-1) return memo[ind] = 0;

    if(memo[ind] != -1) return memo[ind];
    int tempAns = 1e9;
    for(int z=1; z<=k; z++){
        if(ind+z<n) tempAns = min(frogJumpDP(ind+z, heights, n, k, memo) + abs(heights[ind] - heights[ind+z]), tempAns);
    }

    return memo[ind] = tempAns;
}

void solve2(){
    int n, k;
    cout<<"Enter: "<<endl;
    cin>>n>>k;
    int heights[n];
    cout<<"Enter array: "<<endl;
    for(int i=0; i<n; i++) cin>>heights[i];
    // vector<int> memo(n+1, -1);
    vector<int> arr(n, 1e9);
    arr[n-1] = 0;

    // int ans = frogJump(0, heights, n, k);
    // int ans = frogJumpDP(0, heights, n, k, memo);

    // for(int i=0; i<n; i++) cout<<"i: "<<i<<" "<<memo[i]<<" "<<endl;

    // cout<<"Answer: "<<ans<<endl;

    //Tabulation
    for(int i=n-2; i>=0; i--){
        for(int z=1; z<=k; z++){
            if(i+z<n) arr[i] = min(arr[i], abs(heights[i+z]-heights[i]) + arr[i+z]);
        }
    }

    cout<<"Answer: "<<arr[0]<<endl;
}

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    solve2();
    return 0;
}