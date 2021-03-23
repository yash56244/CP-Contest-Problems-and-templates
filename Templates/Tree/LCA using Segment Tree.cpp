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

struct LCA // LCA using Segment tree.
{
    vl height, euler, first, segtree;
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
        segtree.resize(m * 4);
        build(1, 0, m - 1);
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

    void build(ll node, ll s, ll e)
    {
        if (s == e)
        {
            segtree[node] = euler[s];
        }
        else
        {
            ll mid = s + (e - s) / 2;
            build(node << 1, s, mid);
            build(node << 1 | 1, mid + 1, e);
            ll l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    ll query(ll node, ll s, ll e, ll L, ll R)
    {
        if (s > R || e < L)
        {
            return -1;
        }
        if (s >= L && e <= R)
        {
            return segtree[node];
        }
        ll mid = s + (e - s) / 2;
        ll left = query(node << 1, s, mid, L, R);
        ll right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1)
            return right;
        if (right == -1)
            return left;
        return (height[left] < height[right] ? left : right);
    }

    ll lca(ll u, ll v)
    {
        ll left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
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