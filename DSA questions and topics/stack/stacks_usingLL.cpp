#include<iostream>
using namespace std;

// Push, pop, peek, isEmpty, isFull, stackTop, stackBottom

struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL){}
    Node() : data(0), next(NULL){}
};

int push(Node* &top, int value)
{
    Node *newnode = new Node(value);
    if(newnode == NULL)
    {
        cout<<"Stack overflow."<<endl;
    }
    else
    {
        newnode -> next = top;
        top = newnode; 
    }
}

int pop(Node* &top)
{
    if(top == NULL)
    {
        cout<<"Stack is empty.";
        return -1;
    }
    else
    {
        Node *node = top;
        int val = node -> data;
        top = top -> next;
        delete(node);
        return val; 
    }  
}

int peek(Node *top, int pos)
{
    Node *ptr = top;
    if(top == NULL)
    {
        cout<<"Stack is empty."<<endl;
        return -1;
    }
    else
    {
        pos--;
        while(pos-- && ptr != NULL)
        {
            ptr = ptr -> next;
        }
        if(ptr == NULL)
        {
            cout<<"Invalid position."<<endl;
            return -1;
        }
        return ptr -> data;
    }
}

bool isEmpty(Node *top)
{
    return top == NULL;
}

bool isFull()  // This simply means there is no more memory in Heap for allocating.
{
    Node *newnode = new Node;
    if(newnode == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int stackTop(Node *top)
{
    if(top == NULL)
    {
        cout<<"Stack is empty.";
    }
    else
    {
        return top -> data;
    }
}

int stackBottom(Node *top)
{
    if(top == NULL)
    {
        cout<<"Stack is empty.";
        return -1;
    }
    else
    {
        while(top -> next != NULL)
        {
            top = top -> next;
        }
        return top -> data;
    }
}

void printStack(Node *top)
{
    while(top != NULL)
    {
        cout<<top -> data<<endl;
        top = top -> next;
    }
}

int main(){
    Node *top = NULL;
    push(top, 4);
    push(top, 5);
    push(top, 16);
    push(top, 8);
    push(top, 9);
    push(top, 6);
    cout<<stackTop(top)<<endl;
    cout<<"The popped element is: "<<pop(top)<<endl;
    cout<<stackTop(top)<<endl;
    cout<<"Empty or not output: "<<isEmpty(top)<<endl;
    cout<<"Value at 4th position is: "<<peek(top, 9)<<endl;
    cout<<"Top value in the stack: "<<stackTop(top)<<endl;
    // printStack(top);
    cout<<"Bottom value in the stack: "<<stackBottom(top)<<endl;
    cout<<"Output of is full: "<<isFull()<<endl;

    return 0;
}