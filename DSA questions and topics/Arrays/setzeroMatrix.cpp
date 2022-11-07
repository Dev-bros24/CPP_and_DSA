#include <iostream>
using namespace std; // While receiving a 2D array in a function we need to give the column size as they are column specific.

void setZeros(int *arr, int p, int q)
{
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            // cout << *(arr + i * 200 + j) << " ";
            if (*(arr + i * 200 + j) == 0)
            {
                for (int col = 0; col < q; col++)
                {
                    if (*(arr + i * 200 + col) != 0 && col != j)
                    {
                        *(arr + i * 200 + col) = -1;
                    }
                }
                for (int row = 0; row < p; row++)
                {
                    if (*(arr + row * 200 + j) != 0 && row != i)
                    {
                        *(arr + row * 200 + j) = -1;
                    }
                }
            }
        }
    }
    // cout<<"Abhishek"<<endl;
    for (int y = 0; y < p; y++)
    {
        for (int z = 0; z < q; z++)
        {
            // cout<<"inside for loop"<<endl;
            if (*(arr + y * 200 + z) == -1)
            {
                // cout<<"Inside if condition"<<endl;
                // cout<<*(arr + y * 200 + z)<<endl;
                *(arr + y * 200 + z) = 0;
                // cout<<*(arr + y * 200 + z)<<endl;
            }
        }
    }
}

void dispArray(int *arr, int p, int q)
{
    for (int i = 0; i < p; i++)
    {
        // cout<<"This is "<<i+1<<" row"<<endl;
        for (int j = 0; j < q; j++)
        {
            cout << *(arr + i * 200 + j) << " "; // We have to give 200 here as we have to give the size of the column here as the array would take that much space and only then start storing the second row.
        }
        cout << endl;
    }
}

int main()
{
    int l, m, arr[200][200];
    cout << "Enter the no. of rows and columns in the matrix: " << endl;
    cin >> l >> m;
    cout << "Enter the matrix: " << endl;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "The input matrix is: " << endl;
    dispArray((int *)arr, l, m);

    cout<<"setZeros called..."<<endl;
    setZeros((int *)arr, l, m);

    cout << "The output matrix is: " << endl;
    dispArray((int *)arr, l, m);

    return 0;
}

// Dynamically storing matrix with dynamic column

// int l, m;
// cout << "Enter the no. of rows and columns in the matrix: " << endl;
// cin >> l >> m;
// cout << "Enter the matrix: " << endl;
// int **ary = new int*[l];
// for(int i = 0; i < l; ++i) {
//     ary[i] = new int[m];
// }
