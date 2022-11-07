#include <iostream>
using namespace std;

/*
QuickSort is not stable.
It is not adaptive, instead it works worst in case of sorted array.
Average case time complexity is O(nlog(n))
*/

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int partition(int *A, int low, int high)
{
    int pivot = A[low], i = low + 1, j = high;
    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    int temp = A[j];
    A[j] = A[low];
    A[low] = temp;

    return j;
}

void quickSort(int *A, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(A, low, high);
        printArray(A, 8);
        quickSort(A, low, partitionIndex - 1);
        quickSort(A, partitionIndex + 1, high);
    }
}

int main()
{
    int A[] = {12, 54, 65, 7, 23, 9, 4, 5};
    int n = 8;
    int l = 0, h = n - 1;
    printArray(A, n);
    quickSort(A, l, h);
    printArray(A, n);

    return 0;
}