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
const ll maxn = 1e5 + 5;

ll Mod(ll a, ll b)
{
    return (b + a % b) % b;
}
ll power(ll a, ll b, ll mod = mod)
{
    a %= mod;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
ll nthPalindrome(int n, int k)
{
    int temp = (k & 1) ? (k / 2) : (k / 2 - 1);
    int palindrome = (int)pow(10, temp);
    palindrome += n - 1;
    vl p;
    p.push_back(palindrome);
    if (k & 1)
        palindrome /= 10;
    while (palindrome)
    {
        p.push_back(palindrome % 10);
        palindrome /= 10;
    }
    ll nn = 0;
    FOR(i, p.size())
    {
        nn += p[i] * power(10, p.size() - i - 1);
    }
    return nn;
}
vl pal;
void pre()
{
    int i = 1;
    pal.push_back(0);
    while (i < maxn)
    {
        pal.push_back(nthPalindrome(i, 1));
        i++;
    }
    FORL(i, 1, maxn - 1)
    {
        pal[i] += pal[i - 1];
    }
}
void yash56244()
{
    ll l, r;
    cin >> l >> r;
    ll ans = power(pal[l] - pal[l - 1], pal[r] - pal[l]);
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    pre();
    int t = 1;
    cin >> t;
    while (t--)
    {
        yash56244();
    }
    return 0;
}