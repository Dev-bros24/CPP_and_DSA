#include<iostream>
#include<cmath>
using namespace std;

void build(int ind, int low, int high, int arr[], int seg[], bool isor){
    if(low == high){
        seg[ind] = arr[low];
        return;
    }

    int mid = low + (high-low)/2;
    build(2*ind+1, low, mid, arr, seg, !isor);
    build(2*ind+2, mid+1, high, arr, seg, !isor);
    if(isor) seg[ind] = seg[2*ind+1] | seg[2*ind+2];
    else seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];
}

void update(int ind, int i, int value, int low, int high, int seg[], bool isor){
    if(low == high){
        seg[ind] = value;
        return;
    }

    int mid = low + (high-low)/2;
    if(i <= mid) update(2*ind+1, i, value, low, mid, seg, !isor);
    else update(2*ind+2, i, value, mid+1, high, seg, !isor);
    if(isor) seg[ind] = seg[2*ind+1] | seg[2*ind+2];
    else seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];
}

void solve(){
    int n, m;
    cin>>n>>m;
    int elements = pow(2, n);
    int arr[elements];
    for(int i=0; i<elements; i++) cin>>arr[i];
    int seg[4*elements+1];

    if(n%2) build(0, 0, elements-1, arr, seg, true);
    else build(0, 0, elements-1, arr, seg, false);

    while(m--){
        int p, b;
        cin>>p>>b;
        if(n%2) update(0, p-1, b, 0, elements-1, seg, true);
        else update(0, p-1, b, 0, elements-1, seg, false);
        // arr[p] = b;
        cout<<seg[0]<<endl;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    solve();

    return 0;
}