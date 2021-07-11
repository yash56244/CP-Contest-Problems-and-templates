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

void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &vis, int n, int m, bool flag)
{
    if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j])
    {
        return;
    }
    if (!flag && grid[i][j] == '.')
    {
        return;
    }
    vis[i][j] = true;
    dfs(i + 1, j, grid, vis, n, m, true);
    dfs(i, j + 1, grid, vis, n, m, false);
    dfs(i, j - 1, grid, vis, n, m, false);
    dfs(i - 1, j, grid, vis, n, m, false);
}

void yash56244()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    FOR(i, n)
    {
        FOR(j, m)
        {
            cin >> grid[i][j];
        }
    }
    ll arr[m];
    FOR(i, m)
    {
        cin >> arr[m];
    }
    vl v;
    for (int i = 0; i < m; i++)
    {
        bool first = false;
        for (int j = 0; j < n; j++)
        {
            if (grid[j][i] == '#' && !first)
            {
                first = true;
                v.push_back(j);
            }
        }
    }
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int ii = 0, mcnt = INT_MAX;
    for (int k = 0; k < v.size(); k++)
    {
        dfs(v[k], ii, grid, vis, n, m, false);
        ii++;
        int cnt = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == '#')
                {
                    dfs(i, j, grid, vis, n, m, false);
                    cnt++;
                }
            }
        }
        vis.assign(n, vector<bool>(m, false));
        mcnt = min(mcnt, cnt);
    }
    cout << mcnt << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        yash56244();
    }
    return 0;
}