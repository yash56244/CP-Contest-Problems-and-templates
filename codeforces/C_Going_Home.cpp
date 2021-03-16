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
    ll arr2[n];
    FOR(i, n)
    {
        cin >> arr2[i];
    }
    unordered_map<int, pair<int, int>>
        uomp;
    bool found = false;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int sum = arr2[i] + arr2[j];
            if (uomp.find(sum) == uomp.end())
                uomp[sum] = make_pair(i, j);

            else
            {
                pair<int, int> ppp = uomp[sum];
                set<ll> s;
                s.insert(ppp.first + 1);
                s.insert(ppp.second + 1);
                s.insert(i + 1);
                s.insert(j + 1);
                if (s.size() != 4)
                    continue;
                cout << "YES" << endl;
                cout << ppp.second + 1 << " " << ppp.first + 1 << " " << i + 1 << " " << j + 1;
                found = true;
                break;
            }
        }
        if (found)
            break;
    }
    if (!found)
    {
        cout << "NO" << endl;
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