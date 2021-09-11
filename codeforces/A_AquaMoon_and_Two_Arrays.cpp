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
    ll sum = 0;
    FOR(i, n)
    {
        sum += (a[i] - b[i]);
        b[i] = a[i] - b[i];
    }
    if (sum != 0)
    {
        cout << -1 << endl;
    }
    else
    {
        vll v;
        for (int i = 0; i < n; i++)
        {
            int j = 0;
            while (b[i] < 0 && j < n)
            {
                while (b[j] > 0 && b[i] < 0)
                {
                    b[j]--;
                    b[i]++;
                    v.push_back({j + 1, i + 1});
                }
                j++;
            }
        }
        cout << v.size() << endl;
        FOREACH(e, v)
        {
            cout << e.first << " " << e.second << endl;
        }
    }
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