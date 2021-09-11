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
    ll n, m, c;
    cin >> n >> m >> c;
    ll arr[n][m];
    ll mn = 10000000000, ii = 0, jj = 0;
    FOR(i, n)
    {
        FOR(j, m)
        {
            cin >> arr[i][j];
        }
    }
    FOR(i, n)
    {
        FOR(j, m)
        {
            if (mn > arr[i][j])
            {
                mn = arr[i][j];
                ii = i;
                jj = j;
            }
        }
    }
    ll dx[] = {-1, 0, 1, 0};
    ll dy[] = {0, 1, 0 - 1};
    queue<pll> q;
    vector<vector<bool>> vis(n, vb(m, false));
    vvl dist(n, vl(m, inf));
    vector<vector<bool>> mark(n, vb(m, false));
    FOR(i, n)
    {
        FOR(j, m)
        {
            if (arr[ii][jj] == arr[i][j])
            {
                vis[i][j] = true;
                dist[i][j] = arr[i][j];
                q.push({i, j});
                mark[i][j] = true;
            }
        }
    }
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            ll xx = t.first + dx[i];
            ll yy = t.second + dy[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m)
            {
                if (!vis[xx][yy])
                {
                    vis[xx][yy] = true;
                    q.push({xx, yy});
                    ll dd = arr[ii][jj] + arr[xx][yy];
                    dd += c * (abs(xx - ii) + abs(yy - jj));
                    dist[xx][yy] = min(dd, dist[xx][yy]);
                }
            }
        }
    }
    ll ans = inf;
    FOR(i, n)
    {
        FOR(j, m)
        {
            if (!mark[i][j])
                ans = min(ans, dist[i][j]);
        }
    }
    cout << ans;
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