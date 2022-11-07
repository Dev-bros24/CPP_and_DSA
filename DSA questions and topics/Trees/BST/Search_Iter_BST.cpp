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

Node* searchIter(Node* root, int key)
{
    while(root != NULL && root -> data != key)
    {
        if(root -> data > key)
        {
            root = root -> left;
        }
        else
        {
            root = root -> right;
        }
    }
    return root;
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
    int key;
    cout<<"Enter the key you want to find"<<endl;
    cin>>key;
    Node* answer = searchIter(p, key);
    if(answer == NULL)
    {
        cout<<"Value is not present"<<endl;
    }
    else
    {
    cout<<"The key "<<answer->data<<" is found at "<<answer<<" node"<<endl;
    }

    return 0;
}