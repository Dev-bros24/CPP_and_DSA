#include<iostream>
using namespace std;

// TC ~ O(n) and SC is O(1).

int XOR(int a[], int n)
{
    int value = 0;

    for(int i=0; i<n; i++)
    {
        value = value ^ a[i];
    }

    return value;
}

int last_set_bit(int value) // set bit means that in one it was set and in other not.
{
    int count = 0;

    while(value)
    {
        if(value & 1)
        break;

        count++;
        value = value>>1;
    }
    return count;
}

void values(int a[], int size,  int index,  int &num1, int &num2)
{
    for(int i=0; i<size; i++)
    {
        if( a[i] & 1<<index )
        {
            num1 = num1 ^ a[i];
        }
        else{
            num2 = num2 ^ a[i];
        }
    }
}

int main(){
    int a[12] = {32, 67, 13, 32, 67, 11, 13, 15, 78, 15, 9, 9}; // 11, 78
    int n = 12;

    int ans1 = 0, ans2 = 0;

    values(a, n, last_set_bit(XOR(a, n)), ans1, ans2);

    cout<<"The only two non-repeating numbers are: "<<ans1<<" and "<<ans2<<endl;

    return 0;
}