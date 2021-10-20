https://codeforces.com/contest/977/problem/C

#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define forn(i,a,b) for(ll i=a;i<b;i++)
#define ft first
#define sd second
#define sz size()
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<string,int> psi;
typedef pair<char,char> pcc;
typedef pair<double,double> pdd;
typedef pair<long long,long long> pll;
//cout << fixed << setprecision(15) <<x<<endl;
 
 
int main()
{
    fastIO;
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
 
    ll n = 0, k = 0;
    cin >> n >> k;
    vector<ll> v;
    map<ll,ll> m;
    forn(i,0,n)
    {
        ll x = 0;
        cin >> x;
        v.pb(x);
        m[x]++;
    }
    sort(all(v));
    vector<ll> ans;
    ll cnt = 0;
    for(auto &x:v)
    {
        if(cnt == k)
        {
            break;
        }
        ans.pb(x);
        cnt++;
    }
    ll aux = 0;
    set<ll> st;
    for(auto &x:ans)
    {
        st.insert(x);
    }
    ll ansD = -1;
    for(auto &x:st)
    {
        aux+=m[x];
        ansD = max(ansD,x);
    }
    if(k == 0){
        if(v[0]-1>=1) cout << 1 << endl;
        else cout << -1 << endl;
    }else{
    if(aux == k)
    {
        cout << ansD << endl;
    }
    else
    {
        cout << -1  << endl;
    }
    }
}
 
