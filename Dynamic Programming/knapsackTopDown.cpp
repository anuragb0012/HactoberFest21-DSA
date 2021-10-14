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

int knapsack(int n, int w, int wt[], int val[]){
	vector<vector<int>> t(n+1, vector<int>(w+1,0));

	// Initialize with base case i.e if(n==0 or w==0), ans=0.
	//Already intialized vector with 0
	for(int i=1; i<n+1; i++){
		for(int j=1; j<w+1; j++){
			if(wt[i-1]<= j){
				t[i][j]= max(val[i-1]+t[i-1][j-wt[i-1]], t[i-1][j]);
			}
			else{
				t[i][j]= t[i-1][j];
			}
		}
	}
	return t[n][w];
}




int main(){
    file_i_o();
    int wt[]= {1, 4, 14, 10};
    int val[]= {200, 150, 400, 200};
    cout<<knapsack(4, 20, wt, val)<<endl;
	return 0;
}