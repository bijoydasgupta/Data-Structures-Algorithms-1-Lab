#include <bits/stdc++.h>
using namespace std;

int firstOccur(int arr[], int n, int key)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int secondOccur(int arr[], int n, int key)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
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

    int first = firstOccur(arr, n, target);
    int second = secondOccur(arr, n, target);

    cout << "(" << first << "," << second << ")";

    return 0;
}