#include <bits/stdc++.h>
using namespace std;
void bublesort(int arr[], int n, int k)
{
    int sum = 0, cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        bool swaps = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                if (j + 1 == n - 1 - i && cnt != k)
                {
                    sum = sum + arr[j + 1];
                    cnt++;
                    if (cnt == k)
                    {
                        cout << "add done" << endl;
                        break;
                    }
                }
                swaps = true;
            }
        }
        if (cnt < k && swaps == false)
        {
            cout << "Already Sorted. So, Can't add any numbers" << endl;
            break;
        }
    }
    cout << "Answer: " << sum << endl;
}

int main()
{
    int arr[10000];
    int n = 0;
    // Read array until non-integer input
    while (cin.peek() != '\n' && cin >> arr[n])
    {
        n++;
    }
    int k;
    cin >> k;

    bublesort(arr, n, k);
    return 0;
}