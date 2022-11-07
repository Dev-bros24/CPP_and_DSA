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

void levelorderTraversal(Node* root, int level)
{
    if(root == NULL)
    {
        return;
    }
    else if(level == 1)
    {
        cout<<root -> data<<" ";
    }
    else
    {
        levelorderTraversal(root -> left, level-1);
        levelorderTraversal(root -> right, level-1);
    }
    return;
}

int main(){
    Node* p = createNode(4);
    Node* p1 = createNode(2);
    Node* p2 = createNode(6);
    p->left = p1;
    p->right = p2;
    Node* p4 = createNode(1);
    Node* p5 = createNode(3);
    p2->left = p4;
    p2->right = p5;

    for(int i = 1; i<=3; i++)
    {
    levelorderTraversal(p, i);
    }

    return 0;
}