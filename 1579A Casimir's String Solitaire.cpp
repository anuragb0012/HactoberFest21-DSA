#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define vl vector<ll>
#define loop(i,a,b) for(int i=a;i<=b;i++)
int main(){
	fast;
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int l=s.length();
        int cnta{0},cntb{0},cntc{0};
        rep(i,l){
            if(s[i]=='A')cnta++;
            else if(s[i]=='B')cntb++;
            else cntc++;
        }
        if(cntb==(cnta+cntc))cout<<"YES\n";
        else if((cnta==0) && (cntb==cntc))cout<<"YES\n";
        else if((cntc==0) && (cntb==cnta))cout<<"YES\n";
        else cout<<"NO\n";
    }
	return 0;
}