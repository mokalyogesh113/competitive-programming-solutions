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



int dfs(int curr, int n, vvi &adj , vi &cln)
{
    if(adj[curr].size()==0) return 1;

    for(auto i:adj[curr])
    {
        cln[curr] += dfs(i,n,adj,cln);
    }
    return cln[curr];

}


void solve()
{
    int n;
    cin>>n;
     
    vector<vector<int>> adj(n+1);
    vi parent(n+1,0);
    vi cln(n+1,0);

    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        parent[v] = u;
    }

    dfs(1 , n , adj , cln);


    int ans =0;
    for(int i=1;i<=n;i++)
    {
        if(adj[i].size()==0){

            vi temp;
            temp.push_back(i);

            int t = parent[i];
            while(t!=0)
            {
                temp.push_back(t);
                t = parent[t];
            }

            printArray(temp);

            int mid = temp[(temp.size()-1)/2];
            ans = max(ans , cln[mid]);

            cout<<mid<<endl;
        }
    }
    cout<<ans<<endl;




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

