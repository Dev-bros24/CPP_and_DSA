#include<iostream>
#include<vector>
using namespace std;

class SGTree{
private:
    vector<int> seg;
    vector<int> lazy;

public:
    SGTree(int n){
        seg.resize(4*n + 1);
        lazy.resize(4*n + 1);
    }

    void build(int ind, int low, int high, int arr[]){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }

        int mid = low + (high-low)/2;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);
        seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
    }

    void update(int ind, int low, int high, int l, int r, int value){ // Range update, updating each value in the range by +value
        // update the previous remaining updates at
        // this node if any remaining
        if(lazy[ind] != 0){
            seg[ind] += lazy[ind];
            if(low != high){
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        // no overlap
        // l r low high || low high l r
        if(r < low || high < l) return;

        else if(l <= low && high <= r){ // complete overlap 
            seg[ind] += value;
            if(low != high){ // lazy propagation part
                lazy[2*ind+1] += value;
                lazy[2*ind+2] += value;
            }
        }

        else{ // partial overlap
            int mid = low + (high-low)/2;
            update(2*ind+1, low, mid, l, r, value);
            update(2*ind+2, mid+1, high, l, r, value);
            seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
        }
    }

    int query(int ind, int low, int high, int l, int r){
        // update the previous remaining updates at
        // this node if any remaining
        if(lazy[ind] != 0){
            seg[ind] += lazy[ind];
            if(low != high){
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        if(r < low || high < l) return INT_MAX; // no overlap
        else if(l <= low && high <= r) return seg[ind]; // complete overlap
        else{
            int mid = low + (high-low)/2;
            int left = query(2*ind+1, low, mid, l, r);
            int right = query(2*ind+2, mid+1, high, l, r);
            return min(left, right);
        }
    }
};

void solve(){
    int n;
    cout<<"Enter the number of elements of the array: "<<endl;
    cin>>n;
    int arr[n];

    cout<<"Enter the array elements: "<<endl;
    for(int i=0; i<n; i++) cin>>arr[i];

    SGTree sg(n);

    sg.build(0, 0, n-1, arr);

    int t;
    cout<<"Enter the number of queries: ";
    cin>>t;

    while(t--){
        int type;
        cout<<"Enter the type of query\n 1. for query \n 2. for update: "<<endl;
        cin>>type;
        if(type == 1){
            int l, r;
            cout<<"Enter the range: ";
            cin>>l>>r;
            cout<<"Minimum in the range "<<l<<" to "<<r<<" is: "<<sg.query(0, 0, n-1, l, r);
            cout<<sg.query(0, 0, n-1, l, r)<<endl;
        }
        else if(type == 2){
            int l, r, value;
            cout<<"Enter the range indices of the array and the value with which you want to update each of those values: "<<endl;
            cin>>l>>r>>value;
            sg.update(0, 0, n-1, l, r, value);
        }
    }
}

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    solve();

    return 0;
}