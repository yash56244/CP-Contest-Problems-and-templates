#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define andd &&
#define orr ||
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define FOR(i, n) for (ll(i) = 0; (i) < (n); (i)++)
#define FORL(i, a, n) for (ll(i) = (a); (i) <= (n); (i)++)
#define FORR(i, a, n) for (ll(i) = (a); (i) >= (n); (i)--)
#define FORSQ(i, a, n) for (ll(i) = (a); (i) * (i) <= (n); ++(i))
#define FOREACH(a, b) for (auto &(a) : (b))
#define all(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))

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

class RMQ //Range minimum query in O(1) using sparse Table. O(nlogn) for preprocessing.
{
public:
    RMQ(vl v)
    {
        log_table.assign(v.size() + 1, 0);
        for (ll i = 2; i < log_table.size(); i++)
            log_table[i] = log_table[i / 2] + 1;

        sparse_table.assign(log_table.back() + 1, vl(v.size()));
        sparse_table[0] = v;
        for (ll row = 1; row < sparse_table.size(); row++)
        {
            for (ll i = 0; i + (1 << row) <= v.size(); i++)
            {
                sparse_table[row][i] = min(sparse_table[row - 1][i], sparse_table[row - 1][i + (1 << (row - 1))]);
            }
        }
    }

    ll minimum(ll l, ll r)
    {
        ll log = log_table[r - l];
        return min(sparse_table[log][l], sparse_table[log][r - (1 << log)]);
    }

private:
    vl log_table;
    vvl sparse_table;
};

void yash56244() {}

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