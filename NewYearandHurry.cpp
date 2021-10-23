    //https://codeforces.com/contest/750/problem/A
    #include <bits/stdc++.h>
    using namespace std;
    //#define LOCAL
    #define fastIO ios::sync_with_stdio(0), cin.tie(0)
    #define endl '\n'
    #define forn(i,a,b) for(int i=a;i<b;i++)
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
    //cout << fixed << setprecision(12) <<x<<endl;
     
    int main()
    {
        fastIO;
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
    #endif
     
        short n = 0, k = 0, tLibre = 0;
        cin >> n >> k;
        tLibre = 240 - k;
        int a[n+1];
        forn(i,1,n+1)
        {
            a[i] = 5*i;
            //cout<<a[i]<<endl;
        }
        short cnt = 0, sum = 0;
        forn(i,1,n+1){
            if((sum+a[i])<=tLibre){
                sum+=a[i];
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
     
