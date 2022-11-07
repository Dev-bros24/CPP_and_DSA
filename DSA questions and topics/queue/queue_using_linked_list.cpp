#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
    Node() : data(0), next(nullptr) {}
};

void printLinkedlist(Node *head)
{
    cout<<"Printing the elements of this Linked List"<<endl;
    while (head != NULL)
    {
        cout << head->data;
        head = head->next;
        if(head!=NULL)
        {
            cout<<" -> ";
        }
    }
}

bool isFull()
{
    // Node *n = new (std::nothrow) Node;
    Node *n = new Node;
    if(n == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmpty(Node *front)
{
    return front == NULL;
}

void enQueue(Node * &front, Node * &rear, int value)
{
    if(isFull())
    {
        cout << "Queue overflow. No memory remaining." << endl;
    }
    else
    {
        Node *newnode = new Node;
        newnode->data = value;
        newnode->next = NULL;
        if (front == NULL)
        {
            front = rear = newnode;
        }
        else
        {
            rear -> next = newnode;
            rear = newnode;
        }
    }
}

int deQueue(Node * &front, Node * &rear)
{
    int val = -1;
    if (isEmpty(front))
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        val = front->data;
        Node *tmp = front;
        if (front->next == NULL)
        {
            front = front->next;
            rear = rear->next;
        }
        else
        {
            front = front->next;
        }
        delete (tmp);
    }
    return val;
}

int main()
{
    Node *front = NULL, *rear = NULL;
    // front = new Node(7);
    // cout<<front -> data;
    printLinkedlist(front);
    cout<<"DeQueuing element : "<<deQueue(front, rear)<<endl;
    enQueue(front, rear, 123);
    enQueue(front, rear, 13);
    enQueue(front, rear, 34);
    enQueue(front, rear, 17);
    printLinkedlist(front);
    cout<<endl;
    cout<<"DeQueuing element : "<<deQueue(front, rear)<<endl;
    cout<<"DeQueuing element : "<<deQueue(front, rear)<<endl;
    cout<<"DeQueuing element : "<<deQueue(front, rear)<<endl;
    cout<<"DeQueuing element : "<<deQueue(front, rear)<<endl;
    printLinkedlist(front);

    return 0;
}