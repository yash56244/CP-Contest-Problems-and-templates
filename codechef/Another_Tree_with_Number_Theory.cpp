#include <bits/stdc++.h>

using namespace std;

#define mod 1e9 + 7
#define pi 3.1415926535897932384626433832795
#define endl "\n"
#define FOR(i, n) for (ll(i) = 0; (i) < (n); (i)++)
#define FORL(i, a, n) for (ll(i) = (a); (i) <= (n); (i)++)
#define FORR(i, a, n) for (ll(i) = (a); (i) >= (n); (i)--)
#define FORSQ(i, a, n) for (ll(i) = (a); (i) * (i) <= (n); ++(i))
#define FOREACH(a, b) for (auto &(a) : (b))
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SIZE(v) (ll) v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define log(args...)                             \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }

#define logarr(arr, a, b)            \
    for (int z = (a); z <= (b); z++) \
        cout << (arr[z]) << " ";     \
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
typedef pair<ll, ll> pll;
typedef pair<char, char> pcc;
typedef vector<bool> vb;
typedef vector<pll> vll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef priority_queue<ll> PQMAX;
typedef priority_queue<ll, vector<ll>,
                       greater<ll>>
    PQMIN;
typedef set<ll> setll;
typedef map<ll, ll> mapll;

const ll inf = 1e15;

ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
const int MXN = 2e5 + 2;

vl g[MXN];
vll queries[MXN];
ll ans[MXN];
ll leaf[MXN];
unordered_map<ll, vl> level[MXN];

void dfsLeaf(ll s)
{
    if (g[s].size() == 0)
    {
        leaf[s] = 1;
    }
    FOREACH(v, g[s])
    {
        dfsLeaf(v);
        leaf[v] += leaf[s];
    }
}

void dfsLevel(ll s, ll lvl)
{
    if (g[s].size() == 0 or leaf[s] == 1)
        return;
    ll n = g[s].size();
    if (n == 1)
    {
        if (queries[g[s][0]].size() < queries[s].size())
        {
            swap(queries[g[s][0]], queries[s]);
        }
        FOREACH(q, queries[s])
        {
            queries[g[s][0]].push_back(q);
        }
        swap(level[lvl + 1], level[lvl]);
    }
    else
    {
        FOREACH(l, level[lvl])
        {
            if (l.first % n != 0)
            {
                auto v = l.second;
                FOREACH(x, v)
                {
                    ans[x] += l.first;
                }
            }
            else
            {
                level[lvl + 1][l.first / n] = l.second;
            }
        }
        FOREACH(q, queries[s])
        {
            if (q.first % n != 0)
            {
                ans[q.second] += q.first;
            }
            else
            {
                level[lvl + 1][q.first / n].push_back(q.second);
            }
        }
    }
    FOREACH(v, g[s])
    {
        dfsLevel(v, lvl + 1);
    }
    if (g[s].size() == 1)
    {
        swap(level[lvl + 1], level[lvl]);
    }
    else
    {
        FOREACH(q, queries[s])
        {
            if (q.first % n == 0)
            {
                level[lvl + 1][q.first / n].pop_back();
            }
        }
    }
    level[lvl + 1].clear();
}

void yash56244()
{
    ll n;
    cin >> n;
    FOR(i, n - 1)
    {
        ll u;
        cin >> u;
        g[u].push_back(i + 2);
    }
    dfsLeaf(1);
    ll q;
    cin >> q;
    FOR(i, q)
    {
        ll v, w;
        cin >> v >> w;
        queries[v].push_back({w, i});
    }
    dfsLevel(1, 1);
    FOR(i, q)
    {
        cout << ans[i] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    // cin >> t;
    while (t--)
    {
        yash56244();
    }
    return 0;
}