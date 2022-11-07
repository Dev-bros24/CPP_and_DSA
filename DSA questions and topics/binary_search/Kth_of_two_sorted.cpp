#include<bits/stdc++.h>
using namespace std;

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    if(n > m) return (ninjaAndLadoos(row2, row1, n, m, k));
    
    int low = max(0, k-m), high = min(k, n);
    
    int l1, l2, r1, r2;
    
    while(low <= high)
    {
        int cut1 = (low+high)/2;
        l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
        int cut2 = k - cut1;
        
        if(cut1>0 && cut1<=n) l1 = row1[cut1-1];
        if(cut2>0 && cut2<=m) l2 = row2[cut2-1];
        if(cut1<n && cut1>=0) r1 = row1[cut1];
        if(cut2<m && cut2>=0) r2 = row2[cut2];

        if(l1<=r2 && l2<=r1) break;
        else if(l1>r2) high = cut1-1;
        else low = cut1+1;
        
    }
    
    return max(l1,l2);
}

int main(){
    vector<int> nums1 = {2, 3, 9, 9, 10, 11};
    vector<int> nums2 = {1, 1, 2, 4, 5, 6, 7, 8, 8, 9, 9, 13};

    // vector<int> nums1 = {2, 3, 4, 5, 7, 10, 10, 11, 12, 13};
    // vector<int> nums2 = {1, 3, 6, 9, 11, 12, 13, 13};

    int n = 6;
    int m = 12;
    int k = 18;

    // int n = 10;
    // int m = 8;
    // int k = 5;

    double answer = ninjaAndLadoos(nums1, nums2, m, n, k);

    cout << "Answer is: " << answer;

    return 0;
}