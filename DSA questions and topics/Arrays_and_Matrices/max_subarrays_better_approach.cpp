#include<iostream>
#include<vector>
using namespace std;

    int maxSubArray(vector<int>& nums) {
            int summax = nums[0];
            int sum =0;
            for(int i =0; i<nums.size(); i++)
            {
                 sum = sum + nums[i];
                   if ( sum > summax )
                   {
                       summax = sum;
                   }
                   if (sum < 0)
                   {
                       sum = 0;
                   }
            }
        return summax;
    }

int main(){
    vector<int> arr;
    int N;
    cout<<"Enter the number of elements in the array: "<<endl;
    cin>>N;
    cout<<"Enter the array: "<<endl;
    for(int i=0; i<N; i++)
    {
        int value=0;
        cin>>value;
        arr.push_back(value);
    } 

    int maxval = maxSubArray(arr);
    cout<<"Maximum value: "<<maxval;

    return 0;
}