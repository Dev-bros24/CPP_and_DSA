#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> rotatematrix(vector<vector<int>> matrix)
{   
    vector<vector<int>> dummy;
        for (int i=0; i<matrix[0].size(); i++)
        {
            vector<int> temp;
            for(int j=matrix.size()-1; j>=0; j--)
            { 
                int value;
                value = matrix[j][i];
                temp.push_back(value);
            }
            dummy.push_back(temp);
        }
        return dummy;
}

int main(){
    int n, m;
    vector<vector<int>> matrix;
    cout<<"Enter the rows and columns in this matrix: "<<endl;
    cin>>m>>n;
    cout<<"Enter the matrix"<<endl;
    for (int i=0; i<m; i++)
    {
        vector<int> temp;
        for(int j=0; j<n; j++)
        {
            int value;
            cin>>value;
            temp.push_back(value);
        }
        matrix.push_back(temp);
    }

    cout<<"Your matrix is:"<<endl;
    for (int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    vector<vector<int>> matrixnew= rotatematrix(matrix);

    cout<<"Your matrix after rotation is:"<<endl;
    for (int i=0; i<matrixnew.size(); i++)
    {
        for(int j=0; j<matrixnew[0].size(); j++)
        {
            cout<<matrixnew[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}