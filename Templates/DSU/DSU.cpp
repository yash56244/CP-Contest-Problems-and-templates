#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define FOR(i, n) for (ll(i) = 0; (i) < (n); (i)++)
#define FORL(i, a, n) for (ll(i) = (a); (i) <= (n); (i)++)
#define FORR(i, a, n) for (ll(i) = (a); (i) >= (n); (i)--)
#define FORSQ(i, a, n) for (ll(i) = (a); (i) * (i) <= (n); ++(i))
#define FOREACH(a, b) for (auto &(a) : (b))
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SIZE(v) (ll) v.size()
#define SORT(v) sort(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair<char, char> pcc;
typedef vector<bool> vb;
typedef vector<pll> vll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef priority_queue<ll> PQMAX;
typedef priority_queue<ll, vector<ll>,
                       greater<ll>>
    PQMIN;
typedef set<ll> setll;
typedef map<ll, ll> mapll;

const ll inf = 1e15;
const ll mod = 1e9 + 7;

struct DSU
{
    vl parent;

    void init(ll n) { parent = vl(n + 1, -1); }

    ll get(ll x) { return (parent[x] < 0 ? x : parent[x] = get(parent[x])); } // Path Compression.

    bool sameSet(ll x, ll y) { return get(x) == get(y); }

    ll size(ll x) { return -parent[get(x)]; }

    bool unionSets(ll x, ll y)
    {
        x = get(x), y = get(y);

        if (x == y)
            return 0;

        if (parent[x] > parent[y]) // Union by size.
            swap(x, y);

        parent[x] += parent[y];

        parent[y] = x;

        return 1;
    }
};

void yash56244()
{
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;
    while (t--)
    {
        yash56244();
    }
    return 0;
}