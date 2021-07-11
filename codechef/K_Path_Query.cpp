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
const ll maxn = 2e6 + 5;

ll Mod(ll a, ll b)
{
    return (b + a % b) % b;
}

void yash56244()
{
    ll n;
    cin >> n;
    vvl adj(n + 1);
    FOR(i, n - 1)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vb vis(n + 1, false);
    vl dist(n + 1, inf);
    dist[1] = 0;
    vis[1] = true;
    queue<ll> q;
    q.push(1);
    while (!q.empty())
    {
        ll v = q.front();
        q.pop();
        FOREACH(u, adj[v])
        {
            if (!vis[u])
            {
                dist[u] = dist[v] + 1;
                q.push(u);
                vis[u] = true;
            }
        }
    }
    ll qr;
    cin >> qr;
    while (qr--)
    {
        ll k;
        cin >> k;
        vl v;
        while (k--)
        {
            ll vi;
            cin >> vi;
            v.push_back(vi);
        }
        ll mx1 = 1, mx2 = 1;
        FOREACH(e, v)
        {
            if (dist[e] > dist[mx1])
            {
                mx2 = mx1;
                mx1 = e;
            }
            else if (dist[e] > dist[mx2] && e != mx1)
            {
                mx2 = e;
            }
        }
        queue<ll> qq;
        qq.push(mx1);
        vb visi(n + 1, false);
        visi[mx1] = true;
        while (!qq.empty())
        {
            ll v = qq.front();
            qq.pop();
            FOREACH(u, adj[v])
            {
                if (!visi[u])
                {
                    visi[u] = true;
                    if (u == 1)
                    {
                        break;
                    }
                    qq.push(u);
                }
            }
        }
        while (!qq.empty())
        {
            qq.pop();
        }
        qq.push(mx2);
        visi[mx2] = true;
        while (!qq.empty())
        {
            ll v = qq.front();
            qq.pop();
            FOREACH(u, adj[v])
            {
                if (!visi[u])
                {
                    visi[u] = true;
                    if (u == 1)
                    {
                        break;
                    }
                    qq.push(u);
                }
            }
        }
        bool possible = true;
        FOREACH(e, v)
        {
            if (!visi[e])
            {
                possible = false;
                break;
            }
        }
        if (possible)
        {
            yes;
        }
        else
        {
            no;
        }
    }
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