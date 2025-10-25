#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int arr[1000];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Ascending Order: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    if (n % 2 != 0)
    {
        int mid = n / 2;
        cout << arr[mid] << endl;
    }
    else
    {
        int mid = ((n / 2) + ((n / 2) + 1)) / 2;
        cout << arr[mid] << endl;
    }

    return 0;
}