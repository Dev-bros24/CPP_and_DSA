#include <iostream>
using namespace std;


int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    int arr[n];
    int *ptr = new int[n];

    for (int i = 0; i <= n + 6; i++)  // if we're going till 6 extra elements than size i.e. i<=i+5 ... it's working fine.
    {
        cout<<"ABhi1"<<" i "<<i<<endl;
        cin >> arr[i];
        cout<<"ABhi2"<<" i "<<i<<endl;
        cin >> ptr[i];
    }
    cout << "Your first array is the one below" << endl;
    for (int i = 0; i <= n + 6; i++)
    {
        cout << " " << arr[i] << " address  " << &arr[i];
    }
    cout << "\nYour second array is the one below" << endl;
    for (int i = 0; i <= n + 6; i++)
    {
        cout << " " << ptr[i] << " address  " << &ptr[i];
    }

    return 0;
}