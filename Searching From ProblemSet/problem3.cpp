#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int sz, int key)
{
    for (int i = 0; i < sz; i++)
    {
        if (key < arr[i])
        {
            return arr[i];
        }
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

    int greaterValue = linearSearch(arr, n, target);
    cout << greaterValue << endl;
    return 0;
}