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
const ll maxn = 1e5;

ll Mod(ll a, ll b)
{
    return (b + a % b) % b;
}
// vvl factorisation(maxn + 1);
// void sieve()
// {
//     for (int i = 1; i <= maxn; ++i)
//     {
//         for (int j = i; j <= maxn; j += i)
//             factorisation[j].push_back(i);
//     }
// }
void yash56244()
{
    ll n, m;
    cin >> n >> m;
    vl factorisation(n + 1, 1);
    ll cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        ll a = m % i;
        cnt += factorisation[a];
        for (int j = a; j <= n; j += i)
            factorisation[j]++;
    }
    // FORL(i, 2, n)
    // {
    //     int ans = lower_bound(factorisation[m - m % i].begin(), factorisation[m - m % i].end(), i) - factorisation[m - m % i].begin();
    //     if (ans == 0)
    //         cnt += i - 1;
    //     else
    //         cnt += ans;
    // }
    cout << cnt << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    // sieve();

    int t = 1;
    cin >> t;
    while (t--)
    {
        yash56244();
    }
    return 0;
}