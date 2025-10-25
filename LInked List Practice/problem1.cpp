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

void sizeofList()
{
    int count=0;
    Node *tmp = head;
    while(tmp != NULL){
        count++;
        tmp = tmp->next;
    }
    cout<<"Size of the List: "<<count<<endl;
}

int main ()
{
    int x;

    while(cin.peek() != '\n' && cin>>x)
    {
        insertNodeAtEnd(x);
    }

    printList();

    sizeofList();
    return 0;
}
