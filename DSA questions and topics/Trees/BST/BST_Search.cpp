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

Node* searchBST(Node* root, int key)
{
    if(root == NULL || root -> data == key)
    {
        return root;
    }
    else if(root -> data > key)
    {
        return searchBST(root -> left , key);
    }
    else
    {
        return searchBST(root -> right , key);
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
    int key;
    cout<<"Enter the key you want to find"<<endl;
    cin>>key;
    Node* answer = searchBST(p, key);
    if(answer == NULL)
    {
        cout<<"The key is not present"<<endl;
    }
    else
    {
    cout<<"The key "<<answer->data<<" is found at "<<answer<<" node"<<endl;
    }



    return 0;
}