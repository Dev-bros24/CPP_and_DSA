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
}

Node* inorderPredecessor(Node* node)
{
    node = node -> left;
    // if(node == NULL)
    // {
    //     return NULL;
    // }
    // else
    // {
        while(node -> right != NULL)
        {
            node = node -> right;
        }
        return node;
    // }
}

Node* deleteNode(Node* root, int value)
{
    Node* iPre;
    if(root == NULL)
    {
        return NULL;
    }
    if(root -> left == NULL && root -> right == NULL)
    {
        delete(root);
        return NULL;
    }

    if(value < root -> data)
    {
        root -> left = deleteNode(root -> left, value);
    }
    else if(value > root -> data)
    {
        root -> right = deleteNode(root -> right, value);
    }
    else
    {
        iPre = inorderPredecessor(root);
        root -> data = iPre -> data;
        root -> left = deleteNode(root -> left, iPre -> data);
    }
    return root;
}

int main(){
    Node* p = createNode(5);
    Node* p1 = createNode(3);
    Node* p2 = createNode(6);
    p->left = p1;
    p->right = p2;
    Node* p4 = createNode(1);
    Node* p5 = createNode(4);
    p1->left = p4;
    p1->right = p5;

    inOrder(p);
    cout<<endl;
    deleteNode(p, 6);
    inOrder(p);

    return 0;
}