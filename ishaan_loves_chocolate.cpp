//https://practice.geeksforgeeks.org/problems/ishaan-loves-chocolates2156/1/?category[]=Arrays&category[]=Arrays&page=1&query=category[]Arrayspage1category[]Arrays

#include<bits/stdc++.h>
using namespace std;


int chocolates(int arr[], int n);


int main()
{

    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];

        for(int i=0;i<n;i++)
            cin>>arr[i];


        cout << chocolates(arr, n);
        cout << endl;

    }

}
// } Driver Code Ends


int chocolates(int arr[], int n)
{
    // Complete the function
    int i = 0, j = n-1;
    while(i<j)
    {
        if(arr[i] > arr[j])
        {
            i++;
        }
        else if(arr[i] < arr[j])
        {
            j--;
        }
        else
        {
            i++;

        }


    }
    return arr[j];
}

