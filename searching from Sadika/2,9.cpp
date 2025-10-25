#include <iostream>
 using namespace std;
 int binarySearchIter(int arr[], int n, int key, long long &cmp) {
    int lo = 0, hi = n - 1;
    cmp = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        cmp++;
        //if (arr[mid] == key) return mid;
        //cmp++;
        if (arr[mid] < key) lo = mid + 1;
        else                hi = mid - 1;
    }
   // return -1;
 }
 int main() {
    int n, key;
    cout << "Enter n: ";
    cin >> n;
    int arr[1000];
    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter key to search: ";
    cin >> key;
    long long cmp;
    int idx = binarySearchIter(arr, n, key, cmp);
    if (idx >= 0) cout << idx << "\n";
   //else         cout<< "Not found\n";


   cout<<"output   "<<arr[idx-1]<<endl;
    cout << "Comparisons = " << cmp << "\n";
    return 0;
 }
