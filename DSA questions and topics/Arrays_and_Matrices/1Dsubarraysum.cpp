#include<iostream>
using namespace std;
const int N = 1e7 + 10;
int ar[N];

// In case of subarray sums we should take 1 based arrays
int main(){
    int n, q;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the values"<<endl;
    for(int i=1; i<=n ; i++)
    {
        cin>>a[i];
        ar[i] = ar[i-1] + a[i];
    }


    cout<<"The array is"<<endl;
    for(int i=1; i<=n ; i++)
    {
        cout<<a[i]<<" ";
    }

    cout<<"\nThe sum array is"<<endl;
    for(int i=1; i<=n ; i++)
    {
        cout<<ar[i]<<" ";
    }


    cout<<"\nEnter number of queries"<<endl;
    cin>>q;
    while(q--)
    {
        cout<<"Enter from where to where you want the sum"<<endl;
        int l,r,sum=0;
        cin>>l>>r;
        // for(int j=l; j<=r; j++)
        // {
        //     sum = sum + a[j];
        //     // cout<<"Abhi"<<sum;
        // }
        cout<<"The sum of these numbers is: "<<ar[r] - ar[l-1]<<endl;

    }

    return 0;
}