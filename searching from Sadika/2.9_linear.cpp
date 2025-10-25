#include <iostream>
using namespace std;

int main() {
    int n, key;
    cout << "Enter n: ";
    cin >> n;
    int arr[1000];
    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter key: ";
    cin >> key;

    int lo = 0, hi = n - 1;

    // Binary search (index খুঁজে বের করার জন্য)
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == key) {
            cout << "Closest element = " << arr[mid] << endl;
            return 0; // key ঠিকমতো পাওয়া গেলে exit
        }
        if (arr[mid] < key) lo = mid + 1;
        else hi = mid - 1;
    }

    // Binary search শেষে lo এবং hi থেকে closest বের করা
    int closest;
    if (hi >= 0 && lo < n) {
        if (key - arr[hi] <= arr[lo] - key)
            closest = arr[hi];  // left closer
        else
            closest = arr[lo];  // right closer
    }
    else if (hi >= 0) {
        closest = arr[hi];       // শুধু left আছে
    }
    else if (lo < n) {
        closest = arr[lo];       // শুধু right আছে
    }

    cout << "Closest element = " << closest << endl;
    return 0;
}
