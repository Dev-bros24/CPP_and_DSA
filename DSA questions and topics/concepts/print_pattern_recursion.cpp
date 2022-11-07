#include<iostream>
using namespace std;

/*
1 2 3 4 5
1 2 3 4 
1 2 3
1 2
1
1 2
1 2 3
1 2 3 4 5
*/

void print_pattern(int n)
{
    if(n == 1)
    {
        cout<<n<<endl;
        return;
    }
    for(int i=1; i<=n; i++)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    print_pattern(n-1);

    for(int i=1; i<=n; i++)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}


int main(){
    print_pattern(6);
    return 0;
}