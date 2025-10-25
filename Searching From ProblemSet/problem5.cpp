#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
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

    int idx = binarySearch(arr, n, target);
    cout << idx << endl;

    return 0;
}