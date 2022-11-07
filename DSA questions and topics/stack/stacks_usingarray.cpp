#include<bits/stdc++.h>
using namespace std;

#define n 100

struct stacks
{
    int* arr;
    int top;

    // public:
    stacks()
    {
        top = -1;
        arr = new int[n];
    }
    void push(int num)
    {
        if(top == n-1)
        {
            cout<<"Stack overflow"<<endl;
        }
        else
        {
            top++;
            arr[top] = num;
        }
    }
    int pop()
    {
        if(top == -1)
        {
            cout<<"No elements to remove. Stack is empty."<<endl;
            return 0;
        }
        else
        {
            return arr[top --];// we don't care about rest elements
        }
    }
    void Top()
    {
        if(top == -1)
        {
            cout<<"Stack is empty."<<endl;
        }
        else
        {
            cout<<arr[top]<<endl;
        }

    }
    bool empty()
    {
        return top == -1;
        // if(top == -1)
        // {
        //     return true;
        // }
        // else
        // {
        //     return false;
        // }
    }

    int peek(int i)
    {
        if(top - i + 1 < 0)
        {
            cout<<"Invalid position ";
        }
        else
        {
            cout<<"The value is: " << arr[top - i + 1];
        }
        return 0;
    }

};

int main(){
    stacks s1;
    s1.push(3); 
    s1.push(2); 
    s1.push(6);  
    s1.push(9);  
    s1.Top();  // 6
    // cout<<s1.empty()<<endl; // 0
    cout<<"The popped element is: "<<s1.pop()<<endl; 
    cout<<"The popped element is: "<<s1.pop()<<endl; 
    // s1.Top(); // 2
    // s1.pop();
    // s1.pop();
    // s1.pop(); // No elements to remove. Stack is empty.
    // cout<<s1.empty(); // 1
    s1.peek(2);
    return 0;
}