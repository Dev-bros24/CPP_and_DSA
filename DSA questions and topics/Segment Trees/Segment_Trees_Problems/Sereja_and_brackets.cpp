#include<iostream>
using namespace std;

class bracCount{
public:
    int open;
    int closed;
    int full;
    bracCount(){
        open = 0;
        closed = 0;
        full = 0;
    }

    bracCount(int _open, int _closed, int _full){
        open = _open;
        closed = _closed;
        full = _full;
    }
};

bracCount merge(bracCount &left, bracCount &right){
    bracCount ret;
    ret.full = left.full + right.full + min(left.open, right.closed);
    ret.open = left.open + right.open - min(left.open, right.closed);
    ret.closed = left.closed + right.closed - min(left.open, right.closed);
    return ret;
}


void build(int ind, int low, int high, string &str, bracCount seg[]){
    if(low == high){
        if(str[low] == '(') seg[ind].open++;
        else seg[ind].closed++;
        return;
    }

    int mid = low + (high-low)/2;
    build(2*ind+1, low, mid, str, seg);
    build(2*ind+2, mid+1, high, str, seg);
    seg[ind] = merge(seg[2*ind+1], seg[2*ind+2]);
}

bracCount query(int ind, int low, int high, int l, int r, bracCount seg[]){
    if(l>high || r<low) return bracCount(0, 0, 0);
    else if(l<=low && high<=r) return seg[ind];

    int mid = low + (high - low)/2;
    bracCount left = query(2*ind+1, low, mid, l, r, seg);
    bracCount right = query(2*ind+2, mid+1, high, l, r, seg);
    return merge(left, right);
}

void solve(){
    string str;
    cin>>str;
    int m;
    cin>>m;
    int len = str.length();
    bracCount seg[4*len];

    build(0, 0, len-1, str, seg);

    while(m--){
        int l, r;
        cin>>l>>r;
        bracCount ans = query(0, 0, len-1, l-1, r-1, seg);
        cout<<2*ans.full<<endl;
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