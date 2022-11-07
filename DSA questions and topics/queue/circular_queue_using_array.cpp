#include<iostream>
using namespace std;

struct circularQue
{
    int front;
    int rear;
    int *arr;
    int size;

    circularQue(int x)
    {
        front = 0;  // In circular queue we initialize these values with 0 instead of -1 because otherwise our circular increment of rear will never be equal to -1 i.e. front and it will never be full. If we never remove anything and front stays on -1.
        rear = 0;
        size = x;
        arr = new int[size];
    }
};

bool isFull(circularQue *);

void enqueue(circularQue* q, int value)   
{
    if(isFull(q))
    {
        cout<<"Queue overflow.";
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = value;
        cout<<"Enqueing element: "<<value<<endl;
    }
}

bool isEmpty(circularQue *);

int dequeue(circularQue* q)
{
    if(isEmpty(q))
    {
        cout<<"Queue is empty.\n";
        return -1;
    }
    else
    {
        q->front = (q->front + 1) % q->size ;
        return q->arr[q->front];
    }
}



int firstVal(circularQue *q)
{
    if(isEmpty(q))
    {
        cout<<"Empty stack.";
        return -1;
    }
    else
    {
        int frontInd = (q->front + 1) % q->size;
        return q->arr[frontInd];
    }
}

int lastVal(circularQue *q)
{
    if(isEmpty(q))
    {
        cout<<"Empty stack.";
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

bool isEmpty(circularQue *q)
{
    return q->front == q->rear;
}

bool isFull(circularQue *q)
{
    return (q->rear + 1)%q->size == q->front;
}


int main()
{
    circularQue *q;
    q = new circularQue(4);
    // if(isEmpty(q))
    // {
    //     cout<<"Queue Is Empty"<<endl;
    // }
    // Enqueue few elements
    enqueue(q, 12);
    enqueue(q, 15);
    enqueue(q, 1);
    // enqueue(q, 1); // if we give size as 4 then we'll be able to put 3 elements as we have front and rear on 0 so rear will never go to 0, that's why when we enqueue this, it will give Queue overflow.
    cout<<"DeQueueing element: "<<dequeue(q)<<endl;
    cout<<"DeQueueing element: "<<dequeue(q)<<endl;
    cout<<"DeQueueing element: "<<dequeue(q)<<endl;
    // cout<<"DeQueueing element: "<<dequeue(q)<<endl;
    enqueue(q, 45);
    enqueue(q, 45);
    enqueue(q, 45);

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