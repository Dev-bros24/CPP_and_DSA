#include<bits/stdc++.h>
using namespace std;

string addBinary(string a, string b) {
        int i = a.length() - 1;
        int j = b.length() - 1;

        int carry = 0;
        string ans = "";

        while(i>=0 || j>=0 || carry == 1){
            int x = 0, y = 0;
            if(i>=0 && a[i] == '1') x = 1;
            if(j>=0 && b[j] == '1') y = 1;
            
            int sum = x + y + carry;
            carry = sum/2;
            ans = to_string(sum%2) + ans;
            i--;
            j--;
        }
        return ans;
    }

int main(){

    string a = "11";
    string b = "1";

    string answer = addBinary(a, b);

    cout<<"Answer: "<<answer;
}