#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void printLinkedlist(node *head)
{
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


int countNodes(node* head)
{
	static int count = 0;
	if(!head) return count;
	count++;
	countNodes(head->next);
}

int main()
{
    node *head;
    node *first = NULL; // We create a pointer here as we want the memory to be dynamically allocated in heap because then if we want it to be used and released inside one function itself then also we can do it. Because a function's stack(as the static memory gets allocated in stacks) gets destroyed after the function returns value not before that.
    node *second = NULL; // Dynamic memory allocation is done using pointers.
    node *third = NULL;

    // first = (node *)malloc(sizeof(node));
    // second = (node *)malloc(sizeof(node));
    // third = (node *)malloc(sizeof(node));

    first = new node;
    second = new node;  // Here we don't write node* as it already returns the address of the data type i.e. node here.
    third = new node;

    head = first;

    first->data = 24;
    // cout<<"First data -> "<<first->data;
    first->next = second;

    second->data = 13;
    second->next = third;

    third->data = 1998;
    third->next = NULL;

    printLinkedlist(head);

    cout<<"\nNodes: "<<countNodes(head);

    delete (first);

    return 0;
}