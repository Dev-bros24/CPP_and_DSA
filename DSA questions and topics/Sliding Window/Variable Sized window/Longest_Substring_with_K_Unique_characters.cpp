#include<iostream>
#include<map>
using namespace std;

/*
    General Format for variable sized Sliding Window
    int i = 0, j = 0;
    while(j<size){
        calculations
        if(contd < k) j++;
        else if(contd == k){
            find answer from calculations
            j++;
        }
        else if(contd > k){
            while(contd > k){
                remove calculation for i
                i++;
            }
            j++;
        }
    }
    return ans;
*/

int longestKSubstr(string s, int k) {
    int i=0, j=0;
    int n = s.length();

    map<char, int> mp;

    int count = 0;
    int ans = -1;

    while(j<n){
        mp[s[j]]++;
        if(mp[s[j]] == 1) count++;

        if(count<k) j++;
        else if(count == k){
            ans = max(ans, j-i+1);
            j++;
        }
        else{
            while(count > k){
                mp[s[i]]--;
                if(mp[s[i]] == 0) count--;
                i++;
            }
            j++; // In this we can do this and it's not necessary to do that flag approach
            //(mentioned in problem Largest_Subarray_of_sum_K) because we need to find the
            // longest substring with K unique characters and if the number of unique 
            //characters goes above K then it's for sure that it will be by only 1 
            //character and then we can start removing from the start of the string and 
            //then also we'll be at a point where we get exactly K unique characters, 
            //BUT since we need to remove atleast 1 character from the string(then the 
            //length of the subarray becomes exactly equal to the case we have considered 
            //before adding the last character) we can just move end pointer and start 
            //considering the next windows from there. We don't need to consider the 
            //windows in between. 
        }
    }

    return ans;
}

int main(){
    string s = "aabacbebebe";
    int k = 3;

    int ans = longestKSubstr(s, k);
    cout<<"Answer: "<<ans<<endl;

    return 0;
}