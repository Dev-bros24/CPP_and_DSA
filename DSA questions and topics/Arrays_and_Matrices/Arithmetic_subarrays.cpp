#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isArithmetic(vector<int> num, int low, int high){
        // cout<<"low: "<<low<<" high: "<<high<<endl;
        // cout<<"Abhishek: "<<endl;
        // for(int i=low; i<=high; i++){
        //     cout<<num[i]<<" ";
        // }
        sort(num.begin()+low, num.begin()+high+1);

        // cout<<"\nAbhishek: "<<endl;
        // for(int i=low; i<=high; i++){
        //     cout<<num[i]<<" ";
        // }
        // cout<<endl;
        int diff = num[low+1] - num[low];
        for(int i = low+1; i<=high; i++){
            if(num[i] - num[i-1] != diff) return false;
        }

        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        int m = l.size();
        vector<bool> ans(m, false);

        for(int i=0; i<m; i++){
            if(isArithmetic(nums, l[i], r[i])) ans[i] = true;
        }

        return ans;
    }


int main(){
    vector<int> nums{4,6,5,9,3,7};
    vector<int> l{0,0,2};
    vector<int> r{2,3,5};

    vector<bool> ans = checkArithmeticSubarrays(nums, l, r);

    cout<<"Below is the answer: "<<endl;
    for(int i=0; i<ans.size(); i++){
        if(i != ans.size()-1){
            if(ans[i]) cout<<"true, ";
            else cout<<"false, ";
        }
        else{
            if(ans[i]) cout<<"true";
            else cout<<"false";
        }
    }
    cout<<endl;

    return 0;
}