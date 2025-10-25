#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *head = nullptr;

void printList()
{
    cout << endl
         << "Your Linked List: ";
    Node *tmp = head;
    cout << "[";
    while (tmp != nullptr)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << "]" << endl;
}

void insertNodeAtEnd(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = nullptr;

    if (head == nullptr)
    {
        head = temp;
        return;
    }
    Node *cur = head;
    while (cur->next != nullptr)
    {
        cur = cur->next;
    }
    cur->next = temp;
}

int middleElement()
{
    if (head == nullptr)
        return -1;
    Node *cur = head;
    Node *prev = head;

    while (cur != nullptr && cur->next != nullptr)
    {
        cur = cur->next->next;
        prev = prev->next;
    }
    return prev->data;
}
int main()
{
    while (true)
    {
        int x;
        cin >> x;
        if (x == -1)
            break;
        insertNodeAtEnd(x);
    }

    printList();

    cout << "Middle Element of the list: ";

    cout << middleElement() << endl;
    return 0;
}
