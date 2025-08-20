#include<bits/stdc++.h>
#include"../abhi.h"
using namespace std;

// Monotonic Increasing Stack
vector<int> nextSmallerToLeft(int arr[], int n){  // Once we're pushing and once popping each element, so TC -> O(2*n) ~ O(n)
    vector<int> ans(n);
    stack<int> st;

    for(int i=0; i<n; i++){  // reverse this loop to get next smaller to right
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        if(st.empty()) ans[i] = -1;
        else ans[i] = arr[st.top()];
        st.push(i);
    }

    return ans;
}

// Monotonic Decreasing Stack
vector<int> nextGreaterToLeft(int arr[], int n){
    vector<int> ans(n);
    stack<int> st;

    for(int i=0; i<n; i++){ // reverse this loop to get next greater to right
        while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
        if(st.empty()) ans[i] = -1;
        else ans[i] = arr[st.top()];
        st.push(i);
    }

    return ans;
}

int main(){
    int arr[5] = {4, 1, 5, 6, 3}; 
    // int arr[5] = {4, 1, 5, 5, 3};

    printArray(arr, 5);
    cout<<"The next smaller element to the left side array is below"<<endl;
    vector<int> res = nextSmallerToLeft(arr, 5);
    printArray(res);

    cout<<"The next greater element to the left side array is below"<<endl;
    vector<int> res2 = nextGreaterToLeft(arr, 5);
    printArray(res2);
}