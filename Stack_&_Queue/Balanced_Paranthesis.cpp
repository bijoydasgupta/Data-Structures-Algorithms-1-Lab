#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 100
char s[MAX_SIZE];
int top = -1;

void push(char item) {
    if (top >= MAX_SIZE - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    s[++top] = item;
}

char pop() {
    if (top < 0) {
        cout << "Stack Underflow\n";
        return '\0';
    }
    return s[top--];
}

bool stack_is_empty() {
    return top == -1;
}

bool is_matching_pair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(const string& s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(s[i]);
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (!stack_is_empty() && is_matching_pair(pop(), s[i])) {
                continue;
            } else {
                return false;
            }
        }
    }
    return stack_is_empty();
}
int main() {
    string s;
    cout << "Enter an expression: ";
    cin >> s;

    if (isBalanced(s))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

    return 0;
}
