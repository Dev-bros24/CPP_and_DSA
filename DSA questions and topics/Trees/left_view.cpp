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

vector<int> ans;

void leftvie(Node* node, int level)
{
   
    if(node != NULL)
    {
        if(ans.size() == level)
        {
        ans.push_back(node -> data);
        }
        // level++;
        leftvie(node->left, level+1);
        leftvie(node->right, level+1);
    }
   return;
}

// vector<int> leftView(Node *root)
// {
//     vector<int> ans;
//     leftvie(root, 0, ans);
//     return ans;
// }
vector<int> leftView(Node *root)
{
    // vector<int> ans;
    leftvie(root, 0);
    return ans;
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

    vector<int> answer = leftView(p);

    for(int i =0 ; i<answer.size(); i++)
    {
        cout<<answer[i]<<" ";
    }

    return 0;
}

// 2 2 13 7 10 1 10 5 2 N 14 5 11 5 5 13