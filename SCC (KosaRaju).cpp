#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define AND &&
#define OR ||
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define FOR(i, n) for (ll(i) = 0; (i) < (n); (i)++)
#define FORL(i, a, n) for (ll(i) = (a); (i) <= (n); (i)++)
#define FORR(i, a, n) for (ll(i) = (a); (i) >= (n); (i)--)
#define FORSQ(i, a, n) for (ll(i) = (a); (i) * (i) <= (n); ++(i))
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
const ll maxn = 2e5 + 5;

struct SCC //Strongly Connected Components usign KosaRaju Algorithm.
{
    ll n;
    vl todo, comp, comps; //comps will store the beginning node of all sccs.
    vb vis;               //comp[i] will store the beginning of scc of which i is part of.

    SCC(vvl &adj, vvl &radj)
    {
        n = adj.size();
        comp.resize(n, -1);
        vis.resize(n);
        init(adj, radj);
    }
    void dfs1(ll x, vvl &adj)
    {
        vis[x] = 1;
        FOREACH(y, adj[x])
        {
            if (!vis[y])
                dfs1(y, adj);
        }
        todo.push_back(x);
    }
    void dfs2(ll x, ll v, vvl &radj)
    {
        comp[x] = v;
        FOREACH(y, radj[x])
        {
            if (comp[y] == -1)
                dfs2(y, v, radj);
        }
    }
    void init(vvl &adj, vvl &radj)
    {
        FOR(i, n)
        {
            if (!vis[i])
            {
                dfs1(i, adj);
            }
        }
        reverse(all(todo));
        FOREACH(x, todo)
        {
            if (comp[x] == -1)
            {
                dfs2(x, x, radj), comps.push_back(x);
            }
        }
    }
    void print() // printing scc and starting point in O(nlogn).
    {            // printing can easily done in O(n) by starting dfs from each of comps and printing them.
        map<ll, vl> mp;
        FOR(i, n)
        {
            mp[comp[i]].push_back(i);
        }
        FOREACH(e, mp)
        {
            cout << e.first << " -> ";
            FOREACH(ev, e.second)
            {
                cout << ev << " ";
            }
            cout << endl;
        }
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