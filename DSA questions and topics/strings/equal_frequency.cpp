#include<bits/stdc++.h>
using namespace std;

bool equalFrequency(string word) {
        
        int n = word.length();

        for(int i=0; i<n; i++){
            cout<<"Abhishek i: "<<i<<endl;
            bool flag = true;
            vector<int> freq(26, 0);
            for(int j=0; j<n; j++){
                if(i == j) continue;
                else{
                    freq[word[j]-'a'] += 1;
                }
            }
            cout<<"Printing"<<endl;
            for(int p=0; p<5; p++){
                cout<<freq[p]<<" ";
            }
            int val = 0;
            for(int z=0; z<26; z++){
                if(freq[z]!=0){
                    val = freq[z];
                    break;
                }
            }
            cout<<"val : "<<val<<endl;
            for(int k=0; k<26; k++){
                if(freq[k] > 0 && freq[k] != val) {
                    flag = false;
                    break;
                }
            }
            if(flag == true) return true;
        }
        return false;
    }


int main(){

    string s = "abcc";

    cout<<equalFrequency(s);


    return 0;
}