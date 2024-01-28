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


struct TreeNode {
    int val;
    int count; // Number of elements in left subtree
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), count(0), left(NULL), right(NULL) {}
};

void insert(TreeNode*& root, int num, int index, int& smaller_count, vector<int>& counts) {
    if (!root) {
        root = new TreeNode(num);
        counts[index] = smaller_count;
    } else if (num == root->val) {
        root->count++; // Increment duplicate count
        counts[index] = smaller_count + root->count - 1;
    } else if (num < root->val) {
        root->count++; // Increment left subtree count
        insert(root->left, num, index, smaller_count, counts);
    } else {
        smaller_count += root->count + 1; // Increment smaller count
        insert(root->right, num, index, smaller_count, counts);
    }
}

vector<int> countSmaller(vector<int> &nums) {
    vector<int> counts(nums.size(), 0);
    TreeNode* root = nullptr;

    for (int i = nums.size() - 1; i >= 0; --i) {
        int smaller_count = 0;
        insert(root, nums[i], i, smaller_count, counts);
    }

    return counts;
}

void solve()
{
    int n;
    cin>>n;

    vector<pair<ll,ll>> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i].first >> v[i].second;
    sort(all(v) , [](auto &a , auto &b){
        return b.second>a.second;
    });

    vi t(n);
    for(int i=0;i<n;i++)    t[i] = v[i].first;
    vi sol = countSmaller(t);


    ll ans = 0;
    for(int i=0;i<n;i++)
    {
        ans+=sol[i];
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

