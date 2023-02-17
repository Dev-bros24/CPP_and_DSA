#include<iostream>
#include<map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.length();
    map<char, int> mp;

    int i=0, j=0;
    bool flag = false;
    int ans = 0;

    while(j<n){
        mp[s[j]]++;
        if(mp[s[j]] == 2) flag = true;

        if(!flag){
            ans = max(ans, j-i+1);
            j++;
        }
        else{
            while(flag){
                mp[s[i]]--;
                if(mp[s[i]] == 1) flag = false;
                i++;
            }
            j++;
        }
    }

    return ans;
}

int main(){
    string s = "abcabcbb";

    int ans = lengthOfLongestSubstring(s);
    cout<<"Answer: "<<ans<<endl;

    return 0;
}