#include<bits/stdc++.h>
using namespace std ;
binarySearch( int arr[],int n,int target,int &cmp)
{ int lo = 0 ;
int hi = n-1 ;
    cmp=0;

    while (lo<=hi){

    int mid= lo+(hi-lo)/2;
        cmp++;
    if (arr[mid] > target)
    return mid;
    cmp++;
    if (arr[mid] <target)
      lo=mid+1;
    else hi=mid-1;

    }
    return -1;


}


   int main()


    {int n ;
    int arr[1000];
    int target;
    cout<<"enter n"<<endl ;
    cin>>n;

     cout<<"enter sorting array elenment"<<endl ;
     for(int i=0; i<n ; i++)
    cin>>arr[i];


  cout<<"enter target "<<endl ;
    cin>>target;
    int cmp;

    int idx = binarySearch(arr,n,target,cmp) ;
    if (idx>=0)
      cout<<"outout "<<idx<< endl ;

      //cout<<" comparision  "<<cmp<< endl ;
      return 0;}


