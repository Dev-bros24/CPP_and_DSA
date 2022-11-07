#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node() : data(0), left(nullptr), right(nullptr){}
};

Node* createNode(int value)
{
    Node* newnode = new Node;
    newnode -> data = value;
    newnode -> left = NULL;
    newnode -> right = NULL;    
    return newnode;
}

void inOrder(Node* root)
{
    Node* ptr = root;
    if(ptr != NULL)
    {
        inOrder(ptr->left);
        cout<<ptr->data<<" ";
        inOrder(ptr->right);
    }
    // if(ptr -> left != NULL && ptr -> right != NULL)
    // {
    //     inOrder(ptr->left);
    //     cout<<ptr->data<<" ";
    //     inOrder(ptr->right);
    // }
    // else if(ptr->left != NULL)
    // {
    //     inOrder(ptr->left);
    //     cout<<ptr->data<<" ";
    // }
    // else if(ptr->right != NULL)
    // {
    //     cout<<ptr->data<<" ";
    //     inOrder(ptr->right);
    // }
    // else
    // {
    //     cout<<ptr->data<<" ";
    //     return;
    // }
}

int main(){
    Node* p = createNode(7);
    Node* p1 = createNode(2);
    Node* p2 = createNode(3);
    p->left = p1;
    p->right = p2;
    Node* p4 = createNode(1);
    Node* p5 = createNode(4);
    p1->left = p4;
    p2->right = p5;

    inOrder(p);

    return 0;
}