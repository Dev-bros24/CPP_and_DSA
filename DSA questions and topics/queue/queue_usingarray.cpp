#include<iostream>
using namespace std;

struct que
{
    int front;
    int rear;
    int *arr;
    int size;

    que(int x)
    {
        front = -1;
        rear = -1;
        size = x;
        arr = new int[size];
    }
};

void enqueue(que* q, int value)   // if we write que* &s then the memory where this pointer in the actual argument is pointing will not change if we change here. But since we are accessing the elements at the memory location pointed by this pointer here and not changing where this que pointer is pointing we don't need this & referencing.
{
    if(q->rear == q->size-1)
    {
        cout<<"Queue overflow."<<endl;
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = value;
        cout<<"Enqueing element: "<<value<<endl;
    }
}

int dequeue(que* q)
{
    if(q->front == q->rear)
    {
        cout<<"Queue is empty."<<endl;
        return -1;
    }
    else
    {
        q->front++;
        return q->arr[q->front];
    }
}

bool isEmpty(que *);

int firstVal(que *q)
{
    if(isEmpty(q))
    {
        cout<<"Empty Queue.";
        return -1;
    }
    else
    {
        return q->arr[q->front + 1];
    }
}

int lastVal(que *q)
{
    if(isEmpty(q))
    {
        cout<<"Empty Queue.";
        return -1;
    }
    else
    {
        return q->arr[q->rear];
    }
}

// int peek(que *q, int pos)
// {

// }

bool isEmpty(que *q)
{
    return q->front == q->rear;
}

bool isFull(que *q)
{
    return q->rear == q->size-1;
}

int main(){
    que *q;
    q = new que(4);
    // if(isEmpty(q))
    // {
    //     cout<<"Queue Is Empty"<<endl;
    // }
    // Enqueue few elements
    enqueue(q, 12);
    enqueue(q, 15);
    enqueue(q, 1);
    enqueue(q, 1);
    cout<<"DeQueueing element: "<<dequeue(q)<<endl;
    cout<<"DeQueueing element: "<<dequeue(q)<<endl;
    cout<<"DeQueueing element: "<<dequeue(q)<<endl;
    cout<<"DeQueueing element: "<<dequeue(q)<<endl;
    enqueue(q, 1);
    enqueue(q, 1);
    enqueue(q, 1);

    if(isEmpty(q))
    {
        cout<<"Queue Is Empty"<<endl;
    }

    if(isFull(q))
    {
        cout<<"Queue Is Full"<<endl;
    }

    return 0;
}