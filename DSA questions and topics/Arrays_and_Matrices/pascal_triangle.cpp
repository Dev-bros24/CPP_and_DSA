 #include<iostream>
 #include<vector>
 #include<string>
 using namespace std;

vector<vector<int>> generate(int numRows) {
        vector<vector<int>> matrix;
        // matrix[0][0] = matrix[1][0] = matrix[1][1] = 1;
        // cout<<"Abhishek";
        for (int i = 0; i<numRows; i++)
        {
            vector<int> temp; 
            for (int j=0; j<=i; j++)
            {                
                if(j == 0 || j == i)
                {
                    // matrix[i][j] = 1;
                    temp.push_back(1);
                }
                else
                {
                    int value = 0;
                    value = matrix[i-1][j-1] + matrix[i-1][j];
                    temp.push_back(value);
                }
            }
            matrix.push_back(temp);
        }
        return matrix;
    }

 int main(){
    vector<vector<int>> mat;
    int N;
    cout<<"Enter the number of rows: "<<endl;
    cin>>N;
    int nspaces = N;
    mat = generate(N);
    cout<<"Pascal's traingle for "<<N<<" rows is: "<<endl;
    for(int i =0 ; i<mat.size(); i++)
    {
        cout<<string(nspaces,' ');
        for(int j = 0 ; j<mat[i].size() ; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
        nspaces--;
    }
    return 0;
 }
 