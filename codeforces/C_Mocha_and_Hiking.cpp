#include <bits/stdc++.h>

using namespace std;

#define mod 1e9 + 7
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

void yash56244()
{
    ll n;
    cin >> n;
    map<pair<ll, ll>, ll> ss;
    FOR(i, n)
    {
        ll a;
        cin >> a;
        if (a == 0)
        {
            ss[{i + 1, n + 1}]++;
        }
        else
        {
            ss[{n + 1, i + 1}]++;
        }
    }
    ll ii = -1;
    if (ss.find({n, n + 1}) != ss.end())
    {
        FORL(i, 1, n + 1)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    if (ss.find({n + 1, 1}) != ss.end())
    {
        cout << n + 1 << " ";
        FORL(i, 1, n)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    FOR(i, n)
    {
        if (ss.find({i + 1, n + 1}) != ss.end() && ss.find({n + 1, i + 2}) != ss.end())
        {
            ii = i + 1;
            break;
        }
    }
    if (ii == -1)
    {
        cout << -1 << endl;
    }
    else
    {
        FORL(i, 1, ii)
        {
            cout << i << " ";
        }
        cout << n + 1 << " ";
        FORL(i, ii + 1, n)
        {
            cout << i << " ";
        }
        cout << endl;
    }
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