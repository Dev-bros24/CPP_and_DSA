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

int main()
{
    int n;
    cout<<"Enter the number of elements in the array: "<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the array elements: "<<endl;
    for(int i=0 ; i<n; i++)
    {
        cin>>a[i];
    }

    cout<<"Please mention below that for how many numbers you want the count for"<<endl;
    int q; 
    cin>>q;
    int p = 1;
    while(q--)
    {
        int z, count=0;
        cout<<"Enter "<<p<<" number: "<<endl;
        cin>>z;
        for(int j=0; j<n; j++)
        {
            if(a[j] == z)
            {
                count++;
            }
        }
        cout<<"The count of "<<z<<" is: "<<count<<endl;
        p++;
    }
// complexity  O(Q*N) + O(N) = O(N^2)
    return 0;
}