#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Recursion
int countWays(string &str, int i, int j, bool flag){

    static int count = 1;
    cout<<"Count: "<<count<<endl;
    count++;

    if(i>j) return false; // By this we're not saying false, by this we mean there are 0 ways in which we can parenthesize this expression to evaluate this expression to "flag"

    if(i==j){
        if(flag == true) return str[i] == 'T';
        else return str[i] == 'F';
    }

    int ans = 0;
    for(int k=i+1; k<j; k = k+2){
        int lT = countWays(str, i, k-1, true);
        int lF = countWays(str, i, k-1, false);
        int rT = countWays(str, k+1, j, true);
        int rF = countWays(str, k+1, j, false);

        if(str[k] == '&'){
            if(flag) ans = ans + lT*rT;
            else ans = ans + lT*rF + lF*rT + lF*rF;
        }
        else if(str[k] == '|'){
            if(flag) ans = ans + lT*rF + lF*rT + lT*rT;
            else ans = ans + lF*rF;
        }
        else{
            if(flag) ans = ans + lT*rF + lF*rT;
            else ans = ans + lF*rF + lT*rT;
        }
    }
    return ans;
}

// Memoization using 3D matrix
int countWaysDP(string &str, int i, int j, bool flag, vector<vector<vector<int>>> &memo){

    static int count = 1;
    cout<<"Count: "<<count<<endl;
    count++;

    if(i>j) return false; // This is not saying false, by this we mean there are 0 ways in which we can parenthesize this expression to evaluate this expression to "flag"

    if(i==j){
        if(flag == true) return str[i] == 'T';
        else return str[i] == 'F';
    }

    if(memo[i][j][flag] != -1) return memo[i][j][flag];

    int ans = 0;
    for(int k=i+1; k<j; k = k+2){
        int lT = countWaysDP(str, i, k-1, true, memo);
        int lF = countWaysDP(str, i, k-1, false, memo);
        int rT = countWaysDP(str, k+1, j, true, memo);
        int rF = countWaysDP(str, k+1, j, false, memo);

        if(str[k] == '&'){
            if(flag) ans = ans + lT*rT;
            else ans = ans + lT*rF + lF*rT + lF*rF;
        }
        else if(str[k] == '|'){
            if(flag) ans = ans + lT*rF + lF*rT + lT*rT;
            else ans = ans + lF*rF;
        }
        else{
            if(flag) ans = ans + lT*rF + lF*rT;
            else ans = ans + lF*rF + lT*rT;
        }
    }
    return memo[i][j][flag] = ans;
}

// Memoization using maps
int countWaysDPmap(string &str, int i, int j, bool flag, unordered_map<string, int> &memo){

    static int count = 1;
    cout<<"Count: "<<count<<endl;
    count++;

    if(i>j) return false; // this is not saying false, by this we mean there are 0 ways in which we can parenthesize this expression to evaluate this expression to "flag"

    if(i==j){
        if(flag == true) return str[i] == 'T';
        else return str[i] == 'F';
    }

    string temp = to_string(i);
    temp.push_back(' ');
    temp = temp + to_string(j);  // is same as temp.append(to_string(j));
    temp.push_back(' ');
    temp = temp + to_string(flag);

    if(memo.find(temp) != memo.end()) return memo[temp];

    int ans = 0;
    for(int k=i+1; k<j; k = k+2){
        int lT = countWaysDPmap(str, i, k-1, true, memo);
        int lF = countWaysDPmap(str, i, k-1, false, memo);
        int rT = countWaysDPmap(str, k+1, j, true, memo);
        int rF = countWaysDPmap(str, k+1, j, false, memo);

        if(str[k] == '&'){
            if(flag) ans = ans + lT*rT;
            else ans = ans + lT*rF + lF*rT + lF*rF;
        }
        else if(str[k] == '|'){
            if(flag) ans = ans + lT*rF + lF*rT + lT*rT;
            else ans = ans + lF*rF;
        }
        else{
            if(flag) ans = ans + lT*rF + lF*rT;
            else ans = ans + lF*rF + lT*rT;
        }
    }
    return memo[temp] = ans; 
    // return memo[temp] = ans%1003; // ans modulo 1003 is required at gfg
}


int main(){
    // string str = "T|T&F";
    // string str = "T|T&F^T";
    // string str = "T|F^F&T|F^F^F^T|T&T^T|F^T^F&F^T|T^F";
    string str = "T|F^F&T|F^F^F^T&T";
    int n = str.length();
    bool flag = true;
    int i=0, j = n-1;

    vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(2, -1)));

    unordered_map<string, int> mp;

    // int ans = countWays(str, i, j, flag);
    int ans = countWaysDP(str, i, j, flag, memo); 
    // int ans = countWaysDPmap(str, i, j, flag, mp);

    cout<<"Answer: "<<ans;

    return 0;
}