#include <iostream>
#include <vector>
#include<cstring>
using namespace std;
int count = 0;

// int movebot(int i, int j, int arr[][500])
// {
//     int m = 5, n = 5;
//     count++;
//     cout << count << " ";
//     if (i == m - 1 && j == n - 1)
//     {
//         return 1;
//     }
//     else if (i >= m || j >= n)
//     {
//         return 0;
//     }
//     if (arr[i][j] != -1)
//     {
//         return arr[i][j];
//     }
//     else
//     {
//         return arr[i][j] = movebot(i + 1, j, arr) + movebot(i, j + 1, arr);
//     }
// }


int movebot2(int i, int j)
{
    count++;
    cout<<count<<endl;
    int m = 5, n = 4;
    if(i == m-1 && j == n-1)
    {
        return 1;
    }
    else if(i>=m || j>=n)
    {
        return 0;
    }
    else
    {
        return movebot2(i+1, j) + movebot2(i, j+1);
    }   
}

int main()
{
    int ans, ans2;
    int vec[500][500];
    memset(vec, -1, sizeof(vec));
    // cout<<"Initial array is:"<<endl;
    // for (int i=0; i<10; i++)
    // {
    //     for(int j=0;j<3; j++ )
    //     {
    //         cout<<vec[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // ans = movebot(0, 0, vec);
    ans2 = movebot2(0, 0);
    
    // ans = movebot(0, 0);
    // cout << "The answer is" << endl;
    // cout << ans;
    cout << "The answer on second term is" << endl;
    cout << ans2;
    return 0;
}