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

void yash56244()
{
    ll n;
    cin >> n;
    ll a[3] = {0};
    FOR(i, n)
    {
        ll ai;
        cin >> ai;
        if (ai % 3 == 0)
        {
            a[0]++;
        }
        else if (ai % 3 == 1)
        {
            a[1]++;
        }
        else
        {
            a[2]++;
        }
    }
    vll yash;
    for (ll i = 0; i < 3; i++)
    {
        yash.push_back({a[i % 3], i});
    }
    sort(yash.begin(), yash.end());
    ll k = n / 3;
    ll ans = 0;
    if (yash[1].first <= k)
    {
        ll m = yash[2].second;
        ll a0 = yash[0].second, a1 = yash[1].second;
        if (a0 == m - 1 || m == a0 - 2)
        {
            ans += 2 * (k - a[a0]);
            ans += (k - a[a1]);
        }
        else
        {
            ans += 2 * (k - a[a1]);
            ans += k - a[a0];
        }
    }
    else
    {
        ll m = yash[2].second;
        ll a0 = yash[0].second, a1 = yash[1].second;
        if (a0 == m - 1 || m == a0 - 2)
        {
            ans += 2 * (a[m] - k);
            ans += (a[a1] - k);
        }
        else
        {
            ans += 2 * (a[a1] - k);
            ans += (a[m] - k);
        }
    }
    cout << ans << endl;
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