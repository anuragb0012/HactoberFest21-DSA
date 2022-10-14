#include<iostream>
using namespace std;
int main()
{
    int row,coloumn;
    int i,j;
    cout<<"Enter the row and coloumn"<<endl;
    cin>>row>>coloumn;


    for(i=1;i<=row;i++)
    {
        for(j=1;j<=coloumn;j++)
        {
        cout<<"*";
        }
    
    cout<<endl;
    }
}