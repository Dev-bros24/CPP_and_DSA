#include<iostream>
using namespace std; 


void linearsearch(int arr[], int &count, int target, int size)
{
    // cout<<"inside function"<<endl;
    for(int i=0 ; i<size; i++)
    {
        // cout<<sizeof(arr);
        count++;
        if(arr[i] == target)
        {
            cout<<"\nElement "<<target<<" in linear search found at position "<<i+1;
            return;
        }
    } 
    cout<<"\nElement not found in linear search.";
}

void binarySearch_iterative(int arr[], int &count, int target, int size)
{
    int low = 0, high = size - 1, mid = 0;
    while(low<=high)
    {
        count++;
        mid = (low + high)/2;
        if(target == arr[mid])
        {
            cout<<"\nThe element "<<target<<" in binary search iterative found at position "<<mid+1;
            return;
        }
        if(target>arr[mid])
        {
            low = mid+1;
        }
        if(target<arr[mid])
        {
            high = mid-1;
        }
    }
    cout<<"\nElement not found in Binary iterative search.";
    return;
}

void binarySearch_recursive(int arr[], int &count, int target, int low, int high)
{
    int mid = (low+high)/2;
    count++;
    if(low>high)
    {
        cout<<"\nElement not found in Binary recursive search."<<endl;
        return;
    }
    if(arr[mid] == target)
    {
        cout<<"\nThe element "<<target<<" in binary search recursive found at position "<<mid+1;
        return;
    }
    else if(arr[mid]<target)
    {
        binarySearch_recursive(arr, count, target, mid+1, high);
    }
    else
    {
        binarySearch_recursive(arr, count, target, low, mid-1);
    }
}

int main(){
    int n, count = 0, count_bi = 0, count_bir = 0;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0; i<n ; i++)
    {
        cin>>a[i];
    }
    cout<<"Your array is"<<endl;
    for(int j=0; j<n; j++)
    {
        cout<<a[j]<<" ";
    }
    int target;
    cout<<"\nEnter the target element"<<endl;
    cin>>target;

    linearsearch(a, count, target, n);
    binarySearch_iterative(a, count_bi, target, n);
    binarySearch_recursive(a, count_bir, target, 0, n-1);

    cout<<"\nThe count of iterations in linear search are: "<<count;
    cout<<"\nThe count of iterations in binary search iterative are: "<<count_bi;
    cout<<"\nThe count of function calls in binary search recursive are: "<<count_bir;

    return 0;
}