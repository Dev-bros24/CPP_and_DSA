#include<iostream>
using namespace std;

bool rotateString(string s, string goal) {
        int size = s.length();
        for(int i=0; i< size; i++){
            s.push_back(s[0]);
            s = s.substr(1);
            cout<<s<<"  "<<goal<<endl;
            if(s == goal) return true;
        }
        return false;
    }

int main()
{
    if(rotateString("abcde", "cdeab"))
    {
        cout<<"Same";
    }
    else
    {
        cout<<"Not Same";
    }
    return 0;
}