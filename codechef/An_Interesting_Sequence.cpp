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
const ll maxn = 4e6 + 5;

ll Mod(ll a, ll b)
{
    return (b + a % b) % b;
}

vl arr(maxn);

void primeFactorisation()
{
    arr[1] = 1;
    FORL(i, 2, maxn - 1) { arr[i] = i; }
    for (int i = 4; i < maxn; i += 2)
    {
        arr[i] = 2;
    }
    FORSQ(i, 3, maxn - 1)
    {
        if (arr[i] == i)
        {
            for (int j = i * i; j < maxn; j += i)
            {
                if (arr[j] == j)
                {
                    arr[j] = i;
                }
            }
        }
    }
}
vll getFactorisation(ll x)
{
    map<int, int> s;
    while (x != 1)
    {
        s[arr[x]]++;
        x = x / arr[x];
    }
    vll arr;
    FOREACH(e, s)
    {
        arr.push_back({e.second, e.first});
    }
    return arr;
}

vl phi(maxn + 1);

void computeTotient()
{
    for (int i = 1; i <= maxn; i++)
        phi[i] = i;
    for (int p = 2; p <= maxn; p++)
    {
        if (phi[p] == p)
        {
            phi[p] = p - 1;
            for (int i = 2 * p; i <= maxn; i += p)
            {
                phi[i] -= phi[i] / p;
            }
        }
    }
}

void generateDivisors(int curIndex, int curDivisor, vll &arr, vl &v)
{
    if (curIndex == arr.size())
    {
        v.push_back(curDivisor);
        return;
    }
    for (int i = 0; i <= arr[curIndex].first; ++i)
    {
        generateDivisors(curIndex + 1, curDivisor, arr, v);
        curDivisor *= arr[curIndex].second;
    }
}

void yash56244()
{
    ll k;
    cin >> k;
    ll n = 4 * k + 1;
    ll ans = n - 1;
    vl v;
    vll pf = getFactorisation(n);
    generateDivisors(0, 1, pf, v);
    FOREACH(e, v)
    {
        if (e != n)
        {
            ans += e * ((phi[n / e] + 1) / 2);
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);

    computeTotient();
    primeFactorisation();

    int t = 1;
    cin >> t;
    while (t--)
    {
        yash56244();
    }
    return 0;
}