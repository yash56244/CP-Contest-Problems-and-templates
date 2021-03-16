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
vl dpSize(maxn);
vl dpAns(maxn);
vl fact(maxn + 1);
vl naturalNumInverse(maxn + 1);
vl factorialNumInverse(maxn + 1);
vector<pair<ll, pll>> res;
ll n;

void pre()
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;

    FORL(i, 2, maxn)
    {
        naturalNumInverse[i] = (naturalNumInverse[mod % i] * (mod - (mod / i))) % mod;
    }
    factorialNumInverse[0] = factorialNumInverse[1] = 1;

    // precompute inverse of natural numbers
    FORL(i, 2, maxn)
    {
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % mod;
    }

    fact[0] = 1;
    // precompute factorials
    FORL(i, 1, maxn)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

ll NCR(ll n, ll r)
{
    if (r > n)
        return 0;
    if (r == n)
        return 1;
    return ((fact[n] * factorialNumInverse[r]) % mod * factorialNumInverse[n - r]) % mod;
}

ll dfs1(ll s, ll p) // rerouting and tree size
{
    ll ans = 1, subTreeSize = 0;
    FOREACH(e, adj[s])
    {
        if (e != p)
        {
            ll csize = dfs1(e, s);
            subTreeSize += csize;
            ans = (ans * NCR(subTreeSize, csize)) % mod;
            ans = (ans * dpAns[e]) % mod;
        }
    }
    dpAns[s] = ans;
    return subTreeSize + 1;
}

ll dfs2(ll s, ll p) // calculating res
{
    ll subTreeSize = 0;
    FOREACH(e, adj[s])
    {
        if (e != p)
        {
            ll csize = dfs2(e, s);
            subTreeSize += csize;
            res.push_back({min(csize, n - csize), {e, s}});
        }
    }
    dpSize[s] = subTreeSize + 1;
    return dpSize[s];
}
ll dfs4(ll s, ll p) // n <= 10
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

ll dfs3(ll s, ll p) // n <= 10
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
    ll k;
    cin >> n >> k;
    if (n == 1)
    {
        cout << 1 << " " << 1 << endl;
        return;
    }
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
    if (n <= 10)
    {
        vll c;
        FORL(i, 1, n)
        {
            ll f = dfs3(i, -1);
            c.push_back({f, i});
        }
        sort(c.begin(), c.end(), cmp);
        cout << c[k - 1].second << " " << c[k - 1].first << endl;
        return;
    }
    dpSize.clear();
    dpAns.clear();
    res.clear();
    dfs2(1, -1);
    sort(res.begin(), res.end(), greater<pair<ll, pll>>());
    // FOREACH(e, res)
    // {
    //     cout << res.size() << " ";
    // }
    ll k1, k2;
    if (res[0].first != res[0].first)
    {
        vl t;
        if ((res[0].second.first == res[1].second.first) || (res[0].second.first == res[1].second.second))
        {
            k1 = res[0].second.first;
        }
        else
        {
            k1 = res[0].second.second;
        }
        ll i = 1;
        t.push_back((res[0].second.first != k1) ? res[0].second.first : res[0].second.second);
        while (i != n && res[i - 1].first == res[i].first)
        {
            t.push_back((res[i].second.first != k1) ? res[i].second.first : res[i].second.second);
            i++;
        }
        k2 = *max_element(t.begin(), t.end());
    }
    else
    {
        ll a = res[0].second.first, b = res[0].second.second;
        if (dpSize[a] == n - dpSize[a])
        {
            k1 = max(a, b);
            k2 = min(a, b);
        }
        else
        {
            if (dpSize[a] > n - dpSize[a])
            {
                k1 = a;
                k2 = b;
            }
            else
            {
                k2 = a;
                k1 = b;
            }
        }
    }
    if (k == 1)
    {
        dfs1(k1, -1);
        cout << k1 << " " << ((dpAns[k1] % mod) + mod) % mod << endl;
    }
    else
    {
        dfs1(k2, -1);
        cout << k2 << " " << ((dpAns[k2] % mod) + mod) % mod << endl;
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