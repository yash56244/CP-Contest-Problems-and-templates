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
typedef map<ll, ll> mapll;

const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll maxn = 1e6 + 5;

void yash56244()
{
    ll n;
    cin >> n;
    ll arr[n], cnt = 0;
    mapll m;
    FOR(i, n)
    {
        cin >> arr[i];
        if (arr[i] == 0)
            cnt++;
        else
        {
            if (i != 0)
            {
                if (arr[i] == arr[i - 1])
                {
                    m[arr[i]]++;
                }
            }
        }
    }
    ll thresh = 0;
    FOREACH(e, m)
    {
        if (e.second >= 1)
        {
            e.second++;
            thresh += ((e.second * (e.second - 1)) / 2);
            // cout << e.first << e.second << " ";
        }
    }
    // ll bcnt = 0;
    // FORL(i, 0, n - 1)
    // {
    //     FORL(j, i, n - 1)
    //     {
    //         ll orr = arr[i], andd = arr[i], mx = arr[i];
    //         FORL(k, i + 1, j)
    //         {
    //             orr |= arr[k];
    //             andd &= arr[k];
    //             mx = max(mx, arr[k]);
    //         }
    //         orr ^= andd;
    //         if (orr >= mx)
    //         {
    //             // cout << i << " " << j << endl;
    //             bcnt++;
    //         }
    //     }
    // }
    // cout << bcnt << " ";
    cout << cnt + (n * (n - 1) / 2) - thresh << endl;
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