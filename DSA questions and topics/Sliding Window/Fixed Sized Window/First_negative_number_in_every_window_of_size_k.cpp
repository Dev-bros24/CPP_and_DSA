#include<iostream>
#include<vector>
#include"../../abhi.h"
#include<list>
using namespace std;

vector<long long> bruteForce(long long int a[], long long int &n, long long int &k){
    vector<long long> ans;    

    for(int i=0; i<=n-k; i++){
        for(int j=i; j<i+k; j++){
            if(a[j] < 0){
                ans.push_back(a[j]);
                break;
            }
            if(j == i+k-1) ans.push_back(0);
        }
    }

    return ans;
}


vector<long long> optimisedSol(long long int a[], long long int &n, long long int &k){
    vector<long long> ans;
    list<int> lt;
    int i=0, j=0;

    while(j<n){
        if(a[j] < 0) lt.push_back(a[j]);
        if(j-i+1 < k) j++;
        else{
            if(!lt.empty()) ans.push_back(lt.front());
            else ans.push_back(0);
            if(a[i++] < 0) lt.pop_front();
            j++;
        }
    }

    return ans;
}


vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {                                                
    vector<long long> ans = bruteForce(A, N, K);                                     
    // vector<long long> ans = optimisedSol(A, N, K);                                     

    return ans;                                      
}

int main(){
    long long a[] = {-8, 2, 3, -6, 10};
    long long n = 5;
    long long k = 2;

    vector<long long> ans = printFirstNegativeInteger(a, n, k);

    cout<<"Answer: "<<endl;
    printArray(ans);

    return 0;
}