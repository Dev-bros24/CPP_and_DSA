#include<iostream>
using namespace std;

// O(n^2)

// 1. Selection Sort is not Stable.
// 2. It is not Adaptive.
// 3. Minimum no of swaps required. 

void printArray(int* A, int n)
{
    for(int i = 0; i<n; i++)
    {
    cout<<A[i]<<" ";
    }
    cout<<endl;
}

void selectionSort(int *A, int n)
{
    cout<<"Running selection sort...\n";
    int min = 0, ind = 0;
    for(int i = 0; i<n-1; i++)
    {
        min = A[i];
        for(int j=i+1; j<n; j++)
        {
            if(A[j] < min)
            {
                min = A[j];
                ind = j;
            }
        }
        int temp = A[ind];
        A[ind] = A[i];
        A[i] = temp;
    }
}

int main(){
    int A[] = {12, 54, 65, 7, 23, 9};
    int n=6;
    printArray(A, n);
    selectionSort(A ,n);
    printArray(A, n);

    return 0;
}