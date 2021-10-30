#include<bits/stdc++.h>
using namespace std;

int ecludian_gcd(int x,int y)
{
    if (x==0||y==0)
    {
        return x+y;
    }
    return ecludian_gcd(y,x%y);
}


// int simple_gcd(int x,int y)
// {
//     int div=0;
//     if (x>y)
//     {
//         for (int i=1;i<=x/2;i++)
//         {
//             if (x%i==0&&y%i==0)
//             {
//                 div=i;
//             }
//         }
//     }
//     else
//     {
//         for (int i=1;i<=y/2;i++)
//         {
//             if (x%i==0&&y%i==0)
//             {
//                 div=i;
//             }
//         }
//     }
//     return div;
// }

int main()
{
    int x,y;
    cin>>x>>y;
    if (x>y)
    {
        cout<<ecludian_gcd(x,y)<<endl;
    }
    else{
        cout<<ecludian_gcd(y,x)<<endl;
    }
}