#include<iostream>
#include<vector>
using namespace std;


bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        bool flag = false;
        for(int i = 0; i<matrix.size(); i++)
        {
            if(matrix.size() == 1)
            {
                cout<<"Abhishek rows 1 "<<flag<<endl;
                for(int j = 0; j<matrix[0].size(); j++)
                {
                    if(target == matrix[i][j])
                    {
                        flag = true;
                    }
                }
                cout<<"Abhishek rows 1 end"<<flag<<endl;
            }
            else if(i < matrix.size() - 1)
            {
                cout<<"Else if i < matrix.size(): i "<<i<<" flag "<<flag<<endl;
            if(matrix[i][0]<=target && matrix[i+1][0]>target)
            {
                for(int j=0; j<matrix[i].size(); j++)
                {
                    if(matrix[i][j] == target)
                    {
                        flag = true;
                    }
                }
            }
                cout<<"Else if i < matrix.size() END "<<flag<<endl;
            }
            else
            {
                cout<<"else "<<flag<<endl;
                for( int j=0; j<matrix[i].size(); j++)
                {
                     if(matrix[i][j] == target)
                    {
                        flag = true;
                    }
                }
                cout<<"else END "<<flag<<endl;
            }
            if (flag == true)
            {
                break;
            }
        }
        return flag;
    }

int main(){
    int m, n, target;
    bool catchit;
    vector<vector<int>> mat;
    cout<<"Enter the number of rows and columns in the matrix:"<<endl;
    cin>>m>>n;
    cout<<"Enter the elements of the matrix:"<<endl;
    for(int i =0; i<m; i++)
    {
        vector<int> temp;
        for(int j=0; j<n; j++)
        {
            int value;
            cin>>value;
            temp.push_back(value);
        }
        mat.push_back(temp);
    }

    cout<<"Your matrix is:"<<endl;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n ; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Enter the element which you want to check:"<<endl;
    cin>>target;

    catchit = searchMatrix( mat, target);

    cout<<"Is the element present or not: "<<catchit;

    return 0;
}