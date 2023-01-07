#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
};

TreeNode* createNode(int value)
{
    TreeNode* newnode = new TreeNode;
    newnode -> val = value;
    newnode -> left = NULL;
    newnode -> right = NULL;    
    return newnode;
}

void inOrder(TreeNode* root)
{
    TreeNode* ptr = root;
    if(ptr != NULL)
    {
        inOrder(ptr->left);
        cout<<ptr->val<<" ";
        inOrder(ptr->right);
    }
}


int morrisTraversal(TreeNode* cur, int &k){ // Inorder
        while(cur){
            // cout<<"cur: "<<cur->val<<endl;
            if(!cur->left){
                if(k == 1) {
                    // cout<<"Inside IF "<<cur->val<<endl;
                    return cur->val;
                }
                cur = cur->right;
                k = k - 1;
            }
            else{
                TreeNode* prev = cur->left;
                while(prev->right != NULL && prev->right != cur) prev = prev->right;

                if(!prev->right){
                    prev->right = cur; // thread creation
                    cur = cur->left;
                }
                else{
                    if(k == 1) return cur->val;
                    cur = cur->right;
                    prev->right = NULL;
                    k = k - 1;
                }
            }
        }
        return 0;
}

int kthSmallest(TreeNode* root, int k) {
        int ans = morrisTraversal(root, k);
        return ans;
    }


int main(){
    TreeNode* p = createNode(7);
    TreeNode* p1 = createNode(2);
    TreeNode* p2 = createNode(11);
    p->left = p1;
    p->right = p2;
    TreeNode* p4 = createNode(1);
    TreeNode* p5 = createNode(14);
    // p1->left = p4;
    // p2->right = p5;

    inOrder(p);

    int ans = kthSmallest(p, 1);

    cout<<"\nAnswer: "<<ans<<endl;

    return 0;
}