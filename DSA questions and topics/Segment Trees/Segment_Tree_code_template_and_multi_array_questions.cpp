#include<iostream>
#include<vector>
#include<climits>
using namespace std;

/* 
    Below is the template for 
*/

class SegmentMin{
    private:
        vector<int> seg;

    public:
        SegmentMin(int n){
            seg.resize(4 * n);
        }

        void build(int ind, int low, int high, int arr[]){
            if(low == high){
                seg[ind] == arr[low];
                return;
            }

            int mid = low + (high-low)/2;
            build(2*ind + 1, low, mid, arr);
            build(2*ind + 2, mid+1, high, arr);
            seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
        }

        int query(int ind, int low, int high, int l, int r){
            if(l > high || r < low) return INT_MAX; // no overlap
            else if(low <= l && r <= high) return seg[ind]; // complete overlap
            else{
                int mid = low + (high-low)/2;
                int left = query(2*ind+1, low, mid, l, r);
                int right = query(2*ind+2, mid+1, high, l, r);
                return min(left, right);
            }
        }

        void update(int ind, int low, int high, int i, int value){    // point update
            if(low == high == i){
                seg[ind] = value;
                return;
            }
            int mid = low + (high-low)/2;
            if(i <= mid) update(2*ind+1, low, mid, i, value);
            else update(2*ind+2, mid+1, high, i, value);

            seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
        }  
};

int main(){
    int n;
    cout<<"Enter the number of elements of the array: "<<endl;
    cin>>n;

    int arr[n];
    cout<<"Enter the array elements: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    SegmentMin s1(n);
    s1.build(0, 0, n-1, arr);
    cout<<"Segment Tree Build complete!"<<endl;

    

    return 0;
}