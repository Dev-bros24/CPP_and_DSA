#include <iostream>
#include <vector>
using namespace std;
// Faaltu code --> doesn't work for cases like [2, 0] , 1, [1], 1
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    for (int i = 0; i < n; i++)
    {
        int value = nums2[i];
        int j = nums1.size() - 1;
        cout << "\nAbhishek " << i << "th " << value << endl;
        cout << "Abhishek j before:" << j << endl;
        while (nums1[j] == 0 && j!=0)
        {
            j--;
        }
        cout << "Abhishek j between:" << j << endl;
        while (value < nums1[j] )
        {
            j--;
        }
        cout << "Abhishek j after:" << j << endl;

        vector<int>::iterator it;
        if(*(nums1.begin()) !=0)
        {
        it = nums1.begin() + j + 1;
        }
        else{
            it = nums1.begin();
        }
        nums1.insert(it, value);

        cout << "Abhi: ";
        for (int i = 0; i < nums1.size(); i++)
        {
            cout << nums1[i] << " ";
        }
        for(int q=nums1.size()-1; q>=0;q--)
        {
            if(nums1[q]==0)
            {
                nums1.pop_back();
            }
        }
    }
}

int main()
{
    int m, n;
    vector<int> nums1{0}, nums2{1};
    // vector<int> nums1{1, 2, 3, 0, 0, 0}, nums2{2, 5, 6};
    cout << nums1.size() << " " << nums2.size() << endl;
    merge(nums1, 0, nums2, 1);
    cout << "Merged array" << endl;
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
    return 0;
}