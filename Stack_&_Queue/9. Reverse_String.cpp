#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 100
char s[MAX_SIZE];
int top = -1;

void push(char item)
{
    if (top >= MAX_SIZE - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    s[++top] = item;
}

char pop()
{
    if (top < 0) {
        cout << "Stack Underflow\n";
        return '\0';
    }
    return s[top--];
}

bool is_empty() {
    return top == -1;
}

void reverseString(string& str)
{
    for (char c : str) {
        push(c);
    }
    for (int i = 0; i < str.length(); i++) {
        str[i] = pop();
    }
}

int main()
{
    string str;
    cout << "Enter a string to reverse: ";
    getline(cin, str);

    reverseString(str);

    cout << "Reversed string: " << str << endl;

    return 0;
}
