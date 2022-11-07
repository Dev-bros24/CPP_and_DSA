#include<bits/stdc++.h>
using namespace std;

int countNumberOfLeftEle(vector<int> &row, int target)
{
    int low = 0, high = row.size()-1;

    while(low<=high)
    {
        int mid = (low+high)/2;
        if(row[mid]<=target) low = mid+1;
        else  high = mid-1;
    }
    return low;
}

int median(vector<vector<int>> &matrix, int R, int C)
{
    int leftpart = (R*C)/2;
        
        int num = INT_MAX;
        int arr[num];
        int low = 0, high = num-1;
        
        // int ans = 0;
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            int count = 0;
            for(int i=0; i<R; i++) count += countNumberOfLeftEle(matrix[i], mid);

            // cout<<"Abhishek mid: "<<mid<<" count: "<<count<<endl;
            
            if(count <= leftpart) low = mid+1;
            else high = mid-1;
            
        }
        return low;
}

int main(){
    
    // vector<vector<int>> nums = {{1, 3, 5}, 
    //                             {2, 6, 9}, 
    //                             {3, 6, 9}};
    
    vector<vector<int>> nums = {{1, 3, 5}, 
                                {2, 6, 9}, 
                                {3, 6, 9}};

    // vector<vector<int>> nums = {{1, 3, 5}};

    int rows = 3;
    int cols = 3;

    cout<<"Program begins"<<endl;
    int answer = median(nums, rows, cols);

    cout<<"Median is: "<<answer<<endl;

    return 0;
}