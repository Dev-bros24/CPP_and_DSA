/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

/*
     10
     
  8      14
 /       
5   9   13   17

Desired Output
10
8 14
5 9 13 17
*/

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void getLevel(Node* root, vector<int> &temp, int level){
    if(!root) return;
    if(level == 1){
        temp.push_back(root->data);
        return;
    }
    
    getLevel(root -> left, temp, level-1);
    getLevel(root -> right, temp, level-1);
    
}

void addNode(Node* root, Node* &node, int &maxlevel){
    // cout<<"values: "<<root->data<<" "<<node->data<<endl;
    maxlevel++;
    if(root -> data > node->data){
        if(!root -> left){
            root -> left = node;
            maxlevel++;
            return;
        }
        else{
            addNode(root->left, node, maxlevel);
        }
    }
    else{
        if(!root -> right){
            root -> right = node;
            maxlevel++;
            return;
        }
        else{
            addNode(root->right, node, maxlevel);
        }
    }
}

int main()
{
    int option = 0, levels = 0, count = 0, max_level = 0;
    Node* root = NULL;
    do{
        cout<<"\nPlease select from the options below: "<<endl;
        cout<<"1. to add a Node to the tree \n2. To print the level order traversal"<<endl;
        cout<<"0. to exit"<<endl;
        cin>>option;
    
        if(option == 1){
            int num = 0;
            cout<<"Enter the node value"<<endl;
            cin>>num;
            if(!count){
                root = new Node(num);
                count++;
                levels++;
            }
            else{
                Node* tempNode = new Node(num);
                int maxlevel = 0;
                addNode(root, tempNode, maxlevel);
                levels = max(levels, maxlevel);
                count++;
            }
        }
    
        else if(option == 2){
            vector<vector<int>> ans;
            // cout<<"count: "<<count<<endl;
            // int levels = 0;
            // cout<<"Enter the levels: "<<endl;
            // cin>>levels;
    
            for(int i=1; i<=levels; i++){
                vector<int> temp;
                getLevel(root, temp, i);
                ans.push_back(temp);
            }
    
            cout<<"Below is the level order printing: "<<endl;
    
            for(int i=0; i<ans.size(); i++){
                for(int j=0; j<ans[i].size(); j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
                }
                cout<<endl;
                int sec_option = -1;
                cout<<"\nIf you want to continue press 1 else 0"<<endl;
                cin>>sec_option;
                if(!sec_option) break;
            }
            else{
                cout<<"\nWARNING: Please select an appropriate option\n"<<endl;
            }
    }while(option);

    return 0;
}
