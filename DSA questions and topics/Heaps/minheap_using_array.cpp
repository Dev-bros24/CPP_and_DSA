#include<bits/stdc++.h>
using namespace std;

class Minheap{
    int arr[100];
    int size;

    public:
    Minheap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size++;
        int index = size;
        arr[index] = val;

        while(index>1)
        {
            int parent = index/2;
            if(arr[parent] > arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void delete_from_Heap()
    {

        if(size == 0)
        {
            cout<<"Nothing to delete."<<endl;
        }
        
        cout<<"Removing element: "<<arr[1]<<endl;
        arr[1] = arr[size];
        size--;

        int smallestindex = 1;

        while(smallestindex <= size)
        {
            int leftIndex = (2*smallestindex);
            int rightIndex = (2*smallestindex)+1;

            if(leftIndex<=size && arr[leftIndex] < arr[smallestindex])
            {
                swap(arr[smallestindex], arr[leftIndex]);
                smallestindex = leftIndex;
            }
            else if(rightIndex<=size && arr[rightIndex] < arr[smallestindex])
            {
                swap(arr[smallestindex], arr[rightIndex]);
                smallestindex = rightIndex;
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
    }
};

void heapify(int arr[], int n, int i)    // heapify inserts one index at its correct position
{
    int smallest = i;
    int left = 2*i;
    int right = 2*i + 1;
    int size = n;

    if(left <= size && arr[left] < arr[smallest])
    {
        smallest = left;
    }
    if(right <= size && arr[right] < arr[smallest])
    {
        smallest = right;
    }

    if(smallest != i)
    {
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }
}

void heapsort(int arr[], int n)   // O(nlogn)
{
    int size = n;
    while(size>1)
    {
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }
}

int main(){
    
    // Minheap minh;
    // minh.insert(54);
    // minh.insert(74);
    // minh.insert(56);
    // minh.insert(68);
    // minh.insert(15);

    // cout<<"Printing the Minheap: "<<endl;
    // minh.print();

    // cout<<"\nDeleting from heap"<<endl;
    // minh.delete_from_Heap(); // deletes the value the top .. this is pop operation

    // cout<<"Printing the Minheap: "<<endl;
    // minh.print();


    int a[6] = {-1, 89, 34, 23, 76, 35};
    int n = 5;

    // building minheap from the above array
    for(int i=n/2; i>0; i--)  //O(n)
    {
        heapify(a, n, i);  // O(log(n))
    }

    cout<<"Printing the array"<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    heapsort(a, n);
    cout<<"Array after sorting: "<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}