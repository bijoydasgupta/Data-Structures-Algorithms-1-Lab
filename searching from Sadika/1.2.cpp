//1st sheet er 2 no solve:                                                                                                                                                         #include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
int binarySearchIter(int arr[], int n, int key)
{
    int lo = 0, hi = n - 1;
    while (lo <= hi)
    {
        int mid = (hi + lo) / 2;
        if (arr[mid] == key)
            return 1;

        if (arr[mid] < key)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[10000];

    int n = 0;
    while (cin.peek() != '\n' && cin >> arr[n])
    {
        n++;
    }

    for (int i = 0; i <= arr[n - 1] + 1; i++)
    {
        int isfound = binarySearchIter(arr, n, i);
        if (isfound == -1)
        {
            cout << "The Smallest missing number is " << i << endl;
            break;
        }
    }
    return 0;
}
