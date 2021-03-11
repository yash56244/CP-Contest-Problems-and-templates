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
const ll mod = 1e9 + 7;

void yash56244()
{
    ll n, u, r, d, l;
    cin >> n >> u >> r >> d >> l;
    ll cntU = 0, cntR = 0, cntL = 0, cntD = 0;
    if (u == n)
    {
        cntU = u;
        cntL++;
        cntR++;
    }
    if (r == n)
    {
        cntR = n;
        cntU++;
        cntD++;
    }
    if (d == n)
    {
        cntD = n;
        cntR++;
        cntL++;
    }
    if (l == n)
    {
        cntL = n;
        cntU++;
        cntD++;
    }
    if (u == n - 1)
    {
        if (l > r)
        {
            cntL++;
        }
        else
        {
            cntR++;
        }
    }
    if (d == n - 1)
    {
        if (l >= r)
        {
            cntL++;
        }
        else
        {
            cntR++;
        }
    }
    if (l == n - 1)
    {
        if (u > d)
        {
            cntU++;
        }
        else
        {
            cntD++;
        }
    }
    if (r == n - 1)
    {
        if (u >= d)
        {
            cntU++;
        }
        else
        {
            cntD++;
        }
    }
    if (u != n && cntU > u)
    {
        no;
    }
    else if (r != n && cntR > r)
    {
        no;
    }
    else if (l != n && cntL > l)
    {
        no;
    }
    else if (d != n && cntD > d)
    {
        no;
    }
    else
    {
        yes;
    }
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