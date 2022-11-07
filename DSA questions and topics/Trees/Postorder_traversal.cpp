#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
};

Node *createNode(int value)
{
    Node *newnode = new Node;
    newnode->data = value;
    newnode -> left = NULL;
    newnode -> right = NULL;    
    return newnode;
}

void postOrder(Node *root)
{
    Node *ptr = root;
    if(ptr != NULL)
    {    
        postOrder(ptr->left);
        postOrder(ptr->right);
        cout << ptr->data << " ";
    }
    // if (ptr->left != NULL && ptr->right != NULL)
    // {
    //     postOrder(ptr->left);
    //     postOrder(ptr->right);
    //     cout << ptr->data << " ";
    // }
    // else if (ptr->left != NULL)
    // {
    //     postOrder(ptr->left);
    //     cout << ptr->data << " ";
    // }
    // else if (ptr->right != NULL)
    // {
    //     postOrder(ptr->right);
    //     cout << ptr->data << " ";
    // }
    // else
    // {
    //     cout << ptr->data << " ";
    //     return;
    // }
}

int main()
{
    Node *p = createNode(7);
    Node *p1 = createNode(2);
    Node *p2 = createNode(3);
    p->left = p1;
    p->right = p2;
    Node *p4 = createNode(1);
    Node *p5 = createNode(4);
    p1->left = p4;
    p2->right = p5;

    postOrder(p);

    return 0;
}