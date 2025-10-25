#include<bits/stdc++.h>
using namespace std;

#define size 4
int stacks[size];
int top=-1;

bool isEmpty()
{
    if(top==-1) return true;
    else return false;
}
bool isFull()
{
    if(top==size - 1) return true;
    else return false;
}

void push(int value)
{
    if(isFull()) cout<<"The stack is full"<<endl;
    else
    {
        top++;
        stacks[top]=value;
        cout<<"Successfully inserted "<<value<<"."<<endl;
    }
}
void pop()
{
    if(isEmpty()) cout<<"The stack is empty"<<endl;
    else
    {
        cout<<"Successfully popped "<<stacks[top]<<" From the stack"<<endl;
        stacks[top]=0;
        top--;
    }

}
void seeElements()
{
    if(isEmpty()) cout<<"No elements in the stack."<<endl;
    else{
        cout<<"Elements in the stack: "<<endl;
        for(int i=top;i>=0;i--)
        {
            cout<<stacks[i]<<endl;
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    bool flag;
    do{
        cout<<"Which operation do you want?"<<endl;
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Check if stack is empty"<<endl;
        cout<<"4. Check if stack is full"<<endl;
        cout<<"5. See the elements of the stack"<<endl;
        cout<<"Press 0 to exit"<<endl;
        cin>>n;
        switch(n)
        {
        case 1:
            cout<<"Enter the value: "<<endl;
            int value;
            cin>>value;
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:

            flag=isEmpty();
            if(flag) cout<<"The stack is empty"<<endl;
            else cout<<"The stack is not empty"<<endl;
            break;
        case 4:
            flag=isFull();
            if(flag) cout<<"The stack is Full"<<endl;
            else cout<<"The stack is not Full"<<endl;
            break;
        case 5:
            seeElements();
            break;
        case 0:
            break;
        default:
            cout<<"Invalid choice."<<endl;
        }
    }while(n);
    return 0;
}
