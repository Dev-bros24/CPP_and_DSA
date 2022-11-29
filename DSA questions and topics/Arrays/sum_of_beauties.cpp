#include <iostream>
#include <vector>
using namespace std;

int sumOfBeauties(vector<int> &nums)
{
    int size = nums.size();

    vector<int> prefix(size), suffix(size);
    for (int i = 0, j = size - 1; i < size, j >= 0; i++, j--)
    {
        // cout<<"Abhishek i:"<<i<<" j: "<<j<<endl;
        if (i == 0 || nums[i] > prefix[i - 1])
        {
            // cout<<"If 1"<<endl;
            prefix[i] = nums[i];
        }
        else
        {
            // cout<<"else 1"<<endl;
            prefix[i] = prefix[i - 1];
        }

        if (j == size - 1 || nums[j] < suffix[j + 1])
        {
            suffix[j] = nums[j];
        }
        else
        {
            suffix[j] = suffix[j + 1];
        }
    }
    cout<<"Prefix max: "<<endl;
    for(int i=0; i<size; i++){
        cout<<prefix[i]<<" ";
    }

    cout<<"\nSuffix min: "<<endl;
    for(int i=0; i<size; i++){
        cout<<suffix[i]<<" ";
    }

    int beauty = 0;
    for (int i = 1; i < size-1; i++)
    {
        if (nums[i] > prefix[i - 1] && nums[i] < suffix[i + 1])
            beauty = beauty + 2;
        else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
            beauty++;
    }

    return beauty;
}

int main()
{
    vector<int> nums{1, 2, 3};

    int ans = sumOfBeauties(nums);

    cout << "\nAnswer: " << ans;

    return 0;
}