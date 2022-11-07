#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
        int arr[1000000];
        int size;      
        
        MedianFinder()
        {
            size = 0;
            arr[0] = -1;
        }
    
    void addNum(int num) {
        size++;
        int index = size;
        arr[index] = num;

        while(index > 1)
        {
            int parent = index/2;

            if(arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                // cout<<"not needed."<<endl;
                return;
            }
        }
    }
    
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
    
    double findMedian() {
        cout<<"Non Sorted: "<<endl;
        for(int i=1; i<=size; i++)
        {
            cout<<arr[i]<<" ";
        }
        heapSort(arr, size);
        cout<<"\nSorted : "<<endl;
        for(int i=1; i<=size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\nSize: "<<size<<endl;
        double med_ans;
        int ind = size/2;
        
        if(size % 2 == 0)
        {
            med_ans = ((double)arr[ind] + (double)arr[ind+1])/2;
        }
        else{
            med_ans = (double)arr[ind+1];
        }
        return med_ans;
    }
};

int main()
{
    cout<<"Start of program execution "<<endl;
    MedianFinder *obj = new MedianFinder();   // It's not working with normal object creation
    // MedianFinder obj;
    cout<<"Abhi: "<<endl;
    obj->addNum(-1);
    cout<<"Median: "<<obj->findMedian()<<endl;
    obj->addNum(-2);
    cout<<"Median: "<<obj->findMedian()<<endl;
    obj->addNum(-3);
    cout<<"Median: "<<obj->findMedian()<<endl;
    obj->addNum(-4);
    cout<<"Median: "<<obj->findMedian()<<endl;
    obj->addNum(-5);
    cout<<"Median: "<<obj->findMedian()<<endl;
    return 0;
}