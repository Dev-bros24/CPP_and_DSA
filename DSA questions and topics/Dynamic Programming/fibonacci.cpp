#include<iostream>
#include<vector>
using namespace std;

// Considering that the first term of fibonacci is 0 and it starts like 0 1 1 2 ...

// Normal recursion (TC ~ O(2^(n-1)), SC = O(n))
int fibo(int n){
    static int count = 1;
    cout<<"count: "<<count<<endl;
    count++;

    if(n<=1){
        return n;
    }
    return fibo(n-1) + fibo(n-2);
}

// Memoization DP (TC ~ O(n), SC = O(n) + O(n))
int fiboDP(int n, vector<int> &arr){
    static int count = 1;
    cout<<"count: "<<count<<endl;
    count++;

    if(n<=1){
        return n;
    }
    if(arr[n] != -1) return arr[n];

    return arr[n] = fiboDP(n-1, arr) + fiboDP(n-2, arr);
}

int main(){
    int n, answer = 0;
    cout<<"Enter the position that you want to find in fibonacci sequence: ";
    cin>>n;

    vector<int> arr(n, -1);
    answer = fibo(n-1);
    // answer = fiboDP(n-1, arr);

    cout<<"arr vector: "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }


// Tabulation (TC = O(n), SC = O(n))
/*
    arr[0] = 0;
    arr[1] = 1;
    for(int i=2; i<n; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    answer = arr[n-1];
*/

// Space Optimization (TC = O(n), SC = O(1))
/*
    int prev2 = 0, prev = 1, cur = 0;
    for(int i=2; i<n; i++){
        cur = prev + prev2;
        prev2 = prev;
        prev = cur;
    }
    answer = cur;
*/

    cout<<"\nThe number is: "<<answer<<endl;

    return 0;
}