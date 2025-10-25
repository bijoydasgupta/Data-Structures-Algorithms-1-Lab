#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[10000];

    int n = 0;
    while (cin.peek() != '\n' && cin >> arr[n])
    {
        n++;
    }

    int num;
    cin >> num;

    int indx = -1;
    int product = 1;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            indx = 1;
            a = arr[i];
            b = arr[i - 1];
            product = a * b;
            break;
        }
    }
    if (indx != -1)
        cout << "Output: " << a << " * " << b << " = " << product << endl;
    else
        cout << "Number is not found" << endl;
    return 0;
}