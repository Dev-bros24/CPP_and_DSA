#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *createNode(int val)
{
    TreeNode *newnode = new TreeNode(val);
    return newnode;
}

class Solution
{
    // int leftheight = 0, rightheight = 0;
    int findDepth(TreeNode *&root)
    {
        if (!root->left && !root->right)
        {
            cout<<"Returning from base condition"<<endl;
            return 1;
        }

        int leftheight = 0, rightheight = 0;
        if (root->left)
        {
            cout<<"Going left"<<endl;
            leftheight = findDepth(root->left) + 1;
            cout<<"LeftHeight "<<leftheight<<endl;
        }
        if (root->right)
        {
            cout<<"Going right"<<endl;
            rightheight = findDepth(root->right) + 1;
        }

        if (!root->left && root->right)
        {
            cout<<"Inside if rightheight: "<<rightheight<<endl;
            return rightheight;
        }
        else if (!root->right && root->left)
        {
            cout<<"Inside else if leftheight: "<<leftheight<<endl;
            return leftheight;
        }
        else
        {
            cout<<"Inside else leftheight: "<<leftheight<<" rightheight: "<<rightheight<<endl;
            return min(leftheight, rightheight);
        }
    }

public:
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int depth = findDepth(root);
        return depth;
    }
};

int main()
{

    TreeNode *root, *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, *p9;

    root = createNode(0);
    p1 = createNode(2);
    p2 = createNode(4);

    root->left = p1;
    root->right = p2;

    p3 = createNode(1);
    p4 = createNode(3);
    p5 = createNode(-1);

    p1->left = p3;
    p2->left = p4;
    p2->right = p5;

    p6 = createNode(5);
    p7 = createNode(1);
    p8 = createNode(6);
    p9 = createNode(8);

    p3->left = p6;
    p3->right = p7;
    p4->right = p8;
    p5->right = p9;

    Solution obj1;

    int ans = obj1.minDepth(root);

    cout << "Answer: " << ans;

    return 0;
}