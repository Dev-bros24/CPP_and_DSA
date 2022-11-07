#include <bits/stdc++.h>
using namespace std;

/*

Given array a of N integers. Given Q queries and in each query there is a number
X for which we have to give the count in array.


Constraints

1<=N<=1e5
1<=a[i]<=1e7 
1<=Q<=1e5

*/

const int N = 1e7 + 10;
int hsh[N]; // Global arrays are by default initialized with 0 values

int main()
{
    int n;
    cout << "Enter the number of elements in the array: " << endl;
    cin >> n;
    int a[n];
    cout << "Enter the array elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        hsh[a[i]]++;
    }
    // cout << "Storing the count of each element in hash array. "<<endl;
    // for (int r = 0; r < n; r++)
    // {
    //     hsh[a[r]]++;
    // }

    cout << "Please mention below that for how many numbers you want the count for" << endl;
    int q;
    cin >> q;
    int p = 1;
    while (q--)
    {
        int z, count = 0;
        cout << "Enter " << p << " number: " << endl;
        cin >> z;
        // for(int j=0; j<n; j++)
        // {
        //     if(a[j] == z)
        //     {
        //         count++;
        //     }
        // }
        cout << "The count of " << z << " is: " << hsh[z] << endl;
        p++;
    }

    // Old complexity  O(Q*N) + O(N) = O(N^2)
    // New complexity  O(Q) + O(N) = O(N)

    return 0;
}