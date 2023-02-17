#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

// Only for positive values in the array, if there are negative values in the array then the problem can't be solved using Sliding Window approach.
int lenOfLongSubarr(int A[],  int N, int K) 
{ 
    int i = 0, j = 0;
    int sum = 0;
    int maxi = INT_MIN;  
    bool flag = false;

    while(j<N){ 
        if(!flag)  //
        sum += A[j];
        flag = false; //
        
        if(sum<K) j++;
        else if(sum == K){
            maxi = max(maxi, j-i+1);
            j++;
        }
        else{
            while(sum > K){
                sum = sum - A[i++];
            }
            // j++; // this we can't do in this case because of the test case marked in ** as we need to check the subarray after removing the elements from beginning as well, hence we need to use the flag approach as shown
            flag = true; //
        }
    }

    return maxi;
} 

int main(){
    int a[] = {2, 2, 3, 5, 5, 5}; // ** 
    int n = 6;
    int k = 5;

    // int a[] = {10, 5, 2, 7, 1, 9};
    // int n = 6;
    // int k = 15;

    int ans = lenOfLongSubarr(a, n, k);
    cout<<"Answer: "<<ans<<endl;

    return 0;
}