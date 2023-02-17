#include<iostream>
#include<unordered_map>
#include<vector>
#include<map>
#include"../../abhi.h"
using namespace std;

// Function to give count of anagrams
int search(string pat, string txt) {
	int i = 0, j = 0;
    int ans = 0;
    int n = txt.length();
    int k = pat.length();

    map<char, int> mp;
    for(int i=0; i<k; i++){
        mp[pat[i]]++;
    }

    int count = mp.size();

    while(j<n){
        if(mp.find(txt[j]) != mp.end()){
            mp[txt[j]]--;
            if(mp[txt[j]] == 0) count--;
        }

        if(j-i+1 < k) j++;
        else{
            if(count == 0) ans++;
            if(mp.find(txt[i]) != mp.end()){
                mp[txt[i]]++;
                if(mp[txt[i]] == 1) count++;
            }
            i++;
            j++;
        }
    }

    return ans;
}

// Function to return all anagrams start indices
vector<int> findAnagrams(string s, string p) {
    int i = 0, j = 0;
    vector<int> ans;
    int n = s.length();
    int k = p.length();

    map<char, int> mp;
    for(int i=0; i<k; i++){
        mp[p[i]]++;
    }

    int count = mp.size();

    while(j<n){
        if(mp.find(s[j]) != mp.end()){
            mp[s[j]]--;
            if(mp[s[j]] == 0) count--;
        }

        if(j-i+1 < k) j++;
        else{
            if(count == 0) ans.push_back(i);
            if(mp.find(s[i]) != mp.end()){
                mp[s[i]]++;
                if(mp[s[i]] == 1) count++;
            }
            i++;
            j++;
        }
    }

    return ans;
}

int main(){
    string txt = "forxxorfxdofr";
    string pat = "for";

    int ans = search(pat, txt);
    vector<int> answer = findAnagrams(txt, pat);

    cout<<"Answer: "<<ans<<endl;
    cout<<"The indices at which these anagrams are present are: "<<endl;
    printArray(answer);

    return 0;
}