#include<iostream>
#include<vector>
using namespace std;

    int maxSubArray(vector<int>& nums) {
            int summax = nums[0];
        
            for(int i =0; i<nums.size(); i++)
            {
                int value = nums[i];
                cout<<"Abhishek i "<<i<<endl;
                for(int j=i+1; j<nums.size(); j++)
                {
                    
                    value = value +nums[j];
                    cout<<"Abhishek j"<<j<<"value is: "<<value<<endl;
                    if(value > summax)
                    {
                        summax = value;
                    }
                }
                 if(nums[i] > summax)
                    {
                        summax = nums[i];
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