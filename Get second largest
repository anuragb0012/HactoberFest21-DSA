#include<iostream>
using namespace std;

int secondlargest(int A[],int n)
{
    int res=-1;
    int largest=0;
    for(int i=1;i<n;i++)
    {
        if(A[i]>A[largest])
        {
            res=largest;
            largest=i;
        }
        else if(A[i]!=A[largest])
        {
            if(res==-1||A[i]>A[res])
            res=i;
        }   
    }
    return res;
}
int main()
 {
    int n;
    cout<<"Enter the size of array\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int x=secondlargest(arr,n);
    cout<<"Second Largest element in the array is "<<arr[x]<<" and at position "<<x+1;
    return 0;
}
