//Counts the no of subset with a given sum
// Github:- Gupta-Nikhil85


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

int countSubsetSum(int arr[], int sum, int n){
	int t[n+1][sum+1];

	// Initialization
	for(int i=0; i<n+1; i++){
		t[i][0]=1;
	}
	
	for(int j=1; j<sum+1; j++){
		t[0][j]=0;
	}

	for(int i=1; i<n+1; i++){
		for(int j=1; j<sum+1; j++){
			if(arr[i-1]<=j){
				t[i][j]= t[i-1][j] + t[i-1][j-arr[i-1]];
			}
			else{
				t[i][j]= t[i-1][j];
			}
		}
	}
	return t[n][sum];
}


int main(){
    file_i_o();
    int arr[]= {2,3,5,6,11,10};
    int sum=10;
    int n=sizeof(arr)/sizeof(int);
    cout<<countSubsetSum(arr, sum, n);
	return 0;
}