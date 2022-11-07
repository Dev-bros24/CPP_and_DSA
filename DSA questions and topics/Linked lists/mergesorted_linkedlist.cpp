#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr) {}
};

// ListNode* insertAtTail(ListNode *head, int value)
// {
//     ListNode *dummy = new ListNode;
//     dummy -> val = value;
//     if(head == NULL)
//     {
//         return dummy;
//     }
//     ListNode *node = head;
//     while(node->next != NULL)
//     {
//         node = node -> next;
//     }
//     node -> next = dummy;
//     return head;
// }

void insertAtHead(ListNode* &head, int value)
{
    ListNode *dummy = new ListNode(value);
    dummy -> next = head;
    head = dummy;
}

void insertAtTail(ListNode* &head, int value) // Head(actual argument calling ke time waala) jisko point kar raha tha wo nahi change hoga agar humne & nahi lagaya to. Wo null ko kar raha hai to wahin karega. SIMPLE
{
    ListNode *dummy = new ListNode;
    dummy -> val = value;
    if(head == NULL)
    {
        head = dummy;
        return;
    }
    ListNode *node = head;
    while(node->next != NULL)
    {
        node = node -> next;
    }
    node -> next = dummy;
    return;
}

void display(ListNode *node)
{
    cout<<endl;
    while(node != NULL)
    {
        cout<< node -> val<<" -> ";
        node = node -> next;
    }
    cout<<"NULL";
}

ListNode* mergeRecursive(ListNode* head1, ListNode* head2)
{
    if(head1 == NULL)
    {
        return head2;
    }
    if(head2 == NULL)
    {
        return head1;
    }

    ListNode *result;
    if(head1 -> val < head2 -> val)
    {
        result = head1;
        result -> next = mergeRecursive(head1 -> next, head2);
    }
    else
    {
        result = head2;
        result -> next = mergeRecursive(head1, head2 -> next);
    }
    return result;
}


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode *ptr1 = list1, *ptr2 = list2;
        ListNode *dummy = new ListNode(-1);
        ListNode *ptr3 = dummy;
        
        while(ptr1 != NULL && ptr2 != NULL)
        {
            if(ptr1-> val <= ptr2 -> val)
            {
                ptr3 -> next = ptr1;
                ptr1 = ptr1 -> next;
            }
            else
            {
                ptr3 -> next = ptr2;
                ptr2 = ptr2 -> next;
            }
            ptr3 = ptr3->next;
        }
        while(ptr1 != NULL)
        {
            ptr3 -> next = ptr1;
            ptr1 = ptr1 -> next;
            ptr3 = ptr3->next;
        }
        while(ptr2 != NULL)
        {
            ptr3 -> next = ptr2;
            ptr2 = ptr2 -> next;
            ptr3 = ptr3->next;
        }
        // list1 = dummy->next->next->next;
        return dummy->next;
    }

ListNode* mergeinnew(ListNode* head1, ListNode* head2)
{
    ListNode *ptr1 = head1, *ptr2 = head2;

    ListNode *dummy = new ListNode;
    ListNode *head3 = dummy;

    while(ptr1 != NULL && ptr2 != NULL)
    {
        if(ptr1 -> val <= ptr2-> val)
        {
            ListNode *temp = new ListNode;
            temp -> val = ptr1 -> val;
            dummy -> next = temp;
            ptr1 = ptr1 -> next;
        }
        else
        {
            ListNode *temp = new ListNode;
            temp -> val = ptr2 -> val;
            dummy -> next = temp;
            ptr2 = ptr2 -> next;
        }
        dummy = dummy -> next;
    }
    while ( ptr1 != NULL)
    {
        ListNode *temp = new ListNode;
        temp -> val = ptr1 -> val;
        dummy -> next = temp;
        ptr1 = ptr1 -> next;
        dummy = dummy -> next;
    }
    while ( ptr1 != NULL)
    {
        ListNode *temp = new ListNode;
        temp -> val = ptr2 -> val;
        dummy -> next = temp;
        ptr2 = ptr2 -> next;
        dummy = dummy -> next;
    }
    return head3 -> next;
}

int main(){
    ListNode *head1= NULL, *head2 =NULL, *head3 = NULL;
    int arr1[] = {1,4,5,7};
    int arr2[] = {2,3,6};
    for(int i=0; i<4; i++)
    {
       insertAtTail(head1, arr1[i]);
    }
    for(int i=0; i<3; i++)
    {
       insertAtTail(head2, arr2[i]);
    }
    display(head1);
    display(head2);
    // ListNode *head3 = mergeTwoLists(head1, head2);
    // ListNode *head3 = mergeRecursive(head1, head2);
    head3 = mergeinnew(head1, head2);
    display(head3);
    display(head1);
    display(head2);
    return 0;
}