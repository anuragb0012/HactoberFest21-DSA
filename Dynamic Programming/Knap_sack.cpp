#include <iostream>

using namespace std;
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 int knapsack(int w,int i, vector<int> weights, vector<int> values, vector<vector<int>>dp){
   /*
   //recursive approch(no dp attribute will be present)  
   //base condition
     if(i==0||w==0){
         return 0;
     }
    //  case-1: If weight of the element is lessthan w , now i will be having tw0 possibilites weather i can pick the element or i can skip the elemnt, so i will be choosing according to the max return value
        if(weights[i]<=w){
            return (values[i]+knapsack(w-weights[i],i-1,weights,values,dp))>(knapsack(w,i-1,weights,values,dp))?(values[i]+knapsack(w-weights[i],i-1,weights,values,dp)):(knapsack(w,i-1,weights,values,dp));

        }
    // case-2: If weight of the element is greaterthan w, in this case we are left with only one case ,i.e skip the element and proceed further
        else{
            return (knapsack(w,i-1,weights,values,dp));
        }
        */
   
   
   /////////////////////////////////////////////////////////////////////////
   //memoization approch
     //base condition
     if(i<0){
         return 0;
     }
     if(dp[i][w]!=-1){
         return dp[i][w];
     }
     else{
    //  case-1: If weight of the element is lessthan w , now i will be having tw0 possibilites weather i can pick the element or i can skip the elemnt, so i will be choosing according to the max return value
        if(weights[i]<=w){
            return dp[i][w]=(values[i]+knapsack(w-weights[i],i-1,weights,values,dp))>(knapsack(w,i-1,weights,values,dp))?(values[i]+knapsack(w-weights[i],i-1,weights,values,dp)):(knapsack(w,i-1,weights,values,dp));

        }
    // case-2: If weight of the element is greaterthan w, in this case we are left with only one case ,i.e skip the element and proceed further
        else{
            return dp[i][w]=(knapsack(w,i-1,weights,values,dp));
        }
     }
 }
 int main(){
     int n,w;
     cout<<"Enter n : "<<endl;
     cin>>n;
     cout<<"Enter w : "<<endl;
     cin>>w;
     vector<int>weights(n),values(n);
     vector<vector<int>>dp(n+1,vector<int>(w+1));
     for (int i = 0; i < n+1; i++)
        for (int j = 0; j < w + 1; j++)
            dp[i][j] = -1;
     cout<<"Enter the values array in one row with a space between : "<<endl;
     for(int i=0;i<n;i++){
         cin>>values[i];
     }
     cout<<"Enter the weights array in one row with a space between : "<<endl;
     for(int i=0;i<n;i++){
         cin>>weights[i];
     }
     cout<<knapsack(w,n-1,weights,values,dp)<<endl;
     return 0;
 }
