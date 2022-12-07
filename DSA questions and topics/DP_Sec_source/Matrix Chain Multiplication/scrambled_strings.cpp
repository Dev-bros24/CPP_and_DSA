#include<iostream>
#include<unordered_map>
using namespace std;

// Recursion
bool isScramble(string s1, string s2){

    static int count = 1;
    cout<<"Count: "<<count<<endl;
    count++;

    if(s1.compare(s2) == 0) return true;

    if(s1.length() != s2.length()) return false;
    if(s1.length()<=1) return false;

    bool flag = false;
    int n = s1.length();
    for(int i = 1; i<n; i++){
        if((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, n-i), s2.substr(i, n-i))) || 
        (isScramble(s1.substr(0, i), s2.substr(n-i, i)) && isScramble(s1.substr(i, n-i), s2.substr(0, n-i)))){
            flag = true;
            break;
        }
    }
    return flag;
}

// Memoization
bool isScrambleDP(string s1, string s2, unordered_map<string, bool> &mp){

    static int count = 1;
    cout<<"Count: "<<count<<endl;
    count++;

    if(s1.compare(s2) == 0) return true;
    if(s1.length() != s2.length()) return false;
    if(s1.length()<=1) return false;

    string tempStr = s1 + "_" + s2;

    if(mp.find(tempStr) != mp.end()) return mp[tempStr];

    bool flag = false;
    int n = s1.length();
    for(int i = 1; i<n; i++){
        if((isScrambleDP(s1.substr(0, i), s2.substr(0, i), mp) && isScrambleDP(s1.substr(i, n-i), s2.substr(i, n-i), mp)) || 
        (isScrambleDP(s1.substr(0, i), s2.substr(n-i, i), mp) && isScrambleDP(s1.substr(i, n-i), s2.substr(0, n-i), mp))){
            flag = true;
            break;
        }
    }
    return mp[tempStr] = flag;
}

int main(){
    // string s1 = "grt", s2 = "rgt";
    string s1 = "greatlkuiszpgklh", s2 = "rgeatuipzslklkgh";
    // string s1 = "great", s2 = "rgeat";
    unordered_map<string, bool> memo;

    // bool ans = isScramble(s1, s2);
    bool ans = isScrambleDP(s1, s2, memo);

    if(ans) cout<<"Yes, they are scrambled";
    else cout<<"No, they aren't scrambled";

    return 0;
}