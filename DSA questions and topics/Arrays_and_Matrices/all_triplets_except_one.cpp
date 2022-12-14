#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int> nums){
    int ans = 0;
    int n = nums.size();

    for(int i=0; i<32; i++){
        int sum = 0;
        for(int j=0; j<n; j++) if(nums[j] & 1<<i) sum++;
        if(sum%3) ans = ans | 1<<i;
    }
    return ans;
}

int main()
{
    vector<int> nums{2, 2, 2, 5, 6, 8, 9, 8, 6, 8, 5, 6, 5};

    int ans = singleNumber(nums);
    cout<<"Single number: "<<ans;

    return 0;
}