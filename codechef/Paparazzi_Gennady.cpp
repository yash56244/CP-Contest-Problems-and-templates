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

double slope(double x1, double y1, double x2, double y2)
{
    return (y2 - y1) / (x2 - x1);
}

void yash56244()
{
    ll n;
    cin >> n;
    vll coords, stk;
    FOR(i, n)
    {
        ll ai;
        cin >> ai;
        coords.push_back({ai, i + 1});
    }
    if (n == 2)
    {
        cout << 1 << endl;
        return;
    }
    stk.push_back(coords[0]);
    stk.push_back(coords[1]);
    ll ans = 1, m = stk.size();
    FORL(i, 2, n - 1)
    {
        while (stk.size() >= 2)
        {
            double s1 = slope(stk[m - 2].second, stk[m - 2].first, stk[m - 1].second, stk[m - 1].first);
            double s2 = slope(stk[m - 1].second, stk[m - 1].first, coords[i].second, coords[i].first);
            if (s1 <= s2)
            {
                stk.pop_back();
                m--;
            }
            else
                break;
        }
        stk.push_back(coords[i]);
        m++;
        ans = max(ans, stk[m - 1].second - stk[m - 2].second);
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