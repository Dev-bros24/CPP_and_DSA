#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> price{1, 5, 8, 9, 10, 17, 17, 20};
    int N = 8;
    int size = price.size();
    vector<int> length(size);

    for(int i=0; i<size; i++){
        length[i] = i+1;
    }

    // Tabulation

    vector<vector<int>> arr(size+1, vector<int>(N+1, -1));

    for(int j=0; j<=N; j++){
        arr[0][j] = 0;
    }

    for(int i=0; i<=size; i++){
        arr[i][0] = 0;
    }

    for(int i=1; i<=size; i++){
        for(int j=1; j<=N; j++){
            if(length[i-1]<=j){
                arr[i][j] = max(arr[i][j-length[i-1]]+price[i-1], arr[i-1][j]);
            }
            else arr[i][j] = arr[i-1][j];
        }
    }

    int ans = arr[size][N];

    cout<<"Answer: "<<ans;

    return 0;
}