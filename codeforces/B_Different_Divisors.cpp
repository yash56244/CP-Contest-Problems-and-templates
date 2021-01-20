#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define pi 3.1415926535897932384626433832795
#define FOR(i, n) for (ll(i) = 0; (i) < (n); (i)++)
#define FORL(i, a, n) for (ll(i) = (a); (i) <= (n); (i)++)
#define FORR(i, a, n) for (ll(i) = (a); (i) >= (n); (i)--)
#define FORSQ(i, a, n) for (ll(i) = (a); (i) * (i) <= (n); ++(i))
#define FOREACH(a, b) for (auto &(a) : (b))
#define f first
#define s second
#define pb push_back
#define pon pop_back
#define mp make_pair
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SIZE(v) (ll) v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))

typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair<char, char> pcc;
typedef vector<pll> vll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef priority_queue<ll> PQMAX;
typedef priority_queue<ll, vector<ll>,
                       greater<ll>>
    PQMIN;
typedef set<ll> setll;
typedef map<ll, ll> mapll;

ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

void yash56244(bool prime[])
{
    ll d;
    cin >> d;
    ll a, b;
    ll i = d + 1;
    while (1)
    {
        if (prime[i])
        {
            a = i;
            break;
        }
        i++;
    }
    i = i + d;
    while (1)
    {
        if (prime[i])
        {
            b = i;
            break;
        }
        i++;
    }
    cout << a * b << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    ll n = 1000000;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (ll p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    ll t = 1;
    cin >> t;
    while (t--)
    {
        yash56244(prime);
    }
    return 0;
}