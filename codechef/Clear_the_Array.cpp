#include <bits/stdc++.h>

using namespace std;

#define pi 3.1415926535897932384626433832795
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto &(a) : (b))
#define f first
#define s second
#define pb push_back
#define pon pop_back
#define mp make_pair
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef priority_queue<ll> PQMAX;
typedef priority_queue<ll, vector<ll>,
                       greater<ll>>
    PQMIN;

void solve()
{
    ll n, k, x;
    cin >> n >> k >> x;
    ll arr[n];
    ll sum = 0;
    FOR(i, n)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr + n);
    ll pp = 0;
    if (n % 2 == 1)
    {
        pp = 1;
    }
    for (ll i = n - 1; i > pp && k > 0; i -= 2)
    {
        if (x >= arr[i] + arr[i - 1])
        {
            break;
        }
        else
        {
            sum = sum - arr[i] - arr[i - 1] + x;
            k--;
        }
    }

    cout << sum << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        int abhi = 2;
        break;
    }

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}