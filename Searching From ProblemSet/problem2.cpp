#include <bits/stdc++.h>
using namespace std;

int freq[10000];

int linearSearch(int arr[], int sz, int key)
{
    for (int i = 0; i < sz; i++)
    {
        if (key == arr[i])
        {
            freq[i] = i;
        }
    }
}
int main()
{
    int arr[100000], n = 0;

    while (cin.peek() != '\n' && cin >> arr[n])
    {
        n++;
    }
    int target;
    cin >> target;

    linearSearch(arr, n, target);

    for (int i = 0; i < n; i++)
    {
        if (freq[i] != 0)
            cout << freq[i] << " ";
    }
    return 0;
}