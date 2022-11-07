#include<bits/stdc++.h>
using namespace std;

int onlyelement(vector<int> & nums)
{
    int size = nums.size();
    int left = 0;
    int right = size-2;

    // int mid = (left + right)/2;

    while(left <= right)
    {
        int mid = (left + right) >> 1; // divide by 2
        if(nums[mid] == nums[mid^1])
        {
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }
    }
    return nums[left];
}

int main()
{
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};

    int answer = onlyelement(nums);

    cout<<"Number is: "<<answer;

}