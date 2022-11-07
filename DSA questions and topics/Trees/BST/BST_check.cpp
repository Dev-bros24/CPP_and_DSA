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

bool isBST(Node* root)
{
    static Node* prev = NULL;
    if(root != NULL)
    {
        if(!isBST(root -> left))
        {
            return 0;
        }
        if(prev != NULL && prev -> data >= root -> data)
        {
            return 0;
        }
        prev = root;
        return isBST(root -> right);
    }
    else
    {
        return true;
    }
}


int main(){
    Node* p = createNode(7);
    Node* p1 = createNode(2);
    Node* p2 = createNode(11);
    p->left = p1;
    p->right = p2;
    Node* p4 = createNode(1);
    Node* p5 = createNode(14);
    p1->left = p4;
    p2->right = p5;

    inOrder(p);
    cout<<endl;
    bool answer = isBST(p);
    cout<<answer<<endl;

    return 0;
}