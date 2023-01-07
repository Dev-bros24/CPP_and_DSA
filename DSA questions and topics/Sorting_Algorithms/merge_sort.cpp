#include<iostream>
using namespace std;

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int merge(int A[], int l, int mid, int h)
{
    int i, j, k;
    i = l, j = mid+1, k = l;
    int B[h+1];
    // int B[h-l+1];
    // cout<<"Abhishek"<<endl;
    while(i<=mid && j<=h)
    {
        if(A[i] <= A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        if(A[i] > A[j])
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while(j<=h)
    {
        B[k] = A[j];
        j++;
        k++;
    }
    for(int i = l; i<=h; i++)
    {
        A[i] = B[i];
    }
}

void mergeSort(int A[], int l, int h)
{
    if(l<h)
    {
        int m = (l+h)/2;
        mergeSort(A, l, m);
        mergeSort(A, m+1, h);
        merge(A, l, m, h);
    }
}

int main()
{
    int A[] = {12, 54, 65, 7, 23, 9, 4, 5};
    int n = 8;
    int low = 0;
    int high = n-1;
    printArray(A, n);
    mergeSort(A, low, high);
    printArray(A, n);

    return 0;
}