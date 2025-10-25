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

    int min_diff = INT_MAX;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] - arr[i] < min_diff)
            min_diff = arr[i + 1] - arr[i];
    }

    cout << "Minimum Difference: " << min_diff << endl;
    return 0;
}