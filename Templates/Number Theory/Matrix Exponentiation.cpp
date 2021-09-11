// https://www.hackerearth.com/problem/algorithm/the-unlucky-13-d7aea1ff/
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
const int mod = 1e9 + 9;
const ll maxn = 1e6 + 5;

ll Mod(ll a, ll b)
{
    return (b + a % b) % b;
}

vvl multiply(vvl &a, vvl &b)
{
    ll r1 = a.size(), c1 = a[0].size();
    ll r2 = b.size(), c2 = b[0].size();
    vvl ans(r1, vl(c2, 0));
    FOR(i, r1)
    {
        FOR(j, c1)
        {
            FOR(k, c2)
            {
                ans[i][k] += (a[i][j] * b[j][k]) % mod;
                if (ans[i][k] >= mod)
                    ans[i][k] -= mod;
                if (ans[i][k] < 0)
                    ans[i][k] += mod;
            }
        }
    }
    return ans;
}
vvl power(vvl &m, ll n)
{
    vvl res = m;
    ll nn = m.size();
    vvl ans(nn, vl(nn, 0));
    FOR(i, nn)
    {
        ans[i][i] = 1;
    }
    while (n)
    {
        if (n & 1)
        {
            ans = multiply(ans, res);
        }
        n >>= 1;
        res = multiply(res, res);
    }
    return ans;
}

void yash56244()
{
    ll n;
    cin >> n;
    vvl a({{10}, {1}});
    vvl t({{10, -1}, {1, 0}});
    vvl ans = power(t, n);
    ans = multiply(ans, a);
    cout << ans[1][0] << endl;
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