#include<iostream>
#include<vector>
using namespace std;

vector<bool> sieveOfEratosthenes(int &number){
    vector<bool> sieve(number+1, true);
    sieve[0] = false;
    sieve[1] = false;

    for(int i = 2; i*i <= number; i++){
        for(int j = 2*i ; j <= number; j = j+i){
            sieve[j] = false;
        }
    }

    return sieve;
}

int main(){
    int num;
    cout<<"Enter the range upto which you want the prime numbers: "<<endl;
    cin>>num;

    vector<bool> ans = sieveOfEratosthenes(num);
    for(int i=0; i<=num; i++){
        cout<<i<<": ";
        if(ans[i]) cout<<"is Prime "<<endl;
        else cout<<"is NOT Prime"<<endl;
    }
    
    // for(int i=0; i<=num; i++){
    //     if(ans[i]) cout<<i<<" ";
    // }

    return 0;
}