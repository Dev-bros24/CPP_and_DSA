#include<iostream>
#include<vector>

using namespace std;

/*
    SPOILER ALERT ** The thing which I tried here of putting point and range update together, I actually found out doesn't work in O(logn) TC for everything ** 

    We can't put point and range updates together because as you can see in below code point
    Update will have exponential TC which is not why Segment Tree was developed. So, this idea
    of mine was a flop, but I got to learn this :). 

    This exponential TC is a compulsion on us because let's say someone does a range update 
    and then after that he does a point update. Now, in point update all the nodes which will
    be on the way to that node's point in the segment tree(the leaf node) will get updated 
    with the correct summation values but rest all which are yet to be updated with fresh values
    will not be there. So, that way if someone tries to query on a bigger range in which the 
    recursive call does not go below enough to touch those unfresh nodes and picks the answer 
    from above nodes then that will contain a wrong answer as the below nodes will also contribute
    in the answer.

    For below case I have one simple example input: 
    5
    3 1 9 8 4
    4
    3 0 2
    2 0 2 2
    1 1 7
    3 0 2

    here the correct output would be 13, 23 but if we implement the pointUpdate in the
    traditional way then the answer would come out to be 13, 19.
*/

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
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    void pointUpdate(int ind, int low, int high, int i, int value){
        // previous remaining range updates handling
        if(lazy[ind] != 0){
            seg[ind] += (high-low+1) * lazy[ind];
            if(low != high){
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        if(low == high && low == i){
            seg[ind] = value;
            return;
        }
        else if(low == high) return;

        int mid = low + (high-low)/2;
        pointUpdate(2*ind+1, low, mid, i, value);
        pointUpdate(2*ind+2, mid+1, high, i, value);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    void rangeUpdate(int ind, int low, int high, int l, int r, int value){ // entire range of elements will be increased by +value
        // previous remaining Range updates handling
        if(lazy[ind] != 0){
            seg[ind] += (high-low+1) * lazy[ind];
            if(low != high){
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        if(r < low || l > high) // no overlap
            return;

        // complete overlap
        if(l <= low && high <= r){
            seg[ind] += (high-low+1) * value;
            if(low != high){
                lazy[2*ind+1] = value;
                lazy[2*ind+2] = value;
            }
            return;
        }

        int mid = low + (high-low)/2;
        rangeUpdate(2*ind+1, low, mid, l, r, value);
        rangeUpdate(2*ind+2, mid+1, high, l, r, value);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    int query(int ind, int low, int high, int l, int r){
        // handle previous remaining updates first
        if(lazy[ind] != 0){
            seg[ind] += (high-low+1) * lazy[ind];
            if(low != high){
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        // no overlap
        if(r<low || l>high) return 0;
        // complete overlap
        else if(l <= low && high <= r) return seg[ind]; 
        // partial overlap
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
    cout<<"Enter the number of elements in the array: "<<endl;
    cin>>n;

    int arr[n];
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0; i<n; i++) cin>>arr[i];

    SGTree sg(n);
    sg.build(0, 0, n-1, arr);

    int t;
    cout<<"Enter the number of testcases: "<<endl;
    cin>>t;

    while(t--){
        int queryType;
        cout<<"Enter the type of query:\n1.For point update\n2.For rangeUpdate\n3.For query"<<endl;
        cin>>queryType;

        if(queryType == 1){
            int ind, val;
            cout<<"Enter the index of the array which is to be updated and the value: "<<endl;
            cin>>ind>>val;
            sg.pointUpdate(0, 0, n-1, ind, val);
        }
        else if(queryType == 2){
            int l, r, val;
            cout<<"Enter the initial and final indices of the array and the value by which each value will be incremented: "<<endl;
            cin>>l>>r>>val;
            sg.rangeUpdate(0, 0, n-1, l, r, val);
        }
        else{
            int l, r;
            cout<<"Enter the initial and final indices of the array of which you want the sum: "<<endl;
            cin>>l>>r;
            cout<<"The sum in the range "<<l<<" to "<<r<<" is: "<<sg.query(0, 0, n-1, l, r)<<endl;
            cout<<sg.query(0, 0, n-1, l, r)<<endl;
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


/*
Sample Input:

5
3 1 9 8 4
10
1 1 4
2 2 4 4
3 1 4
3 0 2
1 2 2
3 2 3
2 1 3 2
3 0 2 
3 2 4
3 3 4
*/