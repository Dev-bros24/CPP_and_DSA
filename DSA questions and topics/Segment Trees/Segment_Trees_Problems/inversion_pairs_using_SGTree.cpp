#include<iostream> // Not passed all test cases on Coding Ninjas
#include<vector>
using namespace std;

void build(int ind, int low, int high, vector<int> &arr, int seg[]){
    if(low == high){
        seg[ind] = arr[low];
        return;
    }
    int mid = low + (high - low)/2;
    build(2*ind+1, low, mid, arr, seg);
    build(2*ind+2, mid+1, high, arr, seg);
    seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}

// O(log(4*n)) ~ O(logn)
int query(int ind, int low, int high, int l, int r, int seg[]){
    if(r < low || high < l) return 0; // no overlap case
    else if(low >= l && high <= r) return seg[ind]; // complete overlap
    else{  // partial overlap
        int mid = low + (high-low)/2;
        int left = query(2*ind+1, low, mid, l, r, seg);
        int right = query(2*ind+2, mid+1, high, l, r, seg);
        return left + right;
    }
}

void update(int ind, int low, int high, int i, int seg[], int val){
    if(low == high){
        seg[ind] = val;
        return;
    }
    int mid = low + (high-low)/2;
    if(i<=mid) update(2*ind+1, low, mid, i, seg, val);
    if(i>mid) update(2*ind+2, mid+1, high, i, seg, val);
    seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int maxi = INT_MIN;
    for(int i=0; i<n; i++) maxi = max(arr[i], maxi);

    vector<int> freq(maxi+1, 0);
    for(int i=0; i<n; i++) freq[arr[i]]++;

    int seg[4*maxi+1]; 

    build(0, 0, maxi, freq, seg);
    // cout<<seg[0]<<endl;

    int count = 0;
    for(int i=0; i<n; i++){
        update(0, 0, maxi, arr[i], seg, freq[arr[i]] - 1);
        freq[arr[i]]--;
        count+=query(0, 0, maxi, 1, arr[i]-1, seg);
    }

    cout<<count<<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    solve();

    return 0;
}