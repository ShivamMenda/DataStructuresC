#include<iostream>
#define size 5
using namespace std;

class stack
{
private:
    int st[size],top;
public:
    void push();
    void pop();
    void peek();
    void status();
    stack(){
        top=-1;
    }
};

int main()
{
    int ch;
    stack ob;
    while (true)
    {
    cout<<"Implementation of stack"<<endl;
    cout<<"-----------------------"<<endl;
    cout<<"1.Push"<<endl;
    cout<<"2.Pop"<<endl;
    cout<<"3.peek"<<endl;
    cout<<"4.status"<<endl;
    cout<<"5.exit"<<endl;

    cout<<"Enter choice:";
    cin>>ch;

    switch (ch)
    {
    case 1:
        ob.push();
        break;
    case 2:
        ob.pop();
        break;
    case 3:
        ob.peek();
        break;
    case 4:
        ob.status();
        break;
    case 5:
        exit(1);
        break;
    default:
        cout<<"invalid input"<<endl;
        break;
    }


    }

}

void stack::push()
    {
        int x;
        if (top==size-1)
        {
            cout<<"Stack is Overflow"<<endl;
        }
        else{
            cout<<"Enter element:";
            cin>>x;
            top++;
            st[top]=x;
        }
    }
void stack::pop()
{
    if (top==-1)
    {
        cout<<"stack is Underflow";
    }
    else
    {
        cout<<"The popped element is "<<st[top]<<endl;
        top=top-1;
    }
    
    
}

void stack::peek()
{
    if (top==-1)
    {
        cout<<"Stack is Underflow"<<endl;
    }
    else
    {
        cout<<"The top elem is "<<st[top]<<endl;
    }
    
    
}

void stack::status()
{
    if (top==-1)
    {
        cout<<"Stack is empty"<<endl;
    }
    else{
        for (int i = top; i>=0; i--)
        {
            cout<<st[i]<<endl;;
        }
        
    }
}