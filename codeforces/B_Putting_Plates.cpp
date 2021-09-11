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
ll n, m;

void dfs(ll i, ll j, char c, char ans[][21], vector<vector<bool>> &vis)
{
    if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j])
        return;
    char cc;
    if (c == '0')
        cc = '1';
    else
        cc = '0';
    ans[i][j] = c;
    vis[i][j] = true;
    dfs(i - 1, j, cc, ans, vis);
    dfs(i, j - 1, cc, ans, vis);
    dfs(i + 1, j, cc, ans, vis);
    dfs(i, j + 1, cc, ans, vis);
    dfs(i - 1, j - 1, cc, ans, vis);
    dfs(i - 1, j + 1, cc, ans, vis);
    dfs(i + 1, j - 1, cc, ans, vis);
    dfs(i + 1, j + 1, cc, ans, vis);
}

void yash56244()
{
    cin >> n >> m;
    char ans[n][21];
    FOR(i, n)
    {
        FOR(j, m)
        {
            ans[i][j] = '0';
        }
    }
    FOR(i, m)
    {
        if (i % 2 == 0)
        {
            ans[0][i] = '1';
        }
    }
    FOR(i, n)
    {
        if (i % 2 == 0)
        {
            ans[i][0] = '1';
        }
    }
    if (m % 2 == 1 && n % 2 == 0)
    {
        for (int i = m - 1; i >= 2; i -= 2)
        {
            ans[n - 1][i] = '1';
        }
        for (int i = n - 1; i >= 2; i -= 2)
        {
            ans[i][m - 1] = '1';
        }
    }
    else if (m % 2 == 1 && n % 2 == 1)
    {

        for (int i = m - 1; i >= 1; i -= 2)
        {
            ans[n - 1][i] = '1';
        }
        for (int i = n - 1; i >= 1; i -= 2)
        {
            ans[i][m - 1] = '1';
        }
    }
    else if (m % 2 == 0 && n % 2 == 1)
    {

        for (int i = m - 1; i >= 2; i -= 2)
        {
            ans[n - 1][i] = '1';
        }
        for (int i = n - 1; i >= 2; i -= 2)
        {
            ans[i][m - 1] = '1';
        }
    }
    else
    {

        for (int i = m - 1; i >= 2; i -= 2)
        {
            ans[n - 1][i] = '1';
        }
        for (int i = n - 1; i >= 2; i -= 2)
        {
            ans[i][m - 1] = '1';
        }
    }
    FOR(i, n)
    {
        FOR(j, m)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
    cout << endl;
    n = 0, m = 0;
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