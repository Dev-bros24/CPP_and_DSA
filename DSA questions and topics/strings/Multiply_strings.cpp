#include<iostream>
#include<vector>
using namespace std;
int M = 1e9+7;

// Returns the integer value after the multiplication, if exceeds the limit returns %M
int multiplyStrings(string num1, string num2){

    int m = num1.length(), n = num2.length();
    int i = n-1, mf = 1; // multiplication_factor
    int ans = 0;
    while(i>=0){
        int j = m-1;
        int carry = 0;
        int value = 0;
        int pf = 1; // power_factor 
        while(j>=0 || carry != 0){
            int ival = num2[i] - '0';
            int jval = 0;
            if(j>=0) jval = num1[j] - '0';
            
            int sum = (ival*jval) + carry;
            int val = sum % 10;
            carry = sum / 10;
            value = value + val*pf;
            pf = pf*10;
            j--;
        }
        ans = (ans + (value*mf)) % M;
        i--;
        mf = mf*10;
    }
    return ans;
}

// Returns a string after the multiplication
string multiplyStringsStr(string num1, string num2){
    if(num1 == "0" || num2 == "0") return "0";
    int m = num1.length(), n = num2.length();
    int i = n-1, mf = 0; // multiplication_factor
    vector<int> arr(m+n, 0);   // max length of multiplication of two numbers of length m and n can be m+n
    
    while(i>=0){
        int j = m-1;
        int carry = 0;
        int ival = num2[i--] - '0';
        int k = m+n-1-mf;

        while(j>=0 || carry != 0){
            int jval = 0;
            if(j>=0) jval = num1[j--] - '0';
            int prod = (ival*jval) + carry + arr[k];

            arr[k--] = prod % 10;
            carry = prod / 10;
            // j--;
            // k--;
        }
        // i--;
        mf++;
    }
    string ans = "";
    bool flag = false;

    for(int i=0; i<arr.size(); i++){
        if(arr[i] == 0 && !flag) continue;
        else{
            flag = true;
            char ch = arr[i] + '0';
            ans.push_back(ch);
        }
    }

    return ans;
}

int main(){
    string str1 = "0009998", str2 = "009876";

    // int ans = multiplyStrings(str1, str2);
    string ans = multiplyStringsStr(str1, str2);
    cout<<"Ans: "<<endl;

    for(int i=0; i<ans.length(); i++){
        cout<<ans[i];
    }

    return 0;
}