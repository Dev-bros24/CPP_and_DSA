#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

// #define n 100

struct stacks
{
    char* arr;
    int top;
    int size;

stacks()
    {
        size = 100;
        top = -1;
        arr = new char[size];
    }

};
    
    void push(stacks *s, char ch)
    {
        if((*s).top == (*s).size-1)
        {
            cout<<"Stack overflow"<<endl;
        }
        else
        {
            (*s).top++;
            (*s).arr[(*s).top] = ch;
            // cout<<"Abhishek : "<<(*s).top<<" "<<(*s).arr[(*s).top]<<endl;
        }
    }

    char pop(stacks *s)
    {
        if((*s).top == -1)
        {
            cout<<"No elements to remove. Stack is empty."<<endl;
            return 0;
        }
        else
        {
            return (*s).arr[(*s).top --];// we don't care about rest elements
        }
    }

    char Top(stacks s)
    {
        // if(s.top == -1)
        // {
        //     cout<<"Stack is empty."<<endl;
        //     return -1;
        // }
        // else
        // {
            // cout<<"Abhishekkk: "<<s.top<<" "<<s.arr[s.top]<<endl;
            return s.arr[s.top];
        // }

    }

    bool empty(stacks s)
    {
        return s.top == -1;
        // if(top == -1)
        // {
        //     return true;
        // }
        // else
        // {
        //     return false;
        // }
    }

    int peek(stacks s, int i)
    {
        if(s.top - i + 1 < 0)
        {
            cout<<"Invalid position ";
        }
        else
        {
            cout<<"The value is: " << s.arr[s.top - i + 1];
        }
        return 0;
    }


int precedence(char ch)
{
    if(ch == '*' || ch == '/')
    {
        return 3;
    }
    else if(ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

bool isOperator(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return true;
    }
    else
    {
        return false;
    }
}

char *infixToPostfix(char *infix)
{
    stacks s1;
    char* postfix = new char[strlen(infix)+1];
    int i = 0; // Track infix Traversal
    int j = 0; // Track postfix addition
    while(infix[i] != '\0')
    {
        if(!isOperator(infix[i]))
        {

            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if(precedence(infix[i]) > precedence(Top(s1)) || empty(s1))
            {
                push(&s1, (char)infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(&s1);
                j++;
            }
        }
    }
    while(!empty(s1))
    {
        postfix[j] = pop(&s1);
        j++;
    }
    postfix[j] = '\0';
    return postfix;

}

int main(){
    const char *infix = "x-y/z-k*d"; // Not using char* as in C++ a string is not allowed to be converted to char* and const char* is allowed.
    cout<<"Postfix is : "<<infixToPostfix((char*)infix);
    return 0;
}
