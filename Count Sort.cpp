#include <bits/stdc++.h>
using namespace std;

void Count_Sort(int arr[],int n) // Also read Radix sort
{
    int i,a[100],b[n],k=arr[0];
    memset(a,0,sizeof(a));
    for(i=1;i<n;i++)
    {
        k=max(k,arr[i]);
    }
    for(i=0;i<n;i++)
    {
        a[arr[i]]++;
    }
    for(i=1;i<=k;i++)
    a[i]+=a[i-1];

    for(i=n-1;i>=0;i--)
    {
        b[--a[arr[i]]]=arr[i];
    }
    for(i=0;i<n;i++)
    {
        arr[i]=b[i];
    }
}
int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  {
      cin>>arr[i];
  }
  Count_Sort(arr,0,n);
  for(int i=0;i<n;i++)
  {
      cout<<arr[i];
  }
  cout<<"\n";
}
