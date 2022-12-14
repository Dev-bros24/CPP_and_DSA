#include<iostream>
using namespace std;

string convert(string &str){
        // cout<<"Abhishek "<<str<<endl;
        int n = str.length();
        string ans = "";
        long long count = 1, i=0;
        while(i<n){
            count = 1;
            while(i<n-1 && str[i] == str[i+1]){
                count++;
                i++;
            }
            ans = ans + to_string(count);
            ans.push_back(str[i]);
            i++;
        }
        return ans;
    }

    string cas(int n){
        if(n == 1) return "1";

        string temp = cas(n-1);
        string res = convert(temp);
        return res;
    }

    string countAndSay(int n) {
        string ans = cas(n);

        return ans;
    }

int main(){
    int num = 8;
    string ans = countAndSay(num);

    for(int i=0; i<ans.length(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}