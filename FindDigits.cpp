#include<iostream>
using namespace std;
void div_n(int n)
{
    int orgnl = n;
    int z=0;
    int count=0;
         while (n!= 0)
         {
            z=n%10;
            if(z==0)
            {
                  n=n/10;
            }
            else{
                n=n/10;
            if(orgnl%z==0)
                ++count;
           
            }
           
            
           
         }
         orgnl = 0; 
         cout<<count<<"\n";
        
}


int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        div_n(a[i]);
    }

    return 0;
}
