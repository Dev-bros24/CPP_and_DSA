#include<iostream>
#include<vector>
#include<climits>
using namespace std;

/* 
    Below is the template for Range Query Data Structure Segment Tree which finds minimum in a range. 
    This is the optimum choice for problems involving multiple arrays, hence need multiple segment trees
    corresponding to those arrays. 
    Here queries can be of the following type (Example of two arrays):
        Type 1 : We give L1, R1, L2, R2 and we say find the minimum in the range L1 and R1 from array 1
        and also the minimum in the Range L2 and R2 in array 2. Then finally return the minimum of that.
        Type 2 : We give three values i.e. arrayNum, ind and the val. Now, we have to update the value at 
        index ind of the array arrayNum with the value val. 
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
                seg[ind] = arr[low];
                return;
            }

            int mid = low + (high-low)/2;
            build(2*ind + 1, low, mid, arr);
            build(2*ind + 2, mid+1, high, arr);
            seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
        }

        int query(int ind, int low, int high, int l, int r){
            if(l > high || r < low) return INT_MAX; // no overlap
            else if(low >= l && r >= high) return seg[ind]; // complete overlap
            else{                                           // partial overlap
                int mid = low + (high-low)/2;
                int left = query(2*ind+1, low, mid, l, r);
                int right = query(2*ind+2, mid+1, high, l, r);
                return min(left, right);
            }
        }

        void update(int ind, int low, int high, int i, int value){    // point update
            if(low == high){
                seg[ind] = value;
                return;
            }
            int mid = low + (high-low)/2;
            if(i <= mid) update(2*ind+1, low, mid, i, value);
            else update(2*ind+2, mid+1, high, i, value);

            seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
        }  

        int arrayMin(){
            return seg[0];
        }
};

int main(){
    int n1, n2;
    cout<<"Enter the number of elements of the first and second array: "<<endl;
    cin>>n1>>n2;

    int arr1[n1], arr2[n2];
    cout<<"Enter the first array elements: "<<endl;
    for(int i=0; i<n1; i++){
        cin>>arr1[i];
    }

    cout<<"Enter the second array elements: "<<endl;
    for(int i=0; i<n2; i++){
        cin>>arr2[i];
    }

    SegmentMin s1(n1), s2(n2);
    s1.build(0, 0, n1-1, arr1);
    cout<<"First Segment Tree Build complete! "<<s1.arrayMin()<<endl;
    s2.build(0, 0, n2-1, arr2);    
    cout<<"Second Segment Tree Build complete! "<<s2.arrayMin()<<endl;

    int t; 
    cout<<"Enter the number of testcases: "<<endl;
    cin>>t;

    while(t--){
        int typeofQuery;
        cout<<"\nEnter the Query type: "<<endl;
        cin>>typeofQuery;
        if(typeofQuery == 1){
            int l1, r1, l2, r2;
            cout<<"Enter the first and second index of the first array: "<<endl;
            cin>>l1>>r1;
            cout<<"Enter the first and second index of the second array: "<<endl; 
            cin>>l2>>r2;
            int min1 = s1.query(0, 0, n1-1, l1, r1);
            int min2 = s2.query(0, 0, n2-1, l2, r2);
            cout<<"Minimum in the range "<<l1<<" to "<<r1<<" of the first array is: "<<min1<<" and in " 
            "the range "<<l2<<" to "<<r2<<" of the second array is: "<<min2<<"\nHence, the overall"
            " minimum of the two is: "<<min(min1, min2);
        }
        else if(typeofQuery == 2){
            int arrayNum, ind, val;
            cout<<"Enter the array, index and the value which you want to update: "<<endl;
            cin>>arrayNum>>ind>>val;
            if(arrayNum == 1){
                s1.update(0, 0, n1-1, ind, val);
                arr1[ind] = val;
            }
            else if(arrayNum == 2){
                s2.update(0, 0, n2-1, ind, val);
                arr2[ind] = val;
            }
        }
    }

    return 0;
}