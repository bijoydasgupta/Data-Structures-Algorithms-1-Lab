#include <bits/stdc++.h>
using namespace std;

int closestElement(int arr[], int n, int target)
{
    int lo = 0, hi = n - 1;

    // edge cases
    if (target <= arr[0])
        return 0;
    if (target >= arr[n - 1])
        return n - 1;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }

    // now hi < lo
    // arr[hi] < target < arr[lo]
    if ((target - arr[hi]) <= (arr[lo] - target))
        return hi;
    else
        return lo;
}

int main()
{
    int n, arr[1000], target;
    cout << "Enter n: ";
    cin >> n;

    cout << "Enter sorted array elements:" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter target: ";
    cin >> target;

    int idx = closestElement(arr, n, target);
    cout << "Closest element to " << target << " is: " << arr[idx]
         << " at index " << idx << endl;

    return 0;
}
