#include<iostream>
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

int main(){
    Node* p = createNode(5);
    Node* p1 = createNode(67);
    Node* p2 = createNode(95);
    p->right = p2;
    p->left = p1;

    cout<<p2 -> data;

    return 0;
}