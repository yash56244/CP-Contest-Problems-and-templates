#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define aur &&
#define ya ||
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
const ll maxn = 1e6 + 5;

void yash56244()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vll g(n);
    ll pos;
    FOR(i, n)
    {
        cin >> g[i].first;
        g[i].second = i + 1;
    }
    vector<pair<pll, ll>> range(m);
    FOR(i, m)
    {
        cin >> range[i].first.first >> range[i].first.second >> range[i].second;
    }
    sort(g.begin(), g.end(), greater<pll>());
    ll lim = n, sum = 0;
    vl last;
    FOR(i, 1 << lim)
    {
        vb vv(n, 0);
        ll sum = 0;
        FOR(j, lim)
        {
            if (i & (1 << j))
            {
                sum += g[j].first;
                vv[g[j].second - 1] = 1;
            }
        }
        ll delta = 0;
        FOREACH(a, range)
        {
            ll d1 = a.second;
            FORL(i, a.first.first, a.first.second)
            {
                d1 *= vv[i - 1];
            }
            delta += d1;
        }
        last.push_back(sum + delta);
    }
    sort(last.begin(), last.end(), greater<ll>());
    FOR(i, k)
    {
        cout << last[i] << " ";
    }
    cout << endl;
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