#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int main(){
    int t;
    // cout<<"Enter: "<<endl;
    cin>>t;

    while(t--){
        string s;
        cin>>s;
        int n = s.length();

        string a, b, c;
        bool flag = false;
        for(int i=0; i<n; i++){
            for(int j = i+1; j<n; j++){
                string a = s.substr(0, i+1);
                string b = s.substr(i+1, j-i);
                string c = s.substr(j+1, n-j-1);
                if((a.compare(b)>=0 && c.compare(b)>=0) || a.compare(b)<=0 && c.compare(b)<=0){
                    // cout<<"Abhishek: "<<t<<endl;
                    cout<<a<<" "<<b<<" "<<c<<endl;
                    flag = true;
                }
                if(flag) break;
            }
            if(flag) break;
        }
        if(!flag) cout<<":("<<endl;
    }
}