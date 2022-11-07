#include <bits/stdc++.h>
using namespace std;

string getPermutation(int n, int k)
{
    vector<int> nums;
    int fact = 1;
    for (int i = 1; i < n; i++)
    {
        fact = fact * i;
        nums.push_back(i);
    }
    nums.push_back(n);
    string ans = "";
    k--;

    while (true)
    {
        ans = ans + to_string(nums[k / fact]);
        nums.erase(nums.begin() + k / fact);
        if (nums.size() == 0)
        {
            break;
        }
        k = k % fact;
        fact = fact / nums.size();
    }

    return ans;
}

int main()
{
    int n, k;

    cout << "Enter the number: " << endl;
    cin >> n;
    cout << "Enter the permutation sequence that you want: " << endl;
    cin >> k;

    string answer = getPermutation(n, k);

    cout << "The " << k << "th permutation of " << n << " is: " << endl;
    for (int i = 0; i < answer.length(); i++)
    {
        cout << answer[i] << " ";
    }

    return 0;
}