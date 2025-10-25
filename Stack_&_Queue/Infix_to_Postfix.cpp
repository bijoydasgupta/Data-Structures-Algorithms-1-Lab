#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 100

char s[MAX_SIZE];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull () {
    return top == MAX_SIZE - 1;
}
void push(char c) {
    if (isFull()) {
        cout << "Stack Overflow" << endl;
        return;
    }
    s[++top] = c;
}

char pop() {
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        return 0;
    }
    return s[top--];
}

char peek() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return 0;
    }
    return s[top];
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

string infixToPostfix(string infix) {
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (isOperand(c)) {
            postfix += c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix += pop();
            }
            if (!isEmpty() && peek() == '(') {
                pop();
            }
        } else if (isOperator(c)) {
            while (!isEmpty() && precedence(peek()) >= precedence(c)) {
                postfix += pop();
            }
            push(c);
        }
    }

    while (!isEmpty()) {
        postfix += pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
