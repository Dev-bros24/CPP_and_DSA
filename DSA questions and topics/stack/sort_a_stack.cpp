#include <bits/stdc++.h> 
using namespace std;

void place(stack<int> &stack, int ele)
{
    if(stack.empty() || ele >= stack.top()) 
    {
        stack.push(ele);
        return;
    }
    

        int val2 = stack.top();
        stack.pop();
        place(stack, ele);
        stack.push(val2);
    
}

void sortstack(stack<int> &stack)
{
    if(stack.empty()){
        return;
    }
  
    int ele = stack.top();
    stack.pop();
    
    sortstack(stack);
    
    place(stack, ele);
}

void sortStack(stack<int> &stack)
{
	sortstack(stack);
}

int main()
{
    stack<int> st;

    st.push(3);
    st.push(-7);
    st.push(9);
    st.push(-2);
    st.push(5);

    // cout<<"Before:"<<endl;
    // while(!st.empty())
    // {
    //     cout<<st.top()<<endl;
    //     st.pop();
    // }

    sortStack(st);

    cout<<"\nAnswer:"<<endl;
    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }

    return 0;
}