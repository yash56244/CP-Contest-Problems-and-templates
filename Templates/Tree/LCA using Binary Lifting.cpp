#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define andd &&
#define orr ||
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define FOR(i, n) for (ll(i) = 0; (i) < (n); (i)++)
#define FORL(i, a, n) for (ll(i) = (a); (i) <= (n); (i)++)
#define FORR(i, a, n) for (ll(i) = (a); (i) >= (n); (i)--)
#define FORSQ(i, a, n) for (ll(i) = (a); (i) * (i) <= (n); ++(i))
#define FOREACH(a, b) for (auto &(a) : (b))
#define all(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))

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
const ll maxn = 1e6 + 5;

struct LCA
{
    ll n;
    vvl parent; // parent[i][v] = parent of vth node 2^i level up.
    vl depth;

    LCA(vvl &adj, ll root = 0)
    {
        n = adj.size();
        ll d = 1;
        while ((1 << d) < n)
        {
            d++;
        }
        parent.assign(d, vl(n));
        depth.resize(n);
        parent[0][root] = root;
        dfs(root, adj);
    }

    void dfs(ll s, vvl &adj)
    {
        FORL(i, 1, parent.size() - 1)
        {
            parent[i][s] = parent[i - 1][parent[i - 1][s]];
        }
        FOREACH(v, adj[s])
        {
            if (v != parent[0][s])
            {
                depth[v] = depth[parent[0][v] = s] + 1;
                dfs(v, adj);
            }
        }
    }

    ll jump(ll x, ll d)
    {
        if (depth[x] < d)
        {
            return -1;
        }
        FOR(i, parent.size())
        {
            if ((d >> i) & 1)
            {
                x = parent[i][x];
            }
        }
        return x;
    }

    ll lca(ll x, ll y)
    {
        if (depth[x] < depth[y])
            swap(x, y);
        x = jump(x, depth[x] - depth[y]);
        if (x == y)
            return x;
        FORR(i, parent.size() - 1, 0)
        {
            ll X = parent[i][x], Y = parent[i][y];
            if (X != Y)
                x = X, y = Y;
        }
        return parent[0][x];
    }

    ll dist(ll x, ll y)
    {
        return depth[x] + depth[y] - 2 * depth[lca(x, y)];
    }
};

void yash56244()
{
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;
    while (t--)
    {
        yash56244();
    }
    return 0;
}