#include<iostream>
#include<vector>
using namespace std;


int main(){
    vector<vector<vector<int>>> arr(2, vector<vector<int>>(3, vector<int>(4, 1)));

    arr[1][1][2] = 4;

    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            for(int k=0; k<arr[i][j].size(); k++){
                cout<<arr[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<"\n";
    }


    return 0;
}