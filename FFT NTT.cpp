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
const ll mod = 998244353;

ll power(ll x, ll y)
{
    ll res = 1;
    x = x % mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

ll inv(ll m)
{
    return power(m, mod - 2);
}

template <ll mod, ll pr> // NTT<998244353, 3> ntt;
class NTT
{
public:
    long long mod_pow(ll a, ll b)
    {
        ll res = 1;
        while (b)
        {
            if (b & 1)
                res = res * a % mod;
            a = a * a % mod;
            b /= 2;
        }
        return res;
    }
    void ntt(vector<ll> &a, bool flag)
    {
        ll n = (ll)a.size();
        vector<ll> &x = a, y(n);
        if (n == 1)
            return;

        long long s = flag ? (mod - 1) / n : (mod - 1 - (mod - 1) / n), z = mod_pow(pr, s);

        vector<ll> zt(n / 2 + 1, 1);
        for (ll i = 1; i <= n / 2; i++)
            zt[i] = (ll)(zt[i - 1] * z % mod);
        for (ll k = 1, h = n / 2; k < n; k <<= 1, h >>= 1)
        {
            ll ki = 0;
            for (ll i = 0; i < h; i++)
            {
                long long coef = zt[k * i];
                for (ll j = 0; j < k; j++)
                {
                    ll t0 = x[j + ki], t1 = x[j + ki + n / 2];
                    y[j + 2 * ki] = (t0 + t1) % mod;
                    y[j + 2 * ki + k] = (ll)((t0 - t1 + mod) * coef % mod);
                }
                ki += k;
            }
            x.swap(y);
        }
        if (!flag)
        {
            long long invs = mod_pow(n, mod - 2);
            for (ll i = 0; i < n; i++)
                x[i] = (ll)(x[i] * invs % mod);
        }
    }
    vector<ll> convolution(vector<ll> &a, vector<ll> &b) // vector<ll> res = ntt.convolution(a1, a2);
    {
        ll n = (ll)a.size() + (ll)b.size() - 1;
        ll m = 1;
        while (m < n)
            m *= 2;
        a.resize(m);
        b.resize(m);
        ntt(a, true), ntt(b, true);
        for (ll i = 0; i < (ll)a.size(); i++)
            a[i] = (ll)(1LL * a[i] * b[i] % mod);
        ntt(a, false);
        a.resize(n);
        return a;
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