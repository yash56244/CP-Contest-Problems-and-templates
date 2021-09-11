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
class DSU
{
private:
    vector<int> parent, size;

public:
    DSU(int n)
    {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n, 1);
    }
    int find(int a)
    {
        while (parent[a] != a)
        {
            parent[a] = parent[parent[a]];
            a = parent[a];
        }
        return a;
    }
    bool same(int a, int b) { return find(a) == find(b); }
    void unite(int a, int b)
    {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA == rootB)
        {
            return;
        }
        if (size[rootA] < size[rootB])
        {
            parent[rootA] = rootB;
            size[rootB] += size[rootA];
        }
        else
        {
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
        }
    }
    int _size(int a)
    {
        int rootA = find(a);
        return size[rootA];
    }
};

void yash56244()
{
    ll n, m1, m2;
    cin >> n >> m1 >> m2;
    DSU d1(n), d2(n);
    FOR(i, m1)
    {
        ll a, b;
        cin >> a >> b;
        d1.unite(a - 1, b - 1);
    }
    FOR(i, m2)
    {
        ll a, b;
        cin >> a >> b;
        d2.unite(a - 1, b - 1);
    }
    vll res;
    FORL(i, 1, n)
    {
        FORL(j, 1, n)
        {
            if (!d1.same(i - 1, j - 1) && !d2.same(i - 1, j - 1))
            {
                d1.unite(i - 1, j - 1);
                d2.unite(i - 1, j - 1);
                res.push_back({i, j});
            }
        }
    }
    cout << res.size() << endl;
    FOREACH(e, res)
    {
        cout << e.first << " " << e.second << endl;
    }
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