/*
Heap is a CBT(Complete Binary Tree) that comes with a 
heap order property.

Heap order property --> Maxheap, Minheap

Maxheap 
In the CBT, every child will have a value smaller than or equal to it's parent.

Minheap
In the CBT, every child will have a value greater than or equal to it's parent.
*/

/*
IN CASE OF 1 based indexing
If the node is at the i th index then the left child will be at (2*i)th index and right
child will be at (2*i)+1 th index. Parent will be at (i/2) index.

IN CASE OF 0 based indexing
If the node is at the i th index then the left child will be at (2*i)+1th index and right
child will be at (2*i)+2th index. Parent will be at ((i-1)/2) index.

*/

/*
INSERTION IN HEAP
1. Insert at the end
2. Take it to it's correct position
    a. Just compare the element with it's parent and if the value of the parent node
        is smaller then swap the values as it's a max heap.

TC --> O(logn)
*/

/*
DELETION IN HEAP
1. Place the last node's value at the root node.
2. Remove last node.
3. Take root node to it's correct position.

TC --> O(logn)
*/

/*
Because of the nature of the heapsort algorithm, the heap array that we get after sort
of maxheap is ascending and after sorting of minheap is descending.
*/

#include<bits/stdc++.h>
using namespace std;

class Heap{
    int arr[100];
    int size;

    public:
        Heap()
        {
            size = 0;
            arr[0] = -1; // We'll use the array from 1st index
        }

    void insert(int val)
    {   
        size++;
        int index = size;
        arr[index] = val;

        while(index > 1)
        {
            int parent = index/2;

            if(arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }
    void print()
    {
        for(int i=1; i<=size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void delete_from_Heap()
    {
        if(size == 0)
        {
            cout<<"Nothing to delete."<<endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1; // root node is at 1 index
        while(i < size)
        {
            int leftIndex = 2*i;
            int rightIndex = (2*i) + 1;

            if(leftIndex < size && arr[leftIndex] > arr[i])
            {
                swap(arr[leftIndex], arr[i]);
                i = leftIndex;
            }
            else if(rightIndex < size && arr[rightIndex] > arr[i])
            {
                swap (arr[rightIndex], arr[i]);
                i = rightIndex;
            }
            else{
                return;
            }
        }
    }
};


void heapify(int arr[], int n, int i) // TC of this function O(logn)
{
    int largest = i;

    int left = i*2;
    int right = i*2 +1;

    if(left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) // Because of this heapsort algo, minheap's sort gives descending sort and maxheap gives ascending sort and that's why we have to invert the conditions in comparator while declaring priority queue's comparator.
{
    int size = n;

    while(size > 1)
    {
        swap(arr[1], arr[size]);
        size--;

        heapify(arr, size, 1);
    }
}

int main()
{
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.delete_from_Heap();
    h.print();

    // Heapify algo

    int a[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    
    // heap creation
    for(int i=n/2; i>0; i--)  // This building the heap from the array has TC --> O(n)
    {
        heapify(a, n, i);
    }

    cout<<"Printing the array now: "<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<a[i]<<" ";
    }

    // heapsort
    heapSort(a, n);
    cout<<"\nPrinting the array now after sorting: "<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<a[i]<<" ";
    }

    // // Priority Queue
    // cout<<"\nUsing priority Queue here: "<<endl;

    // // maxheap by default
    // priority_queue<int> pq;
    // pq.push(4);
    // pq.push(2);
    // pq.push(5);
    // pq.push(3);
    // pq.push(9);
    

    // cout<<"Element at top: "<<pq.top()<<endl;
    // pq.pop();
    // cout<<"Element at top: "<<pq.top()<<endl;

    // //minheap
    // priority_queue<int, vector<int>, greater<int>> minheap;
    // minheap.push(4);
    // minheap.push(2);
    // minheap.push(2);
    // minheap.push(5);
    // minheap.push(3);
    // cout<<"\nElement at top: "<<minheap.top()<<endl;
    // minheap.pop();
    // cout<<"Element at top: "<<minheap.top()<<endl;
    // minheap.pop();
    // cout<<"Element at top: "<<minheap.top()<<endl;

    return 0;
}

