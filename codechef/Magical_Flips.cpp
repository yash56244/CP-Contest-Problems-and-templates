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
void yash56244()
{
    ll n;
    cin >> n;
    ll a[n], b[n];
    FOR(i, n)
    {
        cin >> a[i];
    }
    FOR(i, n)
    {
        cin >> b[i];
    }
    vl temp(n, -1);
    ll aa = 0, bb = 0;
    FORR(i, 29, 0)
    {
        bool f = true;
        FOR(j, n)
        {
            if (temp[j] != -1)
            {
                if (temp[j] == 1)
                    f = ((f & (b[j] >> i) & 1));
                else
                    f = ((f & (a[j] >> i) & 1));
                continue;
            }
            if (((a[j] >> i) & 1) || ((b[j] >> i) & 1))
            {
                continue;
            }
            else
            {
                f = 0;
                break;
            }
        }
        if (!f)
            continue;
        ll cc = 1;
        FOR(j, n)
        {
            if (temp[j] != -1)
            {
                if (temp[j] == 1)
                    cc = ((cc & (b[j] >> i) & 1));
                else
                    cc = ((cc & (a[j] >> i) & 1));
                continue;
            }
            if (((a[j] >> i) & 1) && ((b[j] >> i) & 1))
            {
                continue;
            }
            else if (((a[j] >> i) & 1))
                temp[j] = 0;
            else if (((b[j] >> i) & 1))
                temp[j] = 1, bb++;
            else
            {
                cc = 0;
                break;
            }
        }
        aa += (cc * (1ll << i));
    }
    cout << aa << " " << bb << endl;
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