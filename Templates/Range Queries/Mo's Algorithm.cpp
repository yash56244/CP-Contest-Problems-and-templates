#include <bits/stdc++.h>

using namespace std;

#define pi 3.1415926535897932384626433832795
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
#define REVERSE(v) reverse(ALL(v))
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

const int block = 300;
ll cnt[2000001];

struct Query
{
    ll l, r, idx;
};

bool cmp(Query a, Query b)
{
    if (a.l / block != b.l / block)
    {
        return a.l / block < b.l / block;
    }
    return a.r < b.r;
}

void yash56244()
{
    ll n, q;
    cin >> n >> q;
    ll arr[n + 1];
    FORL(i, 1, n)
    {
        cin >> arr[i];
    }
    Query queries[q + 1];
    FORL(i, 1, q)
    {
        cin >> queries[i].l >> queries[i].r;
        queries[i].idx = i;
    }
    sort(queries + 1, queries + q + 1, cmp);
    ll l = 0, r = 0;
    ll answers[q + 1];
    ll ans = 0;
    FORL(i, 1, q)
    {
        ll qL = queries[i].l, qR = queries[i].r;
        while (l > qL - 1)
        {
            l--;
            //add.
        }
        while (r < qR)
        {
            r++;
            //add.
        }
        while (l < qL - 1)
        {
            //remove.
            l++;
        }
        while (r > qR)
        {
            //remove.
            r--;
        }
        answers[queries[i].idx] = ans;
    }
    FORL(i, 1, q)
    {
        cout << answers[i] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    // cin >> t;
    while (t--)
    {
        yash56244();
    }
    return 0;
}