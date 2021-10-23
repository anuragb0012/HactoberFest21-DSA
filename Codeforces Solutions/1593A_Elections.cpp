#include<bits/stdc++.h>
#define ll long long
#define m 10e9+7
using namespace std;
void koli() {
   int a,b,c;
   cin>>a>>b>>c;
   int m1=max(a,max(b,c)+1);cout<<m1-a<<" ";
   int m2=max(b,max(a,c)+1);cout<<m2-b<<" ";
   int m3=max(c,max(a,b)+1);cout<<m3-c<<" ";
   cout<<"\n";
 
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       koli();
   }
return 0;
 
}