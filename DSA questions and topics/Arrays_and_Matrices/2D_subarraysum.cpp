#include<iostream>
using namespace std;
const int N = 1e3 + 10;
long long arr[N][N];

int main(){
    int m, n;
    cout<<"Enter the number of rows and columns :"<<endl;
    cin>>m>>n;
    int ar[m][n];

    cout<<"enter the elements"<<endl;
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>ar[i][j];
            arr[i][j] = ar[i][j] + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1]; 
        }
    }

    cout<<"Your matrix is: "<<endl;
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout<<ar[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"the sum matrix is: "<<endl;
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    int q;
    cout<<"Enter the number of queries:"<<endl;
    cin>>q;
    while(q--)
    {   int a , b, c, d, sum=0;
        cout<<"Enter the range coordinates:"<<endl;
        cin>>a>>b>>c>>d;
        // for(int i=a; i<=c; i++)
        // {
        //     for(int j=b; j<=d; j++)
        //     {
        //         sum = sum + ar[i][j];
        //     }
        // }
        cout<<"the sum is: "<<arr[c][d] - arr[a-1][d] - arr[c][b-1] + arr[a-1][b-1]<<endl;
    }

    return 0;
}