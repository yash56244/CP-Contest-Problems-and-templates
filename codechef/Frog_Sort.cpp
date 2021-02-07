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
    ll w[n];
    FOR(i, n)
    {
        cin >> w[i];
    }
    ll l[n];
    FOR(i, n)
    {
        cin >> l[i];
    }
    if (n == 2)
    {
        if (w[0] == 1)
        {
            cout << 0;
        }
        else
        {
            if (l[0] == 1)
            {
                cout << 2;
            }
            else
            {
                cout << 1;
            }
        }
    }
    else if (n == 3)
    {
        ll a, b, c, a1, b1, c1;
        FOR(i, n)
        {
            if (w[i] == 1)
            {
                a = a1 = i + 1;
            }
            else if (w[i] == 2)
            {
                b = b1 = i + 1;
            }
            else if (w[i] == 3)
            {
                c = c1 = i + 1;
            }
        }
        ll ans = 0;
        while (b <= a)
        {
            b += l[b1 - 1];
            ans++;
        }
        while (c <= b or c <= a)
        {
            c += l[c1 - 1];
            ans++;
        }
        cout << ans;
    }
    else if (n == 4)
    {
        ll a, b, c, d, a1, b1, c1, d1;
        FOR(i, n)
        {
            if (w[i] == 1)
            {
                a = a1 = i + 1;
            }
            else if (w[i] == 2)
            {
                b = b1 = i + 1;
            }
            else if (w[i] == 3)
            {
                c = c1 = i + 1;
            }
            else if (w[i] == 4)
            {
                d = d1 = i + 1;
            }
        }
        ll ans = 0;
        while (b <= a)
        {
            b += l[b1 - 1];
            ans++;
        }
        while (c <= b or c <= a)
        {
            c += l[c1 - 1];
            ans++;
        }
        while (d <= a or d <= b or d <= c)
        {
            d += l[d1 - 1];
            ans++;
        }
        cout << ans;
    }
    cout << endl;
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