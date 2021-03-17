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
const ll maxn = 2e5 + 5;

struct LCA // LCA using Sparse Table.
{
    vl height, euler, first, log_table;
    vvl sparse_table;
    vb vis;
    ll n;

    LCA(vvl &adj, ll root = 0) // zero-based indexing
    {
        n = adj.size();
        height.resize(n);
        euler.reserve(2 * n);
        first.resize(n);
        vis.assign(n, false);
        dfs(adj, root);
        ll m = euler.size();
        RMQ(euler);
    }

    void dfs(vvl &adj, ll node, ll h = 0)
    {
        vis[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        FOREACH(v, adj[node])
        {
            if (!vis[v])
            {
                dfs(adj, v, h + 1);
                euler.push_back(node);
            }
        }
    }
    void RMQ(vl v)
    {
        log_table.assign(v.size() + 1, 0);
        for (ll i = 2; i < log_table.size(); i++)
            log_table[i] = log_table[i / 2] + 1;

        sparse_table.assign(log_table.back() + 1, vl(v.size()));
        sparse_table[0] = v;
        for (ll row = 1; row < sparse_table.size(); row++)
        {
            for (ll i = 0; i + (1 << row) <= v.size(); i++)
            {
                sparse_table[row][i] = min(sparse_table[row - 1][i], sparse_table[row - 1][i + (1 << (row - 1))]);
            }
        }
    }

    ll minimum(ll l, ll r)
    {
        ll log = log_table[r - l];
        return min(sparse_table[log][l], sparse_table[log][r - (1 << log)]);
    }

    ll lca(ll u, ll v)
    {
        ll left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return minimum(left, right + 1);
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
    // cin >> t;
    while (t--)
    {
        yash56244();
    }
    return 0;
}