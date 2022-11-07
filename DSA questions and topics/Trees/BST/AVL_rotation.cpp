#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node() : key(0), left(nullptr), right(nullptr) {}
    int height;
};

int getHeight(Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

Node *createNode(int key)
{
    Node *node = new Node;
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getBalanceFactor(Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

// Ideally we should get x's height first above because when we calculate y's height 
// it's left is x and we should move from leaf to root while updating heights.

    return y; // coz this is new root node now.
}

Node *insert(Node *node, int key)
{
    if (node == NULL)
    {
        return createNode(key);
    }

    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    // return node;

    node->height = 1 + max(getHeight(node->right), getHeight(node->left));
    int bf = getBalanceFactor(node);

    // Left Left Case
    if (bf > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }
    // Right Right Case
    if (bf < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }
    // Left Right Case
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Right Left Case
    if (bf < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preOrder(Node *root)
{
    Node *ptr = root;
    if (ptr != NULL)
    {
        cout << ptr->key << " ";
        preOrder(ptr->left);
        preOrder(ptr->right);
    }
}

int main()
{
    Node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preOrder(root);
    cout<<endl<<root->height;
    return 0;
}