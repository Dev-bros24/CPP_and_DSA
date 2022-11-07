#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    if(nums2.size()<nums1.size()) return findMedianSortedArrays(nums2, nums1); // so that we apply binary search on smaller array

    int m = nums1.size();
    int n = nums2.size();

    int leftpart = (m + n + 1) / 2;

    int low = 0, high = m;
    int l1, l2, r1, r2;

    while (low <= high)
    {
        l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
        int cut1 = (low + high) / 2;
        int cut2 = leftpart - cut1;
        if (cut1 > 0)
            l1 = nums1[cut1 - 1];
        if (cut2 > 0)
            l2 = nums2[cut2 - 1];
        if (cut1 < m)
            r1 = nums1[cut1];
        if (cut2 < n)
            r2 = nums2[cut2];
        if (l1 <= r2 && l2 <= r1)
        {
            break;
        }
        else if (l2 > r1)
        {
            low = cut1 + 1;
        }
        else // l1 > r2
        {
            high = cut1 - 1;
        }
    }
    if ((m + n) % 2 == 0)
    {
        return ((double)max(l1, l2) + (double)min(r1, r2)) / 2.0;
    }
    else
    {
        return (double)max(l1, l2);
    }
}

int main()
{
    // vector<int> nums1 = {1, 2, 3};
    // vector<int> nums1 = {1, 2, 4, 8};
    vector<int> nums1 = {1, 3};
    // vector<int> nums2 = {3, 4};
    // vector<int> nums2 = {3, 4, 9, 13};
    vector<int> nums2 = {2};

    double answer = findMedianSortedArrays(nums1, nums2);

    cout << "Median is: " << answer;

    return 0;
}