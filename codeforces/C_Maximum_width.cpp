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
    ll n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<pair<char, ll>> mpa;
    vector<pair<char, ll>> mpb;
    FOREACH(c, s)
    {
        mpa[c - 'a'].first = c;
        mpa[c - 'a'].second++;
    }
    bool f = true;
    ll prev, ans = -1;
    FOREACH(e, mpa)
    {
        if (f)
        {
            prev = e.second;
            f = false;
            continue;
        }
        ans = max(ans, e.second + prev - 1);
        prev = e.second;
    }
    FOREACH(c, t)
    {
        mpb[c - 'a'].first = c;
        mpb[c - 'a'].second++;
    }
    bool f1 = true;
    ll prev1, ans1 = -1;
    FOREACH(e, mpb)
    {
        if (f1)
        {
            prev1 = e.second;
            f1 = false;
            continue;
        }
        ans1 = max(ans1, e.second + prev1 - 1);
        prev1 = e.second;
    }
    if (ans == -1 and ans1 == -1)
    {
        cout << max(mpa[0].second - 1, mpb[0].second - 1) << endl;
        return;
    }
    cout << max(ans, ans1) << endl;
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