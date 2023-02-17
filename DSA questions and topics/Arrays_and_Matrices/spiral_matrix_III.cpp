#include<iostream>
#include<vector>
#include"../abhi.h"
using namespace std;

vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int tC = rows*cols;
        vector<vector<int>> ans;
        int i = rStart, j = cStart;
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int cn = 1, dC = 0;
        ans.push_back(vector<int>{i, j});
        tC--;

        while(tC>0){
            for(int z=0; z<cn; z++){
                i = i+dx[dC];
                j = j+dy[dC];
                if(i<rows && i>=0 && j<cols && j>=0){
                    vector<int> temp{i, j};
                    ans.push_back(temp);
                    tC--;
                }
            }
            if(dC%2 != 0) cn++;
            dC = (dC+1) % 4;
        }      
       return ans;
    }

int main(){
    int rStart = 0, cStart = 0, rows = 0, cols = 0;
    // int rStart = 1, cStart = 4, rows = 5, cols = 6;
    cout<<"Enter the initial coordinates: "<<endl;
    cin>>rStart>>cStart;
    cout<<"Enter the size of the matrix: "<<endl;
    cin>>rows>>cols;

    vector<vector<int>> result = spiralMatrixIII(rows, cols, rStart, cStart);
    cout<<"Answer: "<<endl;
    printArray2D(result);

    return 0;
}