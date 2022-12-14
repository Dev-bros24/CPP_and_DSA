#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> vec1;
    cout << "Enter the values: " << endl;
    int m, n, temp;
    cin >> m >> n;
    cout << "Enter the matrix:" << endl;
    for (int i = 0; i < m; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int value;
            cin >> value;
            temp.push_back(value);
        }
        vec1.push_back(temp);
    }

    cout << "The vector of vector is:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << vec1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "The number of rows are: " << vec1.size() << endl;
    cout << "The number of columns are: " << vec1[0].size() << endl;
    return 0;
}