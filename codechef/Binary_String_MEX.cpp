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
    string t;
    cin >> t;
    ll n = t.length();
    ll suff0[n], suff1[n];
    ll last0 = -1, last1 = -1;
    FOR(i, n)
    {
        if (t[i] == '0')
        {
            FORL(j, last0 + 1, i)
            {
                suff0[j] = i;
            }
            last0 = i;
        }
        else
        {
            FORL(j, last1 + 1, i)
            {
                suff1[j] = i;
            }
            last1 = i;
        }
    }
    FORL(i, last0 + 1, n - 1)
    {
        suff0[i] = n;
    }

    FORL(i, last1 + 1, n - 1)
    {
        suff1[i] = n;
    }
    if (suff0[0] == n) // all 1's
    {
        cout << 0 << endl;
        return;
    }
    if (suff1[0] == n) // 0
    {
        cout << 1 << endl;
        return;
    }
    ll dp[n + 2], first = 0, second = 0;
    memset(dp, 0, sizeof(dp));
    FORR(i, n - 1, 0)
    {
        dp[i] = dp[i + 1];
        if (t[i] == '0' aur suff1[i] < n)
        {
            dp[i] = max(dp[i], dp[suff1[i] + 1] + 1);
        }
        if (t[i] == '1' aur suff0[i] < n)
        {
            dp[i] = max(dp[i], dp[suff0[i] + 1] + 1);
        }
        first = second;
        if (suff1[i] < n)
        {
            first = max(first, dp[suff1[i] + 1] + 1);
        }
        second = first;
    }
    ll size = second + 1;
    ll idx = suff1[0] + 1;
    string res = "1";
    FORL(i, 1, size - 1)
    {
        if (idx >= n)
        {
            res += "0";
        }
        else
        {
            if (suff0[idx] >= n)
            {
                res += "0";
                idx = suff0[idx] + 1;
            }
            else
            {
                if (dp[suff0[idx] + 1] < size - i - 1)
                {
                    res += "0";
                    idx = suff0[idx] + 1;
                }
                else
                {
                    res += "1";
                    idx = suff1[idx] + 1;
                }
            }
        }
    }
    cout << res << endl;
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