#include<iostream>
#include<vector>
using namespace std;

/*
    This problem is finding the number of heads in coins which are stored in the array in form of
    0 and 1. 1 for heads and 0 for tails. Type 1 query is finding the number of coins in a given
    range and type 2 is flipping the coins in a given range. 
*/

class SGTree{
private:
    vector<int> seg;
    vector<int> lazy;

public:
    SGTree(int n){
        seg.resize(4*n + 1);
        lazy.resize(4*n + 1, 0);
    }

    void build(int ind, int low, int high, int arr[]){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }

        int mid = low + (high-low)/2;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    void update(int ind, int low, int high, int l, int r){ // Range update, updating each value in the range by +value
        // update the previous remaining updates at
        // this node if any remaining 
        if(lazy[ind] != 0){
            seg[ind] = (high-low+1) - seg[ind];
            if(low != high){
                lazy[2*ind+1] = !lazy[2*ind+1];
                lazy[2*ind+2] = !lazy[2*ind+2];
            }
            lazy[ind] = 0;
        }

        // no overlap
        // l r low high || low high l r
        if(r < low || high < l) return;

        else if(l <= low && high <= r){ // complete overlap 
            seg[ind] = (high-low+1) - seg[ind];
            if(low != high){ // lazy propagation part
                lazy[2*ind+1] = !lazy[2*ind+1];
                lazy[2*ind+2] = !lazy[2*ind+2];
            }
        }

        else{ // partial overlap
            int mid = low + (high-low)/2;
            update(2*ind+1, low, mid, l, r);
            update(2*ind+2, mid+1, high, l, r);
            seg[ind] = seg[2*ind+1] + seg[2*ind+2];
        }
    }

    int query(int ind, int low, int high, int l, int r){
        // update the previous remaining updates at
        // this node if any remaining
        if(lazy[ind] != 0){
            seg[ind] = (high-low+1) - seg[ind];
            if(low != high){
                lazy[2*ind+1] = !lazy[2*ind+1];
                lazy[2*ind+2] = !lazy[2*ind+2];
            }
            lazy[ind] = 0;
        }

        if(r < low || high < l) return 0; // no overlap
        else if(l <= low && high <= r) return seg[ind]; // complete overlap
        else{
            int mid = low + (high-low)/2;
            int left = query(2*ind+1, low, mid, l, r);
            int right = query(2*ind+2, mid+1, high, l, r);
            return left + right;
        }
    }
};

void solve(){
    int n;
    cout<<"Enter the number of coins: "<<endl;
    cin>>n;
    int arr[n];

    cout<<"Enter the array elements 1 for head and 0 for tails: "<<endl;
    for(int i=0; i<n; i++) cin>>arr[i];

    SGTree sg(n);

    sg.build(0, 0, n-1, arr);

    int t;
    cout<<"Enter the number of queries: ";
    cin>>t;

    while(t--){
        int type;
        cout<<"Enter the type of query\n 1. for query of number of heads in a range \n 2. for a single flip in a range: "<<endl;
        cin>>type;
        if(type == 1){
            int l, r;
            cout<<"Enter the range: ";
            cin>>l>>r;
            cout<<"Number of heads in the range "<<l<<" to "<<r<<" is: "<<sg.query(0, 0, n-1, l, r);
            cout<<sg.query(0, 0, n-1, l, r)<<endl;
        }
        else if(type == 2){
            int l, r;
            cout<<"Enter the range indices of the array: "<<endl;
            cin>>l>>r;
            sg.update(0, 0, n-1, l, r);
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