#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        cout << "Abhi: low: " << low << " mid: " << mid << " high: " << high << endl;
        if (nums[mid] == target)
        {
            return mid;
        }
            if (nums[mid] >= nums[low] && (nums[low] <= target && nums[mid] > target))
            {
                high = mid - 1;
            }
            else if (nums[mid] >= nums[low])
            {
                low = mid + 1;
                cout << "Abhi: " << low << endl;
            }
            else if (nums[high] >= target && nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        // if (high < 0 || low == nums.size())
        // {
        //     return -1;
        // }
    }
    if(low>high)
    return -1;

    return mid;
}

int main()
{
    // vector<int> nums = {4,5,6,7,0,1,2};
    // vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    vector<int> nums = {1, 3, 5};

    int target = 2;

    int answer = search(nums, target);

    cout << "Index is: " << answer << endl;
}