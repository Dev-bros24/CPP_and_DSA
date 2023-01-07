#include<iostream>
using namespace std;

int countset(int n) // O(no. of bits)
{
    int count = 0;
    while(n != 0)
    {
        if(n & 1 == 1)
        {
            count++;
        }
        n = n>>1;
    }
    return count;
}

int optimum(int n) // O(no. of set bits)
{
    int count = 0;
    while(n != 0)
    {
        n = n & (n-1);
        count++;
    }
    return count;
}


int setBits(int num){
    int count = 0;
    int size = sizeof(num);
    for(int i=0; i<size*8; i++){
        if(1<<i & num) count++;
    }
    return count;
}

int main(){
    int n;

    cout<<"Enter the number: "<<endl;
    cin>>n;

    int ans = countset(n);
    int ansop = optimum(n);

    cout<<"Answer: "<<ans<<" optimum answer: "<<ansop<<endl;

    return 0;
}