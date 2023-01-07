#include<iostream>
using namespace std;

// Uses extra Space, but is O(n) time complexity Algorithm.

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void countSort(int* A, int n)
{
    int max = A[0];
    for(int i=0; i<n; i++)
    {
        if(max<A[i])
        {
            max = A[i];
        }
    }
    
    int B[max+1] = {0};
    for(int j=0; j<n; j++)
    {
        B[A[j]]++;
    }

    int p = 0, i = 0;
    while(i<=max)
    {
        if(B[i] != 0)
        {
            A[p] = i;
            p++;
            B[i]--;
        }
        else
        {
            i++;
        }
    }
}

int main(){
    int A[] = {12, 54, 65, 7, 23, 9, 4, 5};
    int n = 8;
    printArray(A, n);
    countSort(A, n);
    printArray(A, n);
    return 0;
}