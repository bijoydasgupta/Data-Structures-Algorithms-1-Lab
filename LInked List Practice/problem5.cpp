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
    cout << "\nYour Linked List: [";
    Node *tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->data;
        if (tmp->next != nullptr)
            cout << "->";
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

// function to delete even numbers
void deleteEvenNodes()
{
    // Handle even nodes at the beginning
    while (head != nullptr && head->data % 2 == 0)
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }

    // Now handle the rest
    Node *cur = head;
    while (cur != nullptr && cur->next != nullptr)
    {
        if (cur->next->data % 2 == 0)
        {
            Node *tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        }
        else
        {
            cur = cur->next;
        }
    }
}

int main()
{
    int x;
    while (true)
    {
        cin >> x;
        if (x == -1)
            break;
        insertNodeAtEnd(x);
    }

    cout << "\nOriginal List: ";
    printList();

    deleteEvenNodes();

    cout << "\nAfter Deleting Even Numbers: ";
    printList();

    return 0;
}
