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
        bool swaps = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps = true;
            }
        }
        if (swaps = false)
            break;
    }

    int N;
    cin >> N;

    cout << "Ascending Order: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    if (N > 0 && N <= n)
        cout << arr[N - 1] << endl;
    else
        cout << "Invalid" << endl;

    return 0;
}