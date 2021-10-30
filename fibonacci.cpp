#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void fibo(ll n,ll x)
{
    if (n==0)
        cout<<0<<endl;
    else if (n==1)
        cout<<1<<endl;
    else
    {
        ll x1=0;
        ll x2=1;
        ll temp=0;
        for (ll i=1;i<n;i++)
        {
            temp=(x1+x2)%x;
            x1=x2;
            x2=temp;
        }
        cout<<temp<<endl;
    }
}

int main()
{
    ll n,x;
    cin>>n>>x;
    fibo(n,x);
}