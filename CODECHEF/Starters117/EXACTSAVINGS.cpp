//Code By @trickymindme
#include<bits/stdc++.h>
#define ll long long int 
#define vi vector<int>
#define vll vector<long long int>
#define vvi vector<vi>
#define vvl vector<vll>
#define vs vector<string>
#define  pii pair<int,int>
#define mpii map<int,int>
#define mem(a,b) memset(a,(b),sizeof(a))
#define FOR(i,j,k,in) for(int i=j;i<k;i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i,j) FOR(i,0,j,1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(c) (c).begin(),(c).end()
#define scanArray(v) for(auto &i:v) cin>>i;
#define printArray(v) for(auto &i:v) cout<<i<<" "; cout<<endl;
#define MP make_pair
#define pb push_back
#define eb emplace_back
#define INF (int)1e9
#define MOD 1000000007
#define MOD1 998244353
#define PI 3.141592653589793238462

#define _test() int _T;  cin>>_T; while(_T--)
#define _test2() for(int c=1;c<T+1; c++){  cout<<"Case #"<<c<<": "; solve();}
#define _print_time() cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC  << " mS\n"

// Functions
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

using namespace std;

 bool f1(vll& arr, ll k) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int sum = arr[i];
            if (sum == k){
                return true;
            }
            for (int j = i + 1; j < n; j++) {
                sum += arr[j];
                if (sum == k){
                    return true;
                }
            }
        }
        return false;
}


void solve()
{
    ll n,x,z;
    cin>>n>>x>>z;

    vll v(n);
    vector<vll> ht(x);

    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        int r = v[i] % x;
        ht[r].pb(v[i]);
        v[i]%2==0;
    }


    if(z%x==0){
        cout<<z/x<<endl;
        return;
    }

    ll l = (z/x) + 1;
    ll u = (z + accumulate(all(v) , 0)) / x +1;

    for(int i=l;i<=u;i++)
    {
        ll rem = (i*x)-z;
        if(f1(v,rem))
        {
            cout<<i<<endl;
            return;
        }
    }
    cout<<-1<<endl;

    


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    _test() 
        solve();
        
    _print_time();
    return 0;    
}

