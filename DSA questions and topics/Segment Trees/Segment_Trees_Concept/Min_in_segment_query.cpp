#include<iostream>
#include<climits>
using namespace std;

// TC --> O(4n)
void build(int ind, int low, int high, int arr[], int seg[]){
    if(low == high){
        seg[ind] = arr[low];
        return;
    }
    int mid = low + (high - low)/2;
    build(2*ind+1, low, mid, arr, seg);
    build(2*ind+2, mid+1, high, arr, seg);
    seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
}

// O(log(4*n)) ~ O(logn)
int query(int ind, int low, int high, int l, int r, int seg[]){
    // if(r < low || high < l) return INT_MAX; // no overlap case
    // if(low >= l && high <= r) return seg[ind]; // complete overlap
    // if(r < high || l > low){  // partial overlap
    //     int mid = low + (high-low)/2;
    //     int left = query(2*ind+1, low, mid, l, r, seg);
    //     int right = query(2*ind+2, mid+1, high, l, r, seg);
    //     return min(left, right);
    // }

    // Below is another approach in which we take partial overlap in else 
    if(r < low || high < l) return INT_MAX; // no overlap case
    else if(low >= l && high <= r) return seg[ind]; // complete overlap
    else{  // partial overlap
        int mid = low + (high-low)/2;
        int left = query(2*ind+1, low, mid, l, r, seg);
        int right = query(2*ind+2, mid+1, high, l, r, seg);
        return min(left, right);
    }
}

// O(log(4*n)) ~ O(logn) 
void update(int ind, int low, int high, int i, int seg[], int val){
    if(low == high){
        seg[ind] = val;
        return;
    }
    int mid = low + (high-low)/2;
    if(i<=mid) update(2*ind+1, low, mid, i, seg, val);
    if(i>mid) update(2*ind+2, mid+1, high, i, seg, val);
    seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
}

int main(){
    int n;
    cout<<"Enter the number of elements of the array: "<<endl;
    cin>>n;

    int arr[n];
    cout<<"Enter the array elements: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int seg[4 * n]; // proved that only 4*n element are required
    build(0, 0, n-1, arr, seg);
    cout<<"Segment Tree Build complete!"<<endl;

    int t;
    cout<<"Enter the testcases number: ";
    cin>>t;

    while(t--){
        int type;
        cout<<"Enter the testcase type: \n 1. For Query in a range \n 2. For Point Update \n";
        cin>>type;
        if(type == 1){
            int l, r;
            cout<<"Enter the first and second index of the range: ";
            cin>>l>>r;
            cout<<"Minimum in the range "<<l<<" to "<<r<<" is: ";
            cout<<query(0, 0, n-1, l, r, seg)<<endl;
        }
        else if(type == 2){
            int i, val;
            cout<<"Enter the array index and the value: ";
            cin>>i>>val;
            update(0, 0, n-1, i, seg, val);
            arr[i] = val;
        }
    }

    return 0;
}