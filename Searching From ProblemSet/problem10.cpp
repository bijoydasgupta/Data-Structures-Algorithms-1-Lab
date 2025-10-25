#include <bits/stdc++.h>
using namespace std;

int findPeakIndex(int arr[], int n) {
    int lo = 0, hi = n - 1;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;

        if (arr[mid] < arr[mid + 1]) {
            lo = mid + 1; // Peak right side
        } else {
            hi = mid; // Peak at mid or left side
        }
    }
    return lo; // or hi, both same
}

int main() {
    int n;
    int arr[1000];
    cout << "Enter n: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int idx = findPeakIndex(arr, n);

    cout << "Peak element is " << arr[idx] << " at index " << idx << endl;

    return 0;
}
