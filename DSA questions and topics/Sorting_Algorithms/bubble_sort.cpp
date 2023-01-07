#include<iostream>
using namespace std;

// O(n^2)

// 1. Bubble Sort is Stable.
// 2. It is not adaptive but we can make it adaptive.

void printArray(int* A, int n)
{
    for(int i = 0; i<n; i++)
    {
    cout<<A[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int *A, int n) // this is Adaptive bubble sort.
{
    for(int i = 0; i<n-1; i++ ) // for number of passes
    {
        int count = 0;
        cout<<i+1<<" Pass Started"<<endl;
        for(int j =0; j<n-i-1; j++) // for comparison in each pass
        {
            if(A[j] > A[j+1])
            {
                count++;
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
        cout<<i+1<<" Pass Ended"<<endl;
        if(count == 0)
        {
            cout<<"Your array got sorted in "<<i+1<<" pass."<<endl;
            return;
        }
        cout<<"Array after "<<i+1<<" pass is: "<<endl;
        printArray(A, n);
    }
    return;
}

int main(){
    // int A[] = {12, 54, 65, 7, 23, 9};
    int A[] = {1, 2, 3, 4, 6, 5};
    int n = 6;
    printArray(A, n); // Printing the array before sorting.
    bubbleSort(A, n); // Function to sort the array
    printArray(A, n); // Printing the array after sorting.

    return 0;
}