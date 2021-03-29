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

void yash56244()
{
    ll n;
    cin >> n;
    ll arr[n];
    ll cnt[101];
    bool cnr[101];
    memset(cnt, 0, sizeof(cnt));
    memset(cnr, false, sizeof(cnr));
    FOR(i, n)
    {
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    sort(arr, arr + n);
    FOR(i, n)
    {
        if (cnt[arr[i]] >= 1 and cnr[arr[i]] == false)
        {
            cout << arr[i] << " ";
            cnt[arr[i]]--;
            cnr[arr[i]] = true;
        }
    }
    FOR(i, n)
    {
        while (cnt[arr[i]] != 0)
        {
            cout << arr[i] << " ";
            cnt[arr[i]]--;
        }
    }
    cout << endl;
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