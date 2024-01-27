#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<limits>
#include<cmath>
using namespace std;

// Recursion
int fJ(int ind, vector<int> heights, int &n){
    static int count = 1;
    cout<<"Count: "<<count<<endl;
    count++;

    if(ind == n-1){
        return 0;
    }
    
    int leftE = INT_MAX, rightE = INT_MAX;
    leftE = fJ(ind+1, heights, n) + abs(heights[ind] - heights[ind + 1]);
    if(ind<n-2)
    rightE = fJ(ind+2, heights, n) + abs(heights[ind] - heights[ind + 2]);

    return min(leftE, rightE);
}

// Memoization
int fJDP(int ind, vector<int> heights, vector<int> &arr){
    static int count = 1;
    cout<<"Count: "<<count<<endl;
    count++;

    if(ind == 0){
        return 0;
    }
    
    if(arr[ind] != -1) return arr[ind];
    int leftE = INT_MAX, rightE = INT_MAX;
    leftE = fJDP(ind-1, heights, arr) + abs(heights[ind] - heights[ind - 1]);
    if(ind>1)
    rightE = fJDP(ind-2, heights, arr) + abs(heights[ind] - heights[ind - 2]);

    return arr[ind] = min(leftE, rightE);
}

int frogJump(int n, vector<int> &heights){
    int ind = 0;
    vector<int> arr(n, -1);
    return fJ(ind, heights, n);
    // return fJDP(ind, heights, arr, n);

    // Tabulation
    // arr[0] = 0;
    // arr[1] = abs(heights[1] - heights[0]);

    // for(int i=2; i<n; i++){
    //     int leftE = abs(heights[i] - heights[i-1]) + arr[i-1];
    //     int rightE = abs(heights[i] - heights[i-2]) + arr[i-2];
    //     arr[i] = min(leftE, rightE);
    // }
    // return arr[n-1];

    // Space optimization
    // int prev2E = 0;
    // int prev1E = abs(heights[1] - heights[0]);
    // int curE = INT_MAX;

    // for(int i=2; i<n; i++){
    //     int leftE = abs(heights[i] - heights[i-1]) + prev1E;
    //     int rightE = abs(heights[i] - heights[i-2]) + prev2E;
    //     curE = min(leftE, rightE);
    //     prev2E = prev1E;
    //     prev1E = curE;
    // }
    // return curE; 
}

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
    cin>>n>>k;
    int heights[n];
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

void solve(){
    // vector<int> heights{10, 20, 30, 10};
    vector<int> heights{7, 4, 4, 2, 6, 6, 3, 4};
    // int n = 4;
    int n = 8;
    // vector<int> heights;
    // heights.push_back(10);
    // heights.push_back(20);
    // heights.push_back(30);
    // heights.push_back(10);
    // int n = 4;

    int ans = frogJump(n, heights);
    cout<<"Answer: "<<ans<<endl;
}

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
    // Tabulation
    // tab[n] = 0;
    // for(int i=n-1; i>=0; i--){
    //     int pick = 0, notpick = 0;
    //     int nextind = (i+2>=n) ? n : i+2;
    //     pick = tab[nextind] + arr[i];
    //     nextind = (i+1>=n) ? n : i+1;
    //     notpick = tab[i+1];
    //     tab[i] = max(pick, notpick);
    // }

    // // cout<<ans;
    // cout<<tab[0];

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

int uniquePaths(int i, int j, int m, int n){
    if(i == m-1 || j == n-1) return 1;
    if(i == m || j == n) return 0;

    return uniquePaths(i+1, j, m, n) + uniquePaths(i, j+1, m, n);
}

int uniquePathsDP(int i, int j, int m, int n, vector<vector<int>> &memo){
    if(i == m-1 || j == n-1) return memo[i][j] = 1;
    if(i == m || j == n) return 0;

    if(memo[i][j] != -1) return memo[i][j];
    return memo[i][j] = uniquePathsDP(i+1, j, m, n, memo) + uniquePathsDP(i, j+1, m, n, memo);
}

int totalPaths(int m, int n){
    // return uniquePaths(0, 0, m, n);
    // vector<vector<int>> memo(m, vector<int>(n, -1));
    // return uniquePathsDP(0, 0, m, n, memo);

    // tabulation
    // vector<vector<int>> dp(m, vector<int>(n, -1));

    // for(int i=0; i<m; i++) dp[i][n-1] = 1;
    // for(int j=0; j<n; j++) dp[m-1][j] = 1;

    // for(int i=m-2; i>=0; i--){
    //     for(int j=n-2; j>=0; j--){
    //         dp[i][j] = dp[i+1][j] + dp[i][j+1];
    //     }
    // }

    // return dp[0][0];

    // space optimisation using 1D Arrays
    vector<int> next(n, 1);

    for(int i=m-2; i>=0; i--){
        vector<int> cur(n);
        for(int j=n-1; j>=0; j--){
            if(j+1<n) cur[j] = next[j] + cur[j+1];
            else cur[j] = next[j];
        }
        next = cur;
    }

    return next[0];
}

void solve5(){
    int m, n;
    cin>>m>>n;
    int ans = totalPaths(m, n);
    cout<<ans;
}

int newPaths(int i, int j, int &m, int &n, vector<vector<int>> &maze){
    if(i == m-1 && j == n-1) return 1;
    if(i >= m || j>=n) return 0;
    if(maze[i][j] == -1) return 0;
    
    int M = 1e9+7;

    int res = newPaths(i+1, j, m, n, maze) + newPaths(i, j+1, m, n, maze);
    return res%M;
}

int M = 1e9 + 7;
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // return newPaths(0, 0, n, m, mat);

    // Tabulation
    // vector<vector<int>> dp(n, vector<int>(m, 0));   
    // dp[n-1][m-1] = 1;
    
    // for(int i=n-1; i>=0; i--){
    //     for(int j=m-1; j>=0; j--){
    //         if(i == n-1 && j == m-1) continue;
    //         else if(mat[i][j] == -1) dp[i][j] = 0;
    //         else{
    //             int right = 0, down = 0;
    //             if(j+1<m) right = dp[i][j+1];
    //             if(i+1<n) down = dp[i+1][j];
    //             dp[i][j] = (right + down) %M;
    //         }
    //     }
    // }

    // return dp[0][0];

    vector<int> next(n, 0);   
    
    for(int i=n-1; i>=0; i--){
        vector<int> curr(m);
        for(int j=m-1; j>=0; j--){
            if(i == n-1 && j == m-1) curr[m-1] = 1;
            else if(mat[i][j] == -1) curr[j] = 0;
            else{
                int right = 0, down = 0;
                if(j+1<m) right = curr[j+1];
                if(i+1<n) down = next[j];
                curr[j] = (right + down) %M;
            }
        }
        next = curr;
    }

    return next[0];
}

// 8 6
// 0 0 -1 0 0 0 
// -1 0 0 0 -1 0 
// 0 0 0 0 0 0 
// 0 -1 0 0 0 0 
// -1 -1 0 -1 -1 0 
// 0 0 -1 -1 0 0 
// 0 0 0 -1 0 0 
// 0 0 -1 0 -1 0 

void solve6(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>mat[i][j];
        }
    }

    int ans = mazeObstacles(n, m, mat);
    cout<<ans;
}

int minSumPath(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    // vector<vector<int>> memo(m, vector<int>(n, -1));
    // // return minSum(0, 0, m, n, grid);
    // return minSumDP(0, 0, m, n, grid, memo);

    // Tabulation
    // vector<vector<int>> tab(m, vector<int>(n));
    // tab[m-1][n-1] = grid[m-1][n-1];

    // for(int i=m-1; i>=0; i--){
    //     for(int j=n-1; j>=0; j--){
    //         if(i == m-1 && j == n-1) continue;
    //         else{
    //             int down = INT_MAX;
    //             int right = INT_MAX;
    //             if(i+1<m) down = tab[i+1][j];
    //             if(j+1<n) right = tab[i][j+1];
    //             tab[i][j] = grid[i][j] + min(right, down);
    //         }
    //     }
    // }

    // return tab[0][0];

    // Space optimisation
    vector<int> next(n);

    for(int i=m-1; i>=0; i--){
        vector<int> curr(n);
        for(int j=n-1; j>=0; j--){
            if(i == m-1 && j == n-1) curr[j] = grid[i][j];
            else{
                int down = INT_MAX, right = INT_MAX;
                if(j+1<n) right = curr[j+1];
                if(i+1<m) down = next[j];
                curr[j] = grid[i][j] + min(down, right);
            }
        }
        next = curr;
    }

    return next[0];
}

void solve7(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>mat[i][j];
        }
    }

    int ans = minSumPath(mat);
    cout<<ans;
}

template <typename T>
void printRange2D(vector<vector<T>> &vec){
    long long m = vec.size();
    for(long long i=0; i<m; i++){
        // if(vec[i].size()){
            for(T val : vec[i]){
                cout<<val<<" ";
            }
            cout<<endl;
        // }
    }
    cout<<endl;
}

string findLCS(int n, int m,string &s1, string &s2){
    // Write your code here.

    vector<vector<int>> tab(n+1, vector<int>(m+1));
    for(int i=0; i<=n; i++) tab[i][0] = 0;
    for(int j=0; j<=m; j++) tab[0][j] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1] == s2[j-1]){
                // cout<<"i: "<<i<<" j: "<<j<<endl;
                // cout<<"str val: "<<s1[i-1]<<" : "<<s2[j-1]<<endl;
                tab[i][j] = 1 + tab[i-1][j-1];
            }
            else tab[i][j] = max(tab[i-1][j], tab[i][j-1]);
        }
    }   

    string str = "";

    printRange2D(tab);

    int i=n, j=m;

    while(i>0 && j>0){ // to print LCS we can use tab[i][j] > 0 condition
        if(s1[i-1] == s2[j-1]){
            str.push_back(s1[i-1]);
            i--;
            j--;
        }
        else if(tab[i][j-1] > tab[i-1][j]){
            str.push_back(s2[j-1]); // for SCS
            j--;
        }
        else{
            str.push_back(s1[i-1]); // for SCS
            i--;
        }
    }

    while(i>0) {
        str.push_back(s1[i-1]); // for SCS
            i--;
    }
    while(j>0){
        str.push_back(s2[j-1]); // for SCS
            j--;
    }
    
    reverse(str.begin(), str.end());
    return str;
}

void solve8(){
    int n, m;
    cin>>n>>m;
    string s1, s2;
    cin>>s1>>s2;

    // string a = "Ah";
    // cout<<a<<endl;

    string res = findLCS(n, m, s1, s2);
    cout<<res<<endl;
}

void solve9()
{
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> vec(4, vector<int>(2));
        for(int i=0; i<4; i++){
            for(int j=0; j<2; j++){
                cin>>vec[i][j];
            }
        }
        int len = 0;
        int st = vec[0][0], pt = vec[0][1];
        for(int i=1; i<4; i++){
            if(vec[i][0] == st){
                len = abs(pt - vec[i][1]);
                break;
            }
        }
        cout<<len*len<<endl;
    }
}

void solve10(){
    int t;
    cin>>t;
    while(t--){
        int size;
        cin>>size;
        vector<char> s(size);
        vector<char> f(size);
        for(int i=0; i<size; i++) cin>>s[i];
        for(int i=0; i<size; i++) cin>>f[i];


        int totals = 0, totalf = 0, maxi = 0;
        for(int i=0; i<size; i++){
            if(s[i] == f[i]) continue;
            else if(s[i] == '1') totals++;
            else totalf++;
        }
        maxi = max(totalf, totals);
        cout<<maxi<<endl;
    }
}

void solve11(){
    int t;
    cin>>t;
    while(t--){
        long long n, f, a, b;
        cin>>n>>f>>a>>b;
        // cout<<"n: "<<n<<" f: "<<f<<" a: "<<a<<" b: "<<b<<endl;
        vector<int> vec(n);
        for(int i=0; i<n; i++) cin>>vec[i];
        int batteryStatus = f;
        bool flag = true;
        int time = 0;

        for(int i=0; i<n; i++){
            if(i == 0) time = vec[i];
            else time = vec[i] - vec[i-1];
            long long totalConsumed = (long long)time*(long long)a;
            int lesser = INT_MAX;
            lesser = min(totalConsumed, b);

            batteryStatus -= lesser;
            if(batteryStatus <= 0){
                flag = false;
                break;
            }
        }
        if(flag) cout<<"yes";
        else cout<<"no";
        cout<<endl;
    }
}

bool cmp(const int a, const int b){
    return a > b;
}

void solve12(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<int> vec1(n);
        vector<int> vec2(m);
        for(int i=0; i<n; i++){
            cin>>vec1[i];
        }
        for(int j=0; j<m; j++){
            cin>>vec2[j];
        }

        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());

        long long dS = 0;
        int i = 0, j = n-1, k = 0, l = m-1;
        int level = 0;
        while(i <= j){
            long long maxiMum = INT_MIN;
            int diff1 = abs(vec1[i] - vec2[l]);
            if(diff1 > maxiMum){
                maxiMum = diff1;
                level = 1;    
            }
            int diff2 = abs(vec1[i] - vec2[k]);
            if(diff2 > maxiMum){
                maxiMum = diff2;
                level = 2;    
            }
            int diff3 = abs(vec1[j] - vec2[k]);
            if(diff3 > maxiMum){
                maxiMum = diff3;
                level = 3;    
            }
            int diff4 = abs(vec1[j] - vec2[l]);
            if(diff4 > maxiMum){
                maxiMum = diff4;
                level = 4;    
            }

            if(level == 1){
                i++;
                l--;
            }
            else if(level == 2){
                i++;
                k++;
            }
            else if(level == 3){
                j--;
                k++;
            }
            else if(level == 4){
                j--;
                l--;
            }

            // cout<<"maxiMum: "<<maxiMum<<" level: "<<level<<endl;
            dS += maxiMum;
        }

        cout<<dS<<endl;
    }
}

void solve13(){
    int t;
    cin>>t;
    while(t--){
        int h, w, xa, ya, xb, yb;
        cin>>h>>w>>xa>>ya>>xb>>yb;

        if(abs(yb - ya) > abs(xb - xa) || xb <= xa){
            cout<<"Draw"<<endl;
            continue;
        }
        else{
                int winningRow = (xb - xa + 1)/2 + xa;
                if((xb - xa) % 2 != 0) // only Alice can win scenario
                {
                    if(yb == ya || ya == yb-1 || ya == yb + 1){
                        cout<<"Alice"<<endl;
                        continue;
                    }
                    else if(yb > ya){
                        int xDist = abs(xb - winningRow);
                        int yDist = abs(w - yb);
                        int maxYB = yb + min(xDist, yDist); //upto where he can Run
                        int diffA = abs(xa - winningRow);
                        int maxYA = ya + diffA;
                        if(maxYA >= maxYB){
                            cout<<"Alice"<<endl;
                            continue;
                        }
                        else{
                            cout<<"Draw"<<endl;
                            continue;
                        }
                    }
                    else{ // alice is on the right of Bob
                        int xDist = abs(xb - winningRow);
                        int yDist = abs(1 - yb);
                        int minYB = yb - min(xDist, yDist); //upto where he can Run
                        int diffA = abs(xa - winningRow);
                        int minYA = ya - diffA;
                        if(minYA <= minYB){
                            cout<<"Alice"<<endl;
                            continue;
                        }
                        else{
                            cout<<"Draw"<<endl;
                            continue;
                        }
                    }
                }
                else{ // only Bob can win
                    if(yb == ya){
                        cout<<"Bob"<<endl;
                        continue;
                    }
                    else if(yb > ya){ // Alice is on the left of Bob
                        int xDist = abs(winningRow - xa);
                        int yDist = abs(1 - ya);
                        int minYA = ya - min(xDist, yDist);
                        int diffB = abs(xb - winningRow);
                        int minYB = yb - diffB;
                        if(minYB <= minYA){
                            cout<<"Bob"<<endl;
                            continue;
                        }
                        else{
                            cout<<"Draw"<<endl;
                            continue;
                        }
                    }
                    else{
                        int xDist = abs(winningRow - xa);
                        int yDist = abs(w - ya);
                        int maxYA = ya + min(xDist, yDist);
                        int diffB = abs(xb - winningRow);
                        int maxYB = yb + diffB;
                        if(maxYB >= maxYA){
                            cout<<"Bob"<<endl;
                            continue;
                        }
                        else{
                            cout<<"Draw"<<endl;
                            continue;
                        }
                    }
                }
            }
        }
}

#define ll long long

void solve14(){
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n>>q;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin>>arr[i];
        while(q--){
            int s, d, k;
            cin>>s>>d>>k;
            int j = 1;
            long long sum = 0;
            for(int i = s-1; i < n && j <= k; i = i + d, j++){
                sum += arr[i]*j;
            }
            cout<<sum<<" ";
        }
        cout<<endl;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // solve();
    // solve2();
    // solve3();
    // solve4();
    // solve5();
    // solve6();
    // solve7();
    // solve8();
    // solve9();
    // solve10();
    // solve11();
    // solve12();
    // solve13();
    solve14();

    return 0;
}