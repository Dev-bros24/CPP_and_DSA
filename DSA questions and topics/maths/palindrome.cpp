#include<iostream>
using namespace std;

bool isPalindrome(int x) {
        if(x<0) return false;
        
        long long reversed = 0;
        long long orig = x;
        
        while(x != 0){
            int lastdigit = x%10;
            reversed = reversed*10 + lastdigit;
            x = x/10;
        }
        
        if(orig == reversed) return true;
            
        return false;
    }

int main(){

    int x = 121;

    if(isPalindrome(x)){
        cout<<"Yes it's a palindrome"<<endl;
    }
    else{
        cout<<"No it's not a palindrome"<<endl;
    }

    return 0;
}