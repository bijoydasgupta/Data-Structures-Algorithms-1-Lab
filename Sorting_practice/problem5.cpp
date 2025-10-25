#include <bits/stdc++.h>
using namespace std;

// Function to check if a part of the array is sorted
bool isSorted(int arr[], int start, int k)
{
    for (int i = start; i < start + k - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return false;
    }
    return true;
}

int main()
{
    int arr[1000];
    int n = 0;
    // Step 1: Read the array from input
    while (cin.peek() != '\n' && cin >> arr[n])
    {
        n++;
    }

    // Step 2: Read k
    int k;
    cin >> k;

    // Step 3: Do insertion sort one step at a time
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Shift elements greater than key
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place key at correct position
        arr[j + 1] = key;

        // Step 4: After sorting this part, check if any sorted partition of size k exists
        if (i + 1 >= k)
        {
            for (int start = 0; start <= i - k + 1; start++)
            {
                if (isSorted(arr, start, k))
                {
                    // Print the sorted partition
                    for (int m = start; m < start + k; m++)
                    {
                        cout << arr[m] << " ";
                    }
                    cout << endl;
                    return 0; // Done
                }
            }
        }
    }

    // If no sorted partition found
    cout << "No sorted partition of size " << k << " found.\n";
    return 0;
}
