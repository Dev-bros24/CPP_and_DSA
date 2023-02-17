#include<iostream>
#include<map>
using namespace std;

// max k types of toys can be picked
int maxToys(string s, int k){
    int i = 0, j = 0;
    int n = s.length();
    int count = 0;
    int ans = 0;

    map<char, int> mp;

    while(j<n){
        mp[s[j]]++;
        if(mp[s[j]] == 1) count++;

        if(count<=k){
            ans = max(ans, j-i+1);
            j++;
        }
        else{
            while(count > k){
                mp[s[i]]--;
                if(mp[s[i]] == 0) count--;
                i++;
            }
            j++;
        }
    }

    return ans;
}

int main(){
    string s = "abaccab";
    int k = 2;

    int ans = maxToys(s, k);
    cout<<"Answer: "<<ans<<endl;

    return 0;
}