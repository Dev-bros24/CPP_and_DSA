#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

// void printLinkedlist(node *head)
// {
//     head = head->next;  // Extra statement in case we pass pointer to head and declare every node as non-pointer
//     while (head != NULL)
//     {
//         cout << head->data;
//         head = head->next;
//         if(head!=NULL)
//         {
//             cout<<" -> ";
//         }
//     }
// }

void printLinkedlist(node head)
{
    node ptr = *(head.next);
    while (head.next != NULL)
    {
        cout << ptr.data;
        head.next = ptr.next;
        ptr = *(head.next);
        if(head.next!=NULL)
        {
            cout<<" -> ";
        }
    }
}

int main()
{
    node head;
    node first; 
    node second; 
    node third;

    // first = new node;
    // second = new node;  
    // third = new node;

    head.next = &first;

    first.data = 24;
    first.next = &second;

    second.data = 13;
    second.next = &third;

    third.data = 1998;
    third.next = NULL;

    // head = first;

    // first->data = 24;
    // first->next = second;

    // second->data = 13;
    // second->next = third;

    // third->data = 1998;
    // third->next = NULL;

    printLinkedlist(head);

    return 0;
}