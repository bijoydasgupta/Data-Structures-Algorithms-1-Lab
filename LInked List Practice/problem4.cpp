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
         << "\nYour Linked List: ";
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

void sortedList(int x)
{
    Node *num = new Node();
    num->data = x;
    num->next = nullptr;

    if (head == nullptr)
    {
        head = num;
    }
    else
    {
        if (num->data < head->data)
        {
            num->next = head;
            head = num;
        }
        Node *tmp = head;
        while (tmp->next != nullptr)
        {
            if (tmp->data < num->data && num->data < tmp->next->data)
            {
                num->next = tmp->next;
                tmp->next = num;
            }
            tmp = tmp->next;
        }
        if (tmp->data < num->data)
        {
            tmp->next = num;
        }
    }
    cout << endl
         << "\nYour Linked List: ";
    Node *cur = head;
    cout << "[";
    while (cur != nullptr)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << "]" << endl;
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

    int key;
    cout << "Enter the key: ";
    cin >> key;

    printList();
    sortedList(key);
    return 0;
}
