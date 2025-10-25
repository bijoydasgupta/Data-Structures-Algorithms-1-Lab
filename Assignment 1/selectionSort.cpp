#include<bits/stdc++.h>
using namespace std;

void selectionSortStr(string arr[], int n, long long &cmp, long long &swaps)
{
    cmp=swaps=0;
    
    for(int i=0; i<n-1; i++){
        int minIndex=i;
        for(int j=i+1; j<n; j++){
            cmp++;
            if(arr[j] < arr[minIndex])
            {
                minIndex=j;
            }
        }
        if(minIndex != i)
        {
            swap(arr[i], arr[minIndex]);
            swaps++;
        }
    }
}
int main () 
{
    int n;
    cin >> n;
    
    string arr[10000];
    
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    long long swaps, cmp;
    selectionSortStr(arr, n, cmp, swaps);
    
    cout << "Sorted Array: " << endl;
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    
    return 0;
}