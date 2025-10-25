#include <bits/stdc++.h>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

void selectionSortStr(int arrS[], int n, long long &cmp2, long long &swaps)
{
    cmp2 = swaps = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            cmp2++;
            if (arrS[j] < arrS[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swap(arrS[i], arrS[minIndex]);
            swaps++;
        }
    }
}

void insertionSort(int arrI[], int n, long long &cmp1, long long &shifts)
{
    cmp1 = shifts = 0;
    for (int i = 1; i < n; i++)
    {
        int key = arrI[i];
        int j = i - 1;
        while (j >= 0 && (++cmp1 && arrI[j] > key))
        {
            arrI[j + 1] = arrI[j];
            shifts++;
            j--;
        }
        arrI[j + 1] = key;
        shifts++;
    }
}
long long cmp3 = 0, copyCount = 0;

void merging(int arrM[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = arrM[l + i];
        copyCount++;
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arrM[m + 1 + j];
        copyCount++;
    }
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        cmp3++;
        if (L[i] <= R[j])
        {
            arrM[k] = L[i];
            i++;
            k++;
        }
        else
        {
            arrM[k] = R[j];
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        arrM[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arrM[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arrM[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arrM, l, m);
        mergeSort(arrM, m + 1, r);
        merging(arrM, l, m, r);
    }
}

int main()
{
    srand(time(0));

    int n = 1000;

    int arrI[10000], arrS[10000], arrM[10000];

    for (int i = 0; i < n; i++)
    {
        int p = rand();
        arrI[i] = p;
        arrS[i] = p;
        arrM[i] = p;
    }

    long long swaps, cmp1, cmp2, shifts;

    insertionSort(arrI, n, cmp1, shifts);
    selectionSortStr(arrS, n, cmp2, swaps);
    mergeSort(arrM, 0, n - 1);

    cout << "Sorted Array For Insertion Sort: " << endl;
    for (int i = 0; i < n; i++)
        cout << arrI[i] << " ";
    cout << endl;
    cout << "Comparisons = " << cmp1 << ", shifts = " << shifts << endl;
    cout << endl;

    cout << "Sorted Array For Selection Sort: " << endl;
    for (int i = 0; i < n; i++)
        cout << arrS[i] << " ";
    cout << endl;
    cout << "Comparisons = " << cmp2 << ", Swaps = " << swaps << endl;
    cout << endl;

    cout << "Sorted Array For Merge Sort: " << endl;
    for (int i = 0; i < n; i++)
        cout << arrM[i] << " ";
    cout << endl;
    cout << "Comparisons = " << cmp3 << ", Copy Count = " << copyCount << endl;
    cout << endl;

    return 0;
}