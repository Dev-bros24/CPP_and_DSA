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

void insertBST(Node* root, int key)
{
    Node* prev = NULL;
    while(root != NULL)
    {
        prev = root;
        if(root -> data == key)
        {
            cout<<"Element "<<key<<" can't be inserted as it's already present."<<endl;
            return;
        }
        else if(root -> data > key)
        {
            root = root -> left;
        }
        else
        {
            root = root -> right;
        }
    }

        Node* newnode = createNode(key);
        if(prev -> data > key)
        {
            prev -> left = newnode;
        } 
        else
        {
            prev -> right = newnode;
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

    insertBST(p, 10);
    insertBST(p, 15);

    cout<<"Abhishek: "<<p->right->left->data<<endl;
    cout<<"Abhishek: "<<p->right->right->right->data<<endl;
    inOrder(p);
    

    return 0;
}