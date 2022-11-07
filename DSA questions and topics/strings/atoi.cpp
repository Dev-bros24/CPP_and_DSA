#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

class Alphatonum{
    string s;

    public:
    Alphatonum(string st)
    {
        s = st;
    }

    int alphtoint()
    {
        int flag = 1;
        int ans = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == ' ')
            {
                continue;
            }
            else if(s[i] == '-')
            {
                flag = -1;
            }
            else if(s[i]>=48 && s[i]<58)
            {
                ans = ans*10 + (s[i]-'0');
            }
            else{
                break;
            }
        }
        return ans*flag;
    }
};

/*

class Solution {
public:
    int myAtoi(string s) {
        int flag = 1;
        long long ans = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == ' ' || s[i] == '+')
            {
                continue;
            }
            else if(s[i] == '-')
            {
                flag = -1;
            }
            else if(s[i]>=48 && s[i]<58)
            {
                ans = ans*10 + (s[i]-'0');
            }
            else{
                break;
            }
        }
        if(ans * flag > pow(2,31)-1 )
        {
            return pow(2,31)-1;
        }
        else if(ans*flag < (-1*pow(2,32)))
        {
            return -1*pow(2,31);
        }
        else
        {
            return ans*flag;
        }
        
    }
};

*/





int main(){
    Alphatonum a("   35676  fsarewfrgre");
    int num = a.alphtoint();

    cout<<num-1<<endl;
    cout<<num<<endl;
    cout<<num+1<<endl;

    cout<<INT32_MIN<<endl;
    cout<<INT32_MAX<<endl;

    cout<<pow(2,31) - 1;

    return 0;
}