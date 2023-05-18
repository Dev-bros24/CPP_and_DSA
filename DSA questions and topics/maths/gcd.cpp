#include<iostream>
#include<vector>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    int n, m;
    cout<<"Enter the two numbers of which you want to find the GCD: "<<endl;
    cin>>n>>m;

    int ans = gcd(m, n);
    cout<<"Greatest common divisor of the two is: "<<ans<<" and the Lowest common multiple is: "<<(m*n)/ans<<endl;

    return 0;
}