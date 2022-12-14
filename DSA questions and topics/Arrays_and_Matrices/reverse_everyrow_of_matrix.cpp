#include<iostream>
#include<vector>
using namespace std;

void reverserows(vector<vector<int>>& mat)
{
    vector<int> temp;
        for (int i = 0; i<mat.size(); i++)
        {
            
            temp.clear();
            
            for(int j=mat.size()-1;j>=0 ; j--)
            {
                temp.push_back(mat[i][j]);
            }
            // cout<<"\nAbhishek"<<endl;
            // for(int q=0; q<temp.size(); q++)
            // {
            //     cout<<temp[q]<<" ";
            // } 
        temp.swap(mat[i]);
        }
}


int main()
{
    int n;
    vector<vector<int>> matrix;
    cout<<"Enter the rows and columns in the square matrix"<<endl;
    cin>>n;
    cout<<"Enter the nxn matrix"<<endl;
    for (int i=0; i<n; i++)
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
    for (int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    reverserows(matrix);
    cout<<"\nThe reversed matrix is:"<<endl;
    for (int i=0; i<matrix.size(); i++)
    {
        for(int j=0; j<matrix[i].size(); j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}