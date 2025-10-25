#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[10000];
    int n = 0;
    int count = 0;
    while (cin.peek() == '\n' && cin >> arr[n])
    {
        n++;
    }
    int k;
    cin >> k;

    for (int i = 0; i < n - 1; i++)
    {
        bool swaps = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swaps = true;
            }
        }
        if (swaps == false)
            break;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
        {
            count++;
        }
    }
    cout << "Output: " << count << endl;
    return 0;
}