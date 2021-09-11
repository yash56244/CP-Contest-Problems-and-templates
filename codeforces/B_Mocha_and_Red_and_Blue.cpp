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
void rec(string &s, ll i, char c)
{
    if (i < 0 || i == s.length())
    {
        return;
    }
    char cc;
    if (s[i] == '?')
    {
        s[i] = c;
        if (c == 'R')
        {
            cc = 'B';
        }
        else
        {
            cc = 'R';
        }
        rec(s, i + 1, cc);
    }
    else
    {
        if (s[i] == 'R')
        {
            cc = 'B';
        }
        else
        {
            cc = 'R';
        }
        rec(s, i + 1, cc);
    }
}
void yash56244()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll idx = -1;
    FOR(i, n)
    {
        if (s[i] == '?')
        {
            idx = i;
            break;
        }
    }
    if (idx == -1)
    {
        cout << s << endl;
        return;
    }
    string t = s;
    rec(t, idx, 'R');
    ll imp1 = 0, imp2 = 0;
    FORL(i, 1, n - 1)
    {
        if (t[i] == t[i - 1])
        {
            imp1++;
        }
    }
    string tt = s;
    rec(tt, idx, 'B');
    FORL(i, 1, n - 1)
    {
        if (tt[i] == tt[i - 1])
        {
            imp2++;
        }
    }
    if (imp1 > imp2)
    {
        cout << tt << endl;
    }
    else
    {
        cout << t << endl;
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