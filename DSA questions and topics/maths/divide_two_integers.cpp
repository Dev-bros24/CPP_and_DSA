#include<iostream>
#include<climits>
using namespace std;

int divide(int dividend, int divisor) {
        
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        // if(dividend == INT_MIN && divisor == 1) return INT_MIN;

        long res = 0;  // we can remove this and use the commented lines
        // int res = 0;
        long long dd = dividend, dr = divisor;
        dd = abs(dd);
        dr = abs(dr);
        
        while(dd >= dr){
            int sc = 0; // shift_count
            while((dr<<sc<<1) <= dd){
                sc++;
            }
            // cout<<"Abhishek sc: "<<sc<<" dd: "<<dd<<" dr: "<<dr<<endl;
            dd = dd - (dr<<sc);
            res = res + (1<<sc);
        }

        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0)) return -res;
        else return res;
    }


int main(){
    // int dividend = 66, divisor = 3;
    int dividend = -2147483648, divisor = 2;

    int ans = divide(dividend, divisor);
    cout<<"Answer: "<<ans<<endl;

    return 0;
}