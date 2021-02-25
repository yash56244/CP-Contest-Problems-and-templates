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
#define log(args...)                             \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }

#define logarr(arr, a, b)            \
    for (int z = (a); z <= (b); z++) \
        cout << (arr[z]) << " ";     \
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

bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.first > b.first;
}

void yash56244()
{
    ll n;
    cin >> n;
    ll arr[n];
    vll temp(n);
    FOR(i, n)
    {
        cin >> arr[i];
        temp.push_back({arr[i], i});
    }
    sort(temp.begin(), temp.end(), cmp);
    ll i = 0, last_index = n - 1;
    vl ans;
    while (1)
    {
        if (last_index == 0)
        {
            ans.push_back(arr[0]);
            break;
        }
        if (temp[i].second == 0)
        {
            for (ll j = temp[i].second; j <= last_index; j++)
            {
                ans.push_back(arr[j]);
            }
            break;
        }
        for (ll j = temp[i].second; j <= last_index; j++)
        {
            ans.push_back(arr[j]);
        }
        if (temp[i].second > last_index)
        {
            i++;
            continue;
        }
        last_index = temp[i].second - 1;
        i++;
    }
    FOREACH(e, ans)
    {
        cout << e << " ";
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