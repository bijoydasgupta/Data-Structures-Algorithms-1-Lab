#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};
Node *head = nullptr;

void printList()
{
    cout<<endl<<"Your Linked List: ";
    Node *tmp = head;
    cout << "[";
    while(tmp != nullptr)
    {
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
    cout<<"]"<<endl;
}

void insertNodeAtEnd (int data)
{
    Node *temp = new Node ();
    temp->data = data;
    temp->next = nullptr;

    if(head == nullptr){
        head = temp;
        return;
    }
    Node *cur = head;
    while(cur->next != nullptr){
        cur = cur->next;
    }
    cur->next = temp;

}

void findOccurance(int x)
{
    int count=0;
    Node *tmp = head;
    while(tmp != nullptr)
    {
        if(tmp->data == x)
        {
            count++;
        }
        tmp = tmp->next;
    }
    cout<<"Occurance: "<<count<<endl;
}

int main ()
{
    int x;

    while(true)
    {
        cin>>x;
        if(x == -1) break;
        insertNodeAtEnd(x);
    }
    int key;
    cout<<"Enter the key: ";
    cin>>key;

    printList();
    findOccurance(key);
    return 0;
}

