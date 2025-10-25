 #include <iostream>
using namespace std;
int linearSearch(int arr[], int n, int key, long long &cmp) {
 cmp = 0;
 for (int i = 0; i < n; i++) {
 cmp++;
 if (arr[i] > key) return i;
 }
 return -1;
}
int main() {
 int n, key;
 cout << "Enter n: ";
 cin >> n;
 int arr[1000];
 cout << "Enter " << n << " elements:\n";
 for (int i = 0; i < n; i++) cin >> arr[i];
 cout << "Enter key to search: ";
 cin >> key;
 long long cmp;
 int idx = linearSearch(arr, n, key, cmp);
 if (idx >= 0) cout << "output " << arr[idx] << "\n";
 else cout << "Not found\n";
 //cout << "Comparisons = " << cmp << "\n";
 return 0;
}
