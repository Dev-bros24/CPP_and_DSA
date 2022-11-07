#include<bits/stdc++.h>
using namespace std;



int main(){

    int n;

    // cout<<"Enter: "<<endl;
    cin>>n;
    int a[n];

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    bool flag = false;

    for(int i=0; i< ((1<<n)); i++)
    {    
        int value = 0;
        for(int bit = 0; bit<n; bit++)
        {
            if(i & 1<<bit) 
            {
                value = value + a[bit];
            }
            else{
                value = value - a[bit];
            }
        }
        if(value%360 == 0)
        {
            flag = true;
            break;
        }    
    }

    if(flag)
    {
        cout<<"YES";
    }
    else cout<<"NO";

    return 0;
}