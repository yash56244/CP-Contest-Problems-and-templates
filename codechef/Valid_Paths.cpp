#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define FOR(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define FORL(i, a, n) for (int(i) = (a); (i) <= (n); (i)++)
#define FORR(i, a, n) for (int(i) = (a); (i) >= (n); (i)--)
#define FORSQ(i, a, n) for (int(i) = (a); (i) * (i) <= (n); ++(i))
#define FOREACH(a, b) for (auto &(a) : (b))
#define all(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))
#define log(args...)                             \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
#define logcontainer(container)   \
    for (auto &(e) : (container)) \
        cout << (e) << " ";       \
    cout << endl;
void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << *it << " = " << a << endl;
    err(++it, args...);
}

typedef long long int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;
typedef vector<bool> vb;
typedef priority_queue<ll> maxheap;
typedef priority_queue<ll, vl, greater<ll>> minheap;
typedef map<ll, ll> mapll;

const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll maxn = 1e5 + 5;

vvl adj(maxn);
vl dp(maxn), dp1(maxn);
ll sets;

ll Mod(ll a, ll b)
{
    return (b + a % b) % b;
}

void dfs(int s, int p)
{
    int cnt = 0;
    FOREACH(v, adj[s])
    {
        if (v != p)
        {
            dfs(v, s);
            cnt++;
            dp[s] = Mod(dp[s] + Mod(Mod(2 * dp[v], mod), mod), mod);
            dp1[s] = Mod(dp1[s] + Mod(dp1[v], mod), mod);
        }
    }
    dp[s] = Mod(dp[s] - cnt, mod);
    dp1[s] = Mod(dp1[s] + dp[s], mod);
    sets = Mod(sets + dp[s], mod);
    ll tsets = 0, rem = Mod(dp[s] - 1, mod);
    FOREACH(v, adj[s])
    {
        if (v != p)
        {
            rem = Mod(rem - dp1[v], mod);
            tsets = Mod(tsets + Mod(Mod(2 * rem, mod) * dp1[v], mod), mod);
        }
    }
    sets = Mod(sets + Mod(tsets, mod), mod);
}

void yash56244()
{
    int n;
    cin >> n;
    adj.clear();
    dp.clear();
    dp1.clear();
    FOR(i, maxn)
    {
        dp[i] = 1;
        dp1[i] = 0;
        adj[i].clear();
    }
    sets = 0;
    FORL(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << sets << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        yash56244();
    }
    return 0;
}