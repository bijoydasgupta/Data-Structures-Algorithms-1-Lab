//1st sheet number 3
#include <bits/stdc++.h>
using namespace std;
int linearSearch(int arr[], int n, int key, long long &cmp) {
 cmp = 0;
 for (int i = 0; i < n; i++) {
 cmp++;
 //cout << "Comparisons = " << cmp << "\n";
 if (arr[i] ==key) return i;
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
 if (idx >= 0) cout << "output " << key+arr[idx+1]+arr[idx+2]+arr[idx+3] << "\n";
 else cout << "Not found\n";
 return 0;
}
