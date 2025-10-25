#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 5
int q[MAX_SIZE];
int fronts = -1;
int rear = -1;

bool isFull() {
    return (fronts == 0 && rear == MAX_SIZE - 1) || (fronts == rear + 1);
}

bool isEmpty() {
    return fronts == -1;
}

void enqueue(int item) {
    if (isFull()) {
        cout << "Queue Overflow\n";
        return;
    }

    if (fronts == -1) {
        fronts = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }

    q[rear] = item;
}

int dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow\n";
        return -1;
    }

    int item = q[fronts];
    q[fronts] = 0;

    if (fronts == rear) {
        fronts = -1;
        rear = -1;
    } else {
        fronts = (fronts + 1) % MAX_SIZE;
    }

    return item;
}
void displayQueue() {
    if (isEmpty()) {
        cout << "Queue is empty\n"; return;
    }
    cout << "Queue elements: ";
    if (rear >= fronts) {
        for (int i = fronts; i <= rear; i++) {
            cout << q[i] << " ";
        }
    } else {
        for (int i = fronts; i < MAX_SIZE; i++) {
                cout << q[i] << " ";
        }
        for (int i = 0; i <= rear; i++) {
                cout << q[i] << " ";
        }
    }
    cout << endl;
}
int main() {
    int choice, item;
    while (true) {
        cout << "\nChoose an operation:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> item;
                enqueue(item);
                break;
            case 2:
                item = dequeue();
                if (item != -1)
                    cout << "Dequeued value: " << item << endl;
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
