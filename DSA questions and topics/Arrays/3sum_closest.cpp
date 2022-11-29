#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int closest = INT_MAX;
        int mindiff = INT_MAX;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int rem = target - nums[i];
            int low = i+1, high = n-1;
            while(low<high){
                int sum = nums[low] + nums[high];
                if(abs(rem - sum) < abs(mindiff)){
                    mindiff = rem-sum;
                    closest = nums[i] + sum;
                    cout<<"Inside if: closest: "<<closest<<" i: "<<i<<endl;
                }
                cout<<"Abhishek: "<<" low: "<<low<<" high: "<<high<<" mindiff: "<<mindiff<<" i: "<<i<<endl;
                if(mindiff == 0) return closest;

                if(rem > sum) low++;
                else high--;
            } 
        }
        return closest;
    }

int main(){
    vector<int> nums{4,0,5,-5,3,3,0,-4,-5};
    int target = -2;

    int ans = threeSumClosest(nums, target);

    cout<<"Answer: "<<ans;

    return 0;
}