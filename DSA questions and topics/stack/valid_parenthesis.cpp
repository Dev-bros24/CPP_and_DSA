#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

bool isValid(string s) {
        stack<char> st;
        int i=0;
        while(i<s.length()){
            if(s[i] == '{' || s[i] == '[' || s[i] == '(')
                st.push(s[i]);
            else{
                if(st.empty()) return false;
                else{
                    if(s[i] == ')' && st.top() == '(') st.pop();
                    else if(s[i] == ')') return false;
                    else if(s[i] == '}' && st.top() == '{') st.pop();
                    else if(s[i] == '}') return false;
                    else if(s[i] == ']' && st.top() == '[') st.pop();
                    else if(s[i] == ']') return false;
                }
            }
            i++;
        }
        
        if(st.empty()) return true;
        else return false;
    }


int main()
{
    string s = "(){}}{";
    bool answer = isValid(s);

    cout<<"Answer: "<<answer<<endl;

    return 0;
}