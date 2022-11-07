#include<iostream>
using namespace std;
int main(){
    
    return 0;
}



struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

Node *flatten(Node *root)
{
     Node *ptr = root -> bottom;
     Node *dum2 = root -> next;
     Node *dum1 = root -> next -> next;
     Node *dum3;
     
     while (dum2 != NULL)
     {
         while (dum2 != NULL)
         {
             if( ptr -> bottom != NULL)
             {
             if ((ptr -> bottom -> data) > (dum2 -> data))
             {
                 dum3 = dum2 -> bottom;
                 dum2 -> bottom = ptr -> bottom;
                 ptr -> bottom = dum2;
                //  dum2 = dum2 -> next;
                dum2 = dum3;
                if(dum2 != NULL)
                {
                if ((ptr -> bottom -> data) < (dum2 -> data))
                {
                    ptr = ptr -> bottom;
                }
                }
             }
             else
             {
                ptr = ptr -> bottom;
             }
             }
             else
             {
                 dum3 = dum2 -> bottom;
                //  dum2 -> bottom = ptr -> bottom;
                 ptr -> bottom = dum2;
                //  dum2 -> bottom = NULL;
                dum2 = dum1;
             }
         }
         dum2 = dum1;
         if(dum1 != NULL)
         {
         dum1 = dum1 -> next;
         }
     }
     return root;
}
