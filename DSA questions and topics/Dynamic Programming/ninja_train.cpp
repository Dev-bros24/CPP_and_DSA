#include<iostream>
#include<vector>
using namespace std;

int ninjaTrain(int ind, vector<vector<int>> &points, int last, int &n){
    if(ind == n) return 0;

    int tempAns = 0;
    for(int j=0; j<3; j++){
        if(j!=last) tempAns = max(tempAns, ninjaTrain(ind+1, points, j, n) + points[ind][j]);
    }

    return tempAns;
}

int ninjaTrainDP(int ind, vector<vector<int>> &points, int last, int &n, vector<vector<int>> &memo){
    if(ind == n) return memo[ind][last] = 0;
    if(memo[ind][last] != -1) return memo[ind][last];

    int tempAns = 0;
    for(int j=0; j<3; j++){
        if(j!=last) tempAns = max(tempAns, ninjaTrainDP(ind+1, points, j, n, memo) + points[ind][j]);
    }

    return memo[ind][last] = tempAns;
}

int ninjaTraining(int n, vector<vector<int>> &points){
    // return ninjaTrain(0, points, 3, n);
    // vector<vector<int>> memo(n+1, vector<int>(4, -1));
    // return ninjaTrainDP(0, points, 3, n, memo);

    //tabulation
    // vector<vector<int>> arr(n+1, vector<int>(4, -1));
    // for(int j=0; j<4; j++) arr[n][j] = 0;

    // for(int day=n-1; day>=0; day--){
    //     for(int last=0; last<=3; last++){
    //         for(int task = 0; task<3; task++){
    //             if(task != last){
    //                 arr[day][last] = max(arr[day][last], arr[day+1][task] + points[day][task]);
    //             }
    //         }
    //     }
    // }

    // return arr[0][3];


    //space optimisation
    vector<int> next(4, 0);

    for(int day=n-1; day>=0; day--){
        vector<int> curr(4);
        for(int last=0; last<=3; last++){
            for(int task = 0; task<3; task++){
                if(task != last){
                   curr[last] = max(curr[last], next[task] + points[day][task]);
                }
            }
        }
        next = curr;
    }

    return next[3];
}

void solve4(){
    int n;
    cin>>n;
    vector<vector<int>> points(n, vector<int>(3));
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin>>points[i][j];
        }
    }

    int ans = ninjaTraining(n, points);
    cout<<ans;
}

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    // solve();
    // solve2();
    // solve3();
    solve4();

    return 0;
}