#include <bits/stdc++.h> 
using namespace std;

void sums(int sum, int index,  vector<int> num, vector<int> &ans)
{
    cout<<"Abhi inside sum"<<endl;
    cout<<"Sum is: "<<sum<<" index: "<<index<<endl;
    if(index == num.size())
    {
        ans.push_back(sum);
        return;
    }
    sums(sum+num[index], index+1, num, ans);
    sums(sum, index+1, num, ans);
    return;
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    cout<<"Abhishek before sums call"<<endl;
    sums(0,0, num, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> vect = {1, 2, 3};
    cout<<"Abhishek before func call"<<endl;
    vector<int> answer = subsetSum(vect);
    

    cout<<"Answer: "<<endl;
    for(int i=0; i<answer.size(); i++)
    {
        cout<<answer[i]<<" ";
    }

    return 0;
}