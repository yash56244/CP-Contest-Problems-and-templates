#include <bits/stdc++.h>

using namespace std;

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
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

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
const ll mod = 1e9 + 7;
const ll maxn = 5e5 + 5;

vl adj[maxn];
vl fact(maxn);
vl dpSize(maxn);

void pre()
{
    fact[0] = 1;
    fact[1] = 1;
    FORL(i, 2, maxn - 1)
    {
        fact[i] = (i * fact[i - 1]) % mod;
    }
}

ll dfs2(ll s, ll p) // size of subtree, k = 1
{
    ll ans = 0;
    FOREACH(e, adj[s])
    {
        if (e != p)
        {
            ans += dfs2(e, s);
        }
    }
    return dpSize[s] = 1 + ans;
}

ll dfs1(ll s, ll p) // k = 1
{
    ll ans = fact[dpSize[s] - 1];
    FOREACH(v, adj[s])
    {
        if (v != p)
        {
            ans *= dfs1(v, s);
            ans /= fact[dpSize[v]];
        }
    }
    return ans;
}

ll dfs4(ll s, ll p) // size of subtree.
{
    ll ans = 0;
    FOREACH(e, adj[s])
    {
        if (e != p)
        {
            ans += dfs4(e, s);
        }
    }
    return 1 + ans;
}

ll dfs3(ll s, ll p)
{
    ll ans = fact[dfs4(s, p) - 1];
    FOREACH(v, adj[s])
    {
        if (v != p)
        {
            ans *= dfs3(v, s);
            ans /= fact[dfs4(v, s)];
        }
    }
    return ans;
}

bool cmp(pll a, pll b)
{
    if (a.first != b.first)
        return a.first > b.first;
    return a.second > b.second;
}

void yash56244()
{
    ll n, k;
    cin >> n >> k;
    FOR(i, maxn)
    {
        adj[i].clear();
    }
    FORL(i, 1, n - 1)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if (k == 1)
    {
        dpSize.clear();
        ll maxsize = -inf;
        FOREACH(v, adj)
        {
            maxsize = max(maxsize, (ll)v.size());
        }
        ll node = -1;
        FORL(i, 1, n)
        {
            if (adj[i].size() == maxsize)
            {
                node = i;
            }
        }
        ll sz = dfs2(node, -1);
        ll f = dfs1(node, -1);
        cout << node << " " << f << endl;
    }
    else if (k == 2 and n <= 10)
    {
        vll c;
        FORL(i, 1, n)
        {
            ll f = dfs3(i, -1);
            c.push_back({f, i});
        }
        sort(c.begin(), c.end(), cmp);
        cout << c[k - 1].second << " " << c[k - 1].first << endl;
    }
    else
    {
        cout << "Codeforces >> Codechef" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    pre();
    ll t = 1;
    cin >> t;
    while (t--)
    {
        yash56244();
    }
    return 0;
}