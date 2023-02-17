#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minTeams(int x, int y, int w){
    static int count = 1;
    cout<<"Count: "<<count<<endl;
    count++;

    if(w == 0) return 0;
    if(w < 0) return INT_MAX;
    int mini = INT_MAX;

    int ans = min(minTeams(x, y, w-x), minTeams(x, y, w-y));

    if(ans != INT_MAX)
    mini = min(mini, 1 + ans);

    return mini;
}

// int minTeams(int x, int y, int w){
//     // static int count = 1;
//     // cout<<"Count: "<<count<<endl;
//     // count++;

//     if(w == 0) return 0;
//     if(w < 0) return INT_MAX;
//     int mini = INT_MAX;

//     int ans = min(minTeams(x, y, w-x), minTeams(x, y, w-y));

//     if(ans != INT_MAX){
//         return min(mini, 1 + ans);
//     }
//     else return INT_MAX;
// }

int minTeamsDP(int x, int y, int w, vector<int> &memo){
    static int count = 1;
    cout<<"Count: "<<count<<endl;
    count++;

    if(w == 0) return 0;
    if(w < 0) return INT_MAX;

    if(memo[w] != -1) return memo[w];
    
    int mini = INT_MAX;

    int ans = min(minTeamsDP(x, y, w-x, memo), minTeamsDP(x, y, w-y, memo));

    if(ans != INT_MAX)return memo[w] = min(mini, 1 + ans);
    else return memo[w] = INT_MAX;
}

int main(){
    
    int n, x, y;
    cin>>x>>y>>n;

    vector<int> memo(n+1, -1);

    int ans = minTeams(x, y, n);
    // int ans = minTeamsDP(x, y, n, memo);

    if(ans == INT_MAX) cout<<"Ans: "<<-1<<endl;
    else cout<<"\nAns: "<<ans<<endl;

    return 0;
}