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
    int key;
    cin >> key;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            int j = i;
            while (i <= j + 3)
            {
                sum = sum + arr[i];
                i++;
            }
            break;
        }
    }
    cout << "Sum = " << sum << endl;

    return 0;
}