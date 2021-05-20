#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define aur &&
#define ya ||
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
const ll maxn = 3e5 + 5;

ll Mod(ll a, ll b)
{
    return (b + a % b) % b;
}

vvl adj(maxn);
vl dp(maxn);
vl dpSize(maxn);

void dfs(ll s, ll p)
{
    FOREACH(v, adj[s])
    {
        if (v != p)
        {
            dfs(v, s);
        }
    }
    vll lvl1;
    FOREACH(v, adj[s])
    {
        if (v != p)
        {
            lvl1.push_back({dp[v], v});
        }
    }
    sort(lvl1.begin(), lvl1.end(), greater<pll>());
    int x = 1;
    FOREACH(pr, lvl1)
    {
        dpSize[pr.second] = x++;
    }
    FOREACH(v, adj[s])
    {
        if (v != p)
        {
            dp[s] += dpSize[v] * dp[v];
        }
    }
}

void yash56244()
{
    ll n, x;
    cin >> n >> x;
    dp.clear();
    dpSize.clear();
    FOR(i, maxn)
    {
        dp[i] = 1;
        dpSize[i] = 0;
        adj[i].clear();
    }
    FORL(i, 1, n - 1)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << dp[1] % mod * x % mod << endl;
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