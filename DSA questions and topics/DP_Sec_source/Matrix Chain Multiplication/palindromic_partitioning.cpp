#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;

bool isPalindrome(string &str, int i, int j){
    if(i == j) return true;
    int lim = (j-i+1)/2 + i-1;
    for(int z = i; z<=lim; z++){
        if(str[z] != str[j-z+i]) return false;
    }
    return true;
}

// Recursion
int minPartitions(string &str, int i, int j){

    static int count = 1;
    cout<<"Count: "<<count<<endl;
    count++;

    if(i>=j || isPalindrome(str, i, j)) {
        return 0; 
    }

    int minAns = INT_MAX;
    for(int k=i; k<j; k++){
        int tempAns = minPartitions(str, i, k) + minPartitions(str, k+1, j) + 1;
        minAns = min(minAns, tempAns);
    }
    return minAns;
}

// Memoization
int minPartitionsDP(string &str, int i, int j, vector<vector<int>> &memo){

    static int count = 1;
    cout<<"Count: "<<count<<endl;
    count++;

    if(i>=j || isPalindrome(str, i, j)) {
        return 0; 
    }

    if(memo[i][j] != -1) return memo[i][j];  // If we move this check before the base condition then also this will change to almost as optimised solution as the one below one(only the extra function stack calls will not be made in that), because then also we'll not be checking the isPalindrome() function again.

    int minAns = INT_MAX;
    for(int k=i; k<j; k++){
        int tempAns = minPartitionsDP(str, i, k, memo) + minPartitionsDP(str, k+1, j, memo) + 1;
        minAns = min(minAns, tempAns);
    }
    return memo[i][j] = minAns;
}

// Memoization further optimised
int minPartitionsDPopt(string &str, int i, int j, vector<vector<int>> &memo){

    static int count = 1;
    cout<<"Count: "<<count<<endl;
    count++;

    if(i>=j || isPalindrome(str, i, j)) {
        return 0; 
    }

    if(memo[i][j] != -1) return memo[i][j]; 

    int minAns = INT_MAX;
    for(int k=i; k<j; k++){
        int left = 0, right = 0;
        if(memo[i][k] != -1) left = memo[i][k];
        else left = minPartitionsDPopt(str, i, k, memo);
        if(memo[k+1][j] != -1) right = memo[k+1][j];
        else right = minPartitionsDPopt(str, k+1, j, memo);

        int tempAns = left + right + 1;
        minAns = min(minAns, tempAns);
    }
    return memo[i][j] = minAns;
}

int main(){
    string str = "ababg";
    // string str = "abcd";
    // string str = "ababbbabbababa";
    // string str = "aaabba";
    // string str = "aab";
    // string str = "aba";
    int n = str.length();
    int i = 0, j = n-1;

    vector<vector<int>> memo(n, vector<int>(n, -1));

    // int ans = minPartitions(str, i, j);
    // int ans = minPartitionsDP(str, i, j, memo);
    int ans = minPartitionsDPopt(str, i, j, memo);

    /*
    Tabulation Initialization(not complete tabulation as of now)

    vector<vector<int>> arr(n, vector<int>(n, -1));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i>=j || isPalindrome(str, i, j)) arr[i][j] = 0;
        }
    }

    */

    cout<<"Answer: "<<ans;

    return 0;
}