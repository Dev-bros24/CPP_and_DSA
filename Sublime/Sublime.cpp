#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        int k;
        cin>>n>>k;
        int a[n];

        for(int i=0; i<n; i++){
            cin>>a[i];
        }

        int num = 0; 
        int i=0;
        while(i<n){
            if(a[i] == num+1){
                num++;
            }
            i++;
        }

        int diff = n - num;
        int count = 0;
        while(diff>0){
            count++;
            diff-=k;
        }
        cout<<count<<endl;
    }

    return 0;
}