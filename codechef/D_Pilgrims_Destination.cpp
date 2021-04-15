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
const ll maxn = 1e5 + 5;

vector<vector<pll>> graph(maxn);
vl dp(maxn);
vl res;
void dfs1(ll s, ll p)
{
    if (p != 0)
    {
        dp[s] = dp[p] + 1;
    }
    FOREACH(v, graph[s])
    {
        if (v.first != p)
        {
            dfs1(v.first, s);
        }
    }
}
void dfs(ll s, ll p, ll pans, ll edgew)
{
    ll ans = pans + edgew * dp[s];
    bool leaf = true;
    FOREACH(v, graph[s])
    {
        if (v.first != p)
        {
            leaf = false;
            dfs(v.first, s, ans, v.second);
        }
    }
    if (leaf)
    {
        res.push_back(ans);
    }
}

void yash56244()
{
    dp.resize(maxn, 0);
    graph.clear();
    graph.resize(maxn);
    res.clear();
    ll n, m;
    cin >> n >> m;
    ll arr[m];
    FOR(i, m)
    {
        cin >> arr[i];
    }
    FOR(i, n - 1)
    {
        ll u, v, k;
        cin >> u >> v >> k;
        graph[u].push_back({v, k});
        graph[v].push_back({u, k});
    }
    dfs1(1, 0);
    dfs(1, 0, 0, 0);
    sort(arr, arr + m, greater<ll>());
    sort(res.begin(), res.end(), greater<ll>());
    ll i = 0, j = 0, cnt = 0;
    while (i < m && j < res.size())
    {
        if (res[j] <= arr[i])
        {
            i++;
            j++;
            cnt++;
        }
        else
        {
            j++;
        }
    }
    cout << cnt << endl;
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