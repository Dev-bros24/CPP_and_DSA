#include<iostream>
#include<map>
#include<climits>
using namespace std;

// Not optimum solution, TLE came in the last input of leetcode as we are calling substr function in every calculation.
// string minWindow(string s, string t) {
//         int n = s.length();
//         map<char, int> mp;

//         int count = 0;
//         string ans = "";

//         for(int i=0; i<t.length(); i++){
//             mp[t[i]]++;
//         }

//         int limit = mp.size();
//         int i = 0, j = 0;
//         bool flag = false;
//         int mini = INT_MAX;

//         while(j<n){
//             if(!flag){
//                 mp[s[j]]--;
//                 if(mp[s[j]] == 0) count++;
//             }
//             flag = false;

//             if(count < limit) j++;
//             else{
//                 if(j-i+1 < mini){
//                     ans = s.substr(i, j-i+1);
//                     mini = j-i+1;
//                 }
                
//                 mp[s[i]]++;
//                 if(mp[s[i]] == 1) count--;
//                 i++;
//                 flag = true;
//             }
//         }

//         return ans;
//     }


string minWindow(string s, string t) {
        int n = s.length();
        map<char, int> mp;
        int minstart = 0, minsize = 0;

        int count = 0;
        string ans = "";

        for(int i=0; i<t.length(); i++){
            mp[t[i]]++;
        }

        int limit = mp.size();
        int i = 0, j = 0;
        bool flag = false;
        int mini = INT_MAX;

        while(j<n){
            if(!flag){
                mp[s[j]]--;
                if(mp[s[j]] == 0) count++;
            }
            flag = false;

            if(count < limit) j++;
            else{
                if(j-i+1 < mini){
                    // ans = s.substr(i, j-i+1);
                    minstart = i;
                    minsize = j-i+1;
                    mini = j-i+1;
                }
                
                mp[s[i]]++;
                if(mp[s[i]] == 1) count--;
                i++;
                flag = true;
            }
        }

        ans = s.substr(minstart, minsize);
        return ans;
    }

int main(){
    string s = "cwaefgcf";
    string t = "cae";

    string ans = minWindow(s, t);
    cout<<"Answer: "<<ans<<endl;

    return 0;
}