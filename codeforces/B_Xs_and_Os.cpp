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

pll yash56244()
{
    ll n;
    cin >> n;
    vector<string> v(n);
    FOR(i, n)
    {
        cin >> v[i];
    }
    vl hh(n), vv(n);
    ll ans = inf;
    FOR(i, n)
    {
        ll cnt = 0;
        FOR(j, n)
        {
            if (v[i][j] == '.')
                cnt++;
            else if (v[i][j] == 'O')
            {
                cnt = inf;
                break;
            }
        }
        ans = min(ans, cnt);
        hh[i] = cnt;
    }
    FOR(i, n)
    {
        ll cnt = 0;
        FOR(j, n)
        {
            if (v[j][i] == '.')
                cnt++;
            else if (v[j][i] == 'O')
            {
                cnt = inf;
                break;
            }
        }
        ans = min(ans, cnt);
        vv[i] = cnt;
    }
    if (ans == inf)
    {
        return {-1, -1};
    }
    ll res = 0;
    FOR(i, n)
    {
        if (vv[i] == 1 && hh[i] == 1 and v[i][i] == '.')
            res++;
        else
        {
            if (vv[i] == ans)
                res++;
            if (hh[i] == ans)
                res++;
        }
    }
    return {ans, res};
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        pll p = yash56244();
        cout << "Case #" << i << ": ";
        if (p.first == -1)
        {
            cout << "Impossible" << endl;
        }
        else
        {
            cout << p.first << " " << p.second << endl;
        }
    }
    return 0;
}