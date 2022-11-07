#include<bits/stdc++.h>
using namespace std;

void permute(vector<int> &nums, int size)
{
    // static int count = 1;
    // count++;
    // cout<<"Abhishek: "<<count<<endl;
    // for(int i=0; i<nums.size(); i++)
    // {
    //     cout<<nums[i]<<" ";
    // }
    // cout<<endl;

    int j = size-1;
    while( j>0 && nums[j-1]>nums[j]) j--;

    if(j>0)
    j--;

    int z = size-1;
    while(z>j && nums[j]>nums[z]) z--;

    if(z>j)
    {
        swap(nums[j], nums[z]);
    }
    
    reverse(nums.begin() + j + 1, nums.end());
}

string getPermutation(int n, int k)
{
    string ans;

    vector<int> nums;
    for(int i = 1; i<=n; i++)
    {
        nums.push_back(i);
    }

    int size = nums.size();

    for(int i=0; i<k-1; i++)
    {
        permute(nums, size);
    }
    
    for(int i=0; i<size; i++)
    {
        char ch = (char)(nums[i] + '0');
        ans.push_back(ch);
    }

    return ans;
}

int main(){
    int n, k;

    cout<<"Enter the number: "<<endl;
    cin>>n;
    cout<<"Enter the permutation sequence that you want: "<<endl;
    cin>>k;

    string answer = getPermutation(n, k);

    cout<<"The "<<k<<"th permutation of "<<n<<" is: "<<endl;
    for(int i=0; i<answer.length(); i++)
    {
        cout<<answer[i]<<" ";
    }

    return 0;
}