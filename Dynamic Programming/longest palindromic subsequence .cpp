#include <iostream>

using namespace std;
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

class Solution{
  public:
    int longestPalinSubseq(string A) {
      
      int n=A.size();
      string B = A;
       reverse(B.begin() , B.end());
      
       
       int t[n+1][n+1];
       for(int i=0; i<=n; i++){
           for(int j=0; j<=n; j++){
               if(i==0 || j==0)
               t[i][j]=0;
     
            else  if(A[i-1]==B[j-1])
               t[i][j] = 1+ t[i-1][j-1];
               
               else
               t[i][j] = max(t[i-1][j] , t[i][j-1]);
           }
       }
       return t[n][n];
    }
};