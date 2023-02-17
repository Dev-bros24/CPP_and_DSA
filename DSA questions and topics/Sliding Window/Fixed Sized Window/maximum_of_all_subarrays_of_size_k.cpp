#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include"../../abhi.h"
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    // list<int> lt;
    deque<int> lt;
    int n = nums.size();

    int i=0, j=0;

    while(j<n){
        while(lt.size() && lt.back() < nums[j]) lt.pop_back();
        lt.push_back(nums[j]);

        if(j-i+1 < k) j++;
        else{
            ans.push_back(lt.front());
            if(lt.front() == nums[i]) lt.pop_front();
            i++;
            j++;
        }
    }

    return ans;
}

int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<int> ans = maxSlidingWindow(nums, k);
    cout<<"Answer is: "<<endl;
    printArray(ans);

    return 0;
}