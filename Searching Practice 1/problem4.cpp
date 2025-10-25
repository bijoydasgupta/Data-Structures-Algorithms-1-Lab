#include <bits/stdc++.h>
using namespace std;
int binarySearchIter(int arr[], int n, int key)
{
    int lo = 0, hi = n - 1;
    int count = 0;

    while (lo <= hi)
    {
        int mid = (hi + lo) / 2;

        if (arr[mid] == key)
        {
            count++;

            // check left side
            int left = mid - 1;
            while (left >= 0 && arr[left] == key)
            {
                count++;
                left--;
            }

            // check right side
            int right = mid + 1;
            while (right < n && arr[right] == key)
            {
                count++;
                right++;
            }
            break; // done counting
        }
        else if (arr[mid] < key)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return count;
}

int main()
{
    int arr[10000];

    int n = 0;
    while (cin.peek() != '\n' && cin >> arr[n])
    {
        n++;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            if (i > 0 && arr[i] == arr[i - 1])
                continue;

            int cnt = binarySearchIter(arr, n, arr[i]);
            if (cnt > 1) // print only repeated positives
                cout << "Number: " << arr[i] << " Count: " << cnt << endl;
        }
    }
    return 0;
}