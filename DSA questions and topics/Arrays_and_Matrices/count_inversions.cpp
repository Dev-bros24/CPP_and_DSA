#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void mergeAlgo(long long *arr, int low, int mid, int high, int &count){
    long long b[high+1];
    int k = low, i = low, j = mid+1;
    
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]) b[k++] = arr[i++];
        else {
            b[k++] = arr[j++];
            count = count + (mid-i+1);
        }
    }

    while(i<=mid) b[k++] = arr[i++];
    while(j<=high) b[k++] = arr[j++];
    
    for(int i=low; i<=high; i++){
        arr[i] = b[i];
    }
}

int mergeSort(long long *arr, int low, int high){
    static int count = 0;
    if(low<high){
        int mid = low + (high-low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        mergeAlgo(arr, low, mid, high, count);
    }
    return count;
}

long long getInversions(long long *arr, int n){
    int low = 0, high = n-1;
    int count = mergeSort(arr, low, high);
    return count;
}

int main(){
    // long long a[] = {3, 2, 1};
    // int size = 3;
    long long a[] = {2, 5, 1, 3, 4};
    int size = 5;

    long long ans = getInversions(a, size);

    cout<<"Answer: "<<ans;

    return 0;
}