#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
int a[n],b[n],pas=0;int val[n];
for(int i=0;i<n;i++)
{
    cin>>a[i]>>b[i];
    pas+=b[i]-a[i];
    val[i]=pas;
 
}int max=0;
for(int i=0;i<n;i++)
{
   if(val[i]>max)
   {max=val[i];}
}
cout<<max;
 
 
 
  
    return 0;
 
}