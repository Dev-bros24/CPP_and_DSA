#include<iostream>
#include<climits>
using namespace std;

void printArray(int a[], int size){
    for(int i=0; i<size; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

// Bubble Sort
void bubbleSort(int a[], int n){
    cout<<"Bubble sort called: "<<endl;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

// Insertion Sort
void insertionSort(int a[], int n){
    cout<<"Insertion Sort called: "<<endl;
    for(int i=1; i<n; i++){
        int key = a[i];
        int j = i-1;
        while(j>=0 && key<a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

// Selection Sort
void selectionSort(int a[], int n){
    cout<<"Selection Sort called: "<<endl;
    for(int i=0; i<n-1; i++){
        int min_ind = i;
        int j = i+1;
        while(j<n){
            if(a[j]<a[min_ind]) min_ind = j;
            j++;
        }
        int temp = a[i];
        a[i] = a[min_ind];
        a[min_ind] = temp;
    }
}

// Count Sort
void countSort(int a[], int n){
    cout<<"Count Sort called: "<<endl;
    int max = INT_MIN;

    for(int i=0; i<n; i++){
        if(a[i]>max) max = a[i];
    }

    int b[max+1] = {0};
    for(int i=0; i<n; i++){
        b[a[i]]++;
    }

    int p = 0;
    for(int i=0; i<=max; i++){
        int num = b[i];
        while(num){
            a[p++] = i;
            num--;
        }
    }
}

// Merge Sort
void mergeAlgo(int a[], int low, int mid, int high){
    int b[high+1];
    int i = low;
    int j = mid+1;
    int k = low;

    while(i<=mid && j<=high){
        if(a[i]<a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    }
    while(i<=mid) b[k++] = a[i++];
    while(j<=high) b[k++] = a[j++];

    for(int i=low; i<=high; i++){
        a[i] = b[i];
    }
}

void mergeSort(int a[], int low, int high){
    static int count = 1;
    if(count == 1) cout<<"Merge Sort called: "<<endl;
    count++;
    
    if(low<high){
        int mid = low + (high-low)/2;

        mergeSort(a, low, mid);
        mergeSort(a, mid+1, high);
        mergeAlgo(a, low, mid, high);
    }
    return;
}

// Quick Sort
int partition(int a[], int low, int high){
    int pivot = a[low];
    int i = low+1, j = high;

    while(i<=j){
        while(i<=high && a[i]<=pivot) i++;
        while(a[j]>pivot) j--;
        if(i<j){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void quickSort(int a[], int low, int high){
    static int count = 1;
    if(count == 1) cout<<"Quick Sort called: "<<endl;
    count++;

    if(low<high){
        int partition_index = partition(a, low, high);

        quickSort(a, low, partition_index-1);
        quickSort(a, partition_index+1, high);
    }
    return;
}

int main(){
    int a[] = {5, 4, 3};
    int n = 3;
    // int a[] = {3, 56, 35};
    // int n = 3;
    // int a[] = {3, 56, 35, 43, 2};
    // int n = 5;
    // int a[] = {3, 56, 35, 43, 2, 56, 56, 34, 35, 43, 2, 1};
    // int n = 12;
    int low = 0, high = n-1;

    printArray(a, n);
    // bubbleSort(a, n);
    // insertionSort(a, n);
    // selectionSort(a, n);
    // countSort(a, n);
    // mergeSort(a, low, high);
    // quickSort(a, low, high);
    printArray(a, n);

    return 0;
}