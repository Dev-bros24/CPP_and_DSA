#include<bits/stdc++.h>
#include"../abhi.h"
using namespace std;

/*
    These are usually implemented using Double ended queues or deques. 
*/

// Monotonic increasing queue 
vector<int> slidingWindowMinimum(int arr[], int n, int k){
    vector<int> ans;
    deque<int> deq;

    // 0 1 2 3 4 5 6 7
    for(int i=0; i<n; i++){
        while(!deq.empty() && deq.front() <= i-k) deq.pop_front(); // pop any elements that are out of the window
        while(!deq.empty() && arr[deq.back()] > arr[i]) deq.pop_back(); 

        deq.push_back(i);
        if(i >= k-1){ // now we will start getting windows of size k
            ans.push_back(arr[deq.front()]);
        }
    }

    return ans;
}

// Monotonic Decreasing Queue
vector<int> slidingWindowMaximum(int arr[], int n, int k){
    vector<int> ans;
    deque<int> deq;

    for(int i=0; i<n; i++){
        while(!deq.empty() && deq.front() <= i-k) deq.pop_front();
        while(!deq.empty() && arr[deq.back()] < arr[i]) deq.pop_back();

        deq.push_back(i);
        if(i >= k-1){
            ans.push_back(arr[deq.front()]);
        }
    }

    return ans;
}

int main(){
    int arr[8] = {1, 3, -1, -3, 5, 3, 6, 7}; 
    int k = 3;

    printArray(arr, 8);
    cout<<"The minimums in the window of size "<<k<<" are below"<<endl;
    vector<int> res = slidingWindowMinimum(arr, 8, k);
    printArray(res);

    cout<<"The maximums in the window of size "<<k<<" are below"<<endl;
    vector<int> res2 = slidingWindowMaximum(arr, 8, k);
    printArray(res2);
}