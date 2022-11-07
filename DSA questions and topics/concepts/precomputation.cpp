#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;

const int N = 1e5 + 10;
long long fact[N];

int main(){
    fact [0] = fact[1] = 1;
    for (int i=2; i<N; i++)
    {
        fact[i] = fact[i-1] * i;
    }
    int t;
    cout<<"Enter the number of values for which you want factorial modulo M: "<<endl;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        // int fact=1;
        // for(int i=2; i<=n; i++)
        // {
        //     fact = (fact * i) % M;
        // }
        // cout<<fact<<endl;
        cout<<"The factorial of "<<n<<" is: "<<fact[n]<<endl;
    }
    return 0;
}

// This code has a TC of O(T*N) or O(N^2) // OLD
// New complexity = O(N) + O(T) = O(N)  // as we are now just using the values which we have already stored.

// now as we know that it can ask factorials from 1 to 1e5, and numbers can be repeated in
// between we will store these values beforehand.